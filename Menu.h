#pragma once   //����pragma once�����ļ�ֻ�ᱻ����һ��
#include<string>
using namespace std;

//��ʾ������
void ProgramMainWindow();
//��������
void ProgramManipWindow();
//ѡ���ȡ���ݵķ���
void GetDataMethod(int&);

//����������ĸ���
void InputRandomNum(int& n);
//���뱣����������ļ���
void InputRandomFileName(string& str);
//�������������ļ���
void InputSortResultFileName(string& str);
//ѡ�����򷽷�
void SelectSortMethod(int&);
//��������ķ�ʽ(�������)
void SetSortMode(char& SortMode);
