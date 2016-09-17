#include "histogram.h"

using namespace std;

///////////////////////////////////////////////////////////////////
// ��������������� �������
void AddBar(Histogram &historgam, const char *strName);
bool AppendBar(Histogram &historgam, const char *strName);

///////////////////////////////////////////////////////////////////
// ���������� ������� �� ����� histogram.h


//-----------------------------------------------------------------
// ������� AddBlock ����������� �������� ������� strName ���������� historgam �� 1.
// ���� ������� � ����� ������ �� ����������, �� ���������.
void AddBlock(Histogram &historgam, const char *strName){
	if(!AppendBar(historgam, strName)){
		AddBar(historgam, strName);
	}
}

//-----------------------------------------------------------------
// ������� PrintHistogram ������� ���������� �� �����.
void PrintHistogram(const Histogram &historgam){
    //��� ���������� ������������ �������� �������� �� ������ ���� ���� ��������� ��������� ������:
    int maxStrLen=strlen(historgam.BarNames[0]);
    for(int i=1; i<historgam.nBarsSize; i++)
    {
        if(strlen(historgam.BarNames[i])>maxStrLen)
        {
            maxStrLen=strlen(historgam.BarNames[i]);
        }
    }
    //� ���������� ������ ����� ��������� ����� ������������� �������� �������
	for(int i=0; i<historgam.nBarsSize; i++){
        std::cout.width(maxStrLen);//�������� ����������� ����� ��������� ��������(��� �� ������������ ����� �������� �������)
        //����� � ������� setfill � std::left �������� "����������" ��� ��������� ���� � ������������ �� ������ ����
		cout <<setfill(' ')<<std::left<<historgam.BarNames[i] << '|';
		//cout.setf
		cout << setfill(historgam.chBlock) << setw(10*historgam.Bars[i]/historgam.nMaxBar) << "" << /*ends <<*/ endl;
	}
}

///////////////////////////////////////////////////////////////////
// ���������� ��������������� �������

//-----------------------------------------------------------------
// ������� AppendBar ����������� �������� ������� strName ���������� historgam �� 1.
bool AppendBar(Histogram &historgam, const char *strName){
	for(int i=0; i<historgam.nBarsSize; i++){
		if(strcmp(historgam.BarNames[i], strName)==0){
			historgam.nMaxBar = max(historgam.nMaxBar, ++historgam.Bars[i]);
			return true;
		}
	}
	return false;
}

// ������� AddBar ������� � ���������� historgam ����� ������� � ������ strName.
//-----------------------------------------------------------------
void AddBar(Histogram &historgam, const char *strName){
	char **newNames = new char *[historgam.nBarsSize+1];
	int   *newBars  = new int[historgam.nBarsSize+1];
	if(historgam.nBarsSize > 0){
		for(int i=0; i<historgam.nBarsSize; i++){
			newNames[i] = historgam.BarNames[i];
			newBars[i] = historgam.Bars[i];
		}
		delete[] historgam.BarNames;
		delete[] historgam.Bars;
	}

	newNames[historgam.nBarsSize] = new char[strlen(strName)+1];
	strcpy(newNames[historgam.nBarsSize], strName);
	newBars[historgam.nBarsSize] = 1;

	historgam.nBarsSize++;
	historgam.BarNames = newNames;
	historgam.Bars = newBars;
}

