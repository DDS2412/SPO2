// SPO2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "Algo.h"
#include "CreationTable.h"

#include "time.h"
#include "algorithm"
#include "string"
#include <math.h>
#include "iostream"
#include "fstream"
#include "windows.h"

using namespace std;

int* GetRandomValue();
void GetReuslt(string title, void(*sort)(int*, int));
void SortMappingFiles(void(*sort)(int*, int));
void SortMergeWrapper(int* arr, int size);
void SortBasePoints(void(*sort)(int*, int));

const int ARRSIZE = 50000;

int times[] = { 0, 0, 0 };

int main()
{
	GetReuslt("Merge sort", SortMergeWrapper);

	GetReuslt("Selection sort", SelectionSort);

	cout << endl;
}

void GetReuslt(string title, void(*sort)(int*, int)) {
	int* values = GetRandomValue();

	SYSTEMTIME st, ft;
	GetSystemTime(&st);
	sort(values, ARRSIZE);
	GetSystemTime(&ft);
	times[0] = abs(ft.wMilliseconds - st.wMilliseconds);

	GetSystemTime(&st);
	SortMappingFiles(sort);
	GetSystemTime(&ft);
	times[1] = abs(ft.wMilliseconds - st.wMilliseconds);
	
	GetSystemTime(&st);
	SortBasePoints(sort);
	GetSystemTime(&ft);
	times[2] = abs(ft.wMilliseconds - st.wMilliseconds);

	DrawTable(title, times);	
}

int* GetRandomValue() {
	ofstream f;
	f.open("input.txt");

	int* arr = new int[ARRSIZE];

	for (int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = 1 + rand() % 50;
		f << arr[i] << i << endl;
	}

	f.close();

	return arr;
}

void SortMergeWrapper(int* arr, int size) {
	MergeSort(arr, 0, size - 1);
}

void SortMappingFiles(void(*sort)(int*, int))
{
	string fname = "input.txt";
	wstring wstr(fname.begin(), fname.end());

	LPCWSTR str = (LPCWSTR)wstr.c_str();

	HANDLE hFile = CreateFile(str, GENERIC_READ | GENERIC_WRITE, 
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

	HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);

	DWORD dwFileSize = GetFileSize(hFile, NULL);

	int *memory = (int*)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, dwFileSize);

	sort(memory, ARRSIZE);

	UnmapViewOfFile(memory);

	CloseHandle(hMap);

	CloseHandle(hFile);
}

void SortBasePoints(void(*sort)(int*, int))
{
	string fname = "input.txt";
	wstring wstr(fname.begin(), fname.end());
	LPCWSTR str = (LPCWSTR)wstr.c_str();
	HANDLE hFile = CreateFile(str, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
	DWORD dwFileSize = GetFileSize(hFile, NULL);
	int *memory = (int*)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, dwFileSize);
	int dataSize = 2;
	int* data = new int[dwFileSize/ dataSize];

	for (int i = 0; i <= ARRSIZE; ++i)
	{
		data[i] = *(memory + i * dataSize);
	}
	sort(data, ARRSIZE);

	for (int i = 0; i <= ARRSIZE; ++i)
	{
		memory[i] = *(data + i * dataSize);
	}

	UnmapViewOfFile(memory);
	CloseHandle(hMap);
	CloseHandle(hFile);
}