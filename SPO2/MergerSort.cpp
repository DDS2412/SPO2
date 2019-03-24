#include "Algo.h"
#include "pch.h"

#include <string.h>

void InsertionSort(int* pArr, int bInd, int eInd);
void Merge(int* pArr, int bInd, int mInd, int eInd);

void MergeSort(int* pArr, int bInd, int eInd)
{
	if (20 >= eInd - bInd)
	{
		InsertionSort(pArr, bInd, eInd);
	}
	else
	{
		int mInd = (bInd + eInd) / 2;
		MergeSort(pArr, bInd, mInd);
		MergeSort(pArr, mInd + 1, eInd);
		Merge(pArr, bInd, mInd, eInd);
	}
}

void InsertionSort(int* pArr, int bInd, int eInd)
{
	int i, j, tmp;
	for (i = bInd; i <= eInd; ++i)
	{
		tmp = pArr[i];
		for (j = i - 1; j >= bInd && tmp < pArr[j]; --j)
		{
			pArr[j + 1] = pArr[j];
		}
		pArr[j + 1] = tmp;
	}
}

void Merge(int* pArr, int bInd, int mInd, int eInd)
{
	int* p = new int[mInd - bInd + 1];
	int* p1 = new int[eInd - mInd];
	memcpy(p, pArr + bInd, sizeof(int)*(mInd - bInd + 1));
	memcpy(p1, pArr + mInd + 1, sizeof(int)*(eInd - mInd));
	int n, m, k;
	for (n = 0, m = 0, k = 0; n < (mInd - bInd + 1) && m < (eInd - mInd); ++k)
	{
		pArr[bInd + k] = (p[n] < p1[m] ? p[n++] : p1[m++]);
	}
	memcpy(pArr + bInd + k, p1 + m, sizeof(int)*(eInd - mInd - m));
	memcpy(pArr + bInd + k, p + n, sizeof(int)*(mInd - bInd + 1 - n));
	delete[] p; p = 0;
	delete[] p1; p1 = 0;
}