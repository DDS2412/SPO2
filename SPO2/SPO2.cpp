// SPO2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "Algo.h"
#include "CreationTable.h"

#include "stdafx.h"

#include "time.h"
#include "algorithm"
#include "string"
#include "iostream"
#include "fstream"
#include "windows.h"

using namespace std;

int* GetRandomValue();
void GetReuslt(string title, void(*sort)(int*, int));

void SortMergeWrapper(int* arr, int size);

const int ARRSIZE = 500;

int times[] = { 0, 0, 0 };

int main()
{
	GetReuslt("Merge sort", SortMergeWrapper);

	cout << endl;
}

void GetReuslt(string title, void(*sort)(int*, int)) {
	int* values = GetRandomValue();
	SYSTEMTIME st, ft;
	GetSystemTime(&st);
	sort(values, ARRSIZE);
	GetSystemTime(&ft);
	times[0] = ft.wMilliseconds - st.wMilliseconds;

	DrawTable(title, times);

	//ShowArr(values, ARRSIZE);
}

int* GetRandomValue() {
	int arr[ARRSIZE];

	for (int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = 1 + rand() % 50;
	}

	return arr;
}

void SortMergeWrapper(int* arr, int size) {
	MergeSort(arr, 0, size - 1);
}