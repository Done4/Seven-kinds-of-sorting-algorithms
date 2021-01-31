#pragma once   //包含pragma once语句的文件只会被编译一次
#include<string>
using namespace std;

//显示主窗口
void ProgramMainWindow();
//操作窗口
void ProgramManipWindow();
//选择获取数据的方法
void GetDataMethod(int&);

//输入随机数的个数
void InputRandomNum(int& n);
//输入保存随机数的文件名
void InputRandomFileName(string& str);
//输入排序结果的文件名
void InputSortResultFileName(string& str);
//选择排序方法
void SelectSortMethod(int&);
//设置排序的方式(升序或降序)
void SetSortMode(char& SortMode);
