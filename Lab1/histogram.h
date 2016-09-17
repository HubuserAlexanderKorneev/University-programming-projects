#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
//��������� ��� �������� �����������
typedef struct{
	char **BarNames;
	int *Bars;
	int nBarsSize;
	char chBlock;
	int nMaxBar;
} Histogram;


//������� ��� ������ � ������������
void inline InitHistogram(Histogram &historgam);
void inline DestroyHistogram(Histogram &historgam);
void PrintHistogram(const Histogram &historgam);
void AddBlock(Histogram &historgam, const char *strName);

#include "histogram.inl"
