#include "pch.h";
#include "CreationTable.h"

void ShowGreatHeader(string title);
void ShowHeader();
void ShowSubheader(string titles[], int length);
void ShowFooter();
void ShowSplitteLine();
void ShowLine(int firstTime, int secondTime, int thirdTime);

const char TABCHAR = char('\t');
const char UNDERLINE = char(205);
const char VERTICALBORDER = char(186);

void DrawTable(string title, int* values) {
	string titles[] = { "Sorting with Heaps" , "Sorting with Mapping", "Sorting with Base Points" };

	ShowHeader();
	ShowGreatHeader(title);
	ShowSplitteLine();		
	ShowSubheader(titles, 3);
	ShowSplitteLine();
	ShowLine(values[0], values[1], values[2]);
	ShowFooter();
}

void ShowArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << setw(4) << arr[i];
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}

	}
	cout << endl;
}

void ShowHeader() {
	cout << char(201);
	for (int i = 0; i < 87; i++) {
		cout << UNDERLINE;
	}
	cout << char(187) << endl;		
}

void ShowFooter() {
	cout << char(200);
	for (int i = 0; i < 87; i++) {
		cout << UNDERLINE;
	}
	cout << char(188) << endl;
}

void ShowSplitteLine() {
	cout << char(204);

	for (int i = 0; i < 87; i++) {
		cout << UNDERLINE;
	}

	cout << char(185) << endl;
}

void ShowLine(int firstTime, int secondTime, int thirdTime) {
	cout << VERTICALBORDER
		<< TABCHAR << TABCHAR
		<< firstTime << " ms"
		<< TABCHAR << TABCHAR << TABCHAR
		<< secondTime << " ms"
		<< TABCHAR << TABCHAR << TABCHAR
		<< thirdTime << " ms"
		<< TABCHAR << TABCHAR << TABCHAR
		<< VERTICALBORDER << endl;
}

void ShowSubheader(string titles[], int length) {
	cout << VERTICALBORDER << TABCHAR;
	for (int i = 0; i < length; i++) {
		cout << titles[i] << TABCHAR;
	}

	cout << VERTICALBORDER << endl;
}

void ShowGreatHeader(string title) {
	cout << VERTICALBORDER
		<< TABCHAR << TABCHAR << TABCHAR << TABCHAR << TABCHAR
		<< title
		<< TABCHAR << TABCHAR << TABCHAR << TABCHAR << TABCHAR
		<< VERTICALBORDER << endl;
}