#include "stdafx.h"
#include<iostream>
#include"ProRandomIntData.h"
#include <random>
#include <time.h>
using namespace std;

void ProRandomIntData(int* a, int n)
{	
	/////////////////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||-----------------------��������"<<n<<"���������" << endl;
	//������������
	default_random_engine s((unsigned int)time(0)); //����	
	uniform_int_distribution<int> u;
	for (int i = 0; i < n; i++)a[i] = u(s);	
	cout << "\t||------------------------�������������-------------------------||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
}


