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
	cout << "\t||-----------------------正在生成"<<n<<"个随机数！" << endl;
	//产生多个随机数
	default_random_engine s((unsigned int)time(0)); //种子	
	uniform_int_distribution<int> u;
	for (int i = 0; i < n; i++)a[i] = u(s);	
	cout << "\t||------------------------生成随机数结束-------------------------||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
}


