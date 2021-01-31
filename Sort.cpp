#include "stdafx.h"
#include "Sort.h"

/////////////////////////////////////////////////////////////////////////////////////////
//���캯��
template <class T>

CSort<T>::CSort(T *a, int m, int sm, char op)
{
	IntData = a;
	IntDataNum = m;
	SortMethod = sm;
	ro = op;	
}

//��������
template <class T>
CSort<T>::~CSort()
{
}

template<class T>
T * CSort<T>::GetData()
{
	return IntData;
}

////////////////////////////////////////////////////////////////
//��������������
template<class T>
void CSort<T>::Sort()
{
	switch (SortMethod)
	{
	//ð������
	case 1: 
		// �������
		BubbleSort(IntData, IntDataNum);
		break;

	//ѡ������
	case 2: 
		// �������
		SelectSort(IntData, IntDataNum);
		break;

	//��������
	case 3: 
		// �������
		InsertSort(IntData, IntDataNum);
		break;

	//������
	case 4: 
		// �������
		HeapSort(IntData, IntDataNum);
		break;

	//Shell����
	case 5: 
		// �������
		ShellSort(IntData, IntDataNum);
		break;

	//�鲢����
	case 6: 
		// �������
		MergeSort(IntData, IntDataNum);
		break;
	//��������
	case 7: 
		// �������
		QuickSort(IntData, IntDataNum);
		break;	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void CSort<T>::BubbleSort(T* d, const int n)
{
	///////////////////////////////////////////////
	//�����油��ð���������
	if (d == NULL || n < 2) {
		cout << "��������" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (comp(d[j + 1],d[j])) {
				T temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}

}

////////////////////////////////////////////////////
//ֱ��ѡ������
template<class T>
void CSort<T>::SelectSort(T* d, const int n)
{
	//////////////////////////////////////////////////////////////
	//�����油��ֱ��ѡ�����
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (comp(d[j],d[index])) index = j;
		}
		//����
		T temp = d[i];
		d[i] = d[index];
		d[index] = temp;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////
//ֱ�Ӳ�������
template<class T>
void CSort<T>::InsertSort(T* d, const int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;    //�����������һ�����ݵ�����
		T a = d[i];       //�������е�һ������
		while (k >= 0 && comp(a, d[k])) //������һ�����λ
		{
			d[k + 1] = d[k];
			k--;
		}
		d[k + 1] = a; //���������е�һ��������������������
	}

}


///////////////////////////////////////////////////////////////////////////////////////////
//������
template<class T>
void CSort<T>::HeapAdjust(T* d, int left, int right)
{
	T a = d[left];	//�����	
	for (int j = 2 * left + 1; j <= right; j = 2 * j + 1) //2 * left + 1��Ҷ
	{
		if (j < right && comp(d[j], d[j + 1])) j++;            //j + 1��Ҷ
		if (comp(d[j], a)) break;  //�����������ֹѭ��
		d[left] = d[j];            //Ҷ������ڸ����
		left = j;		            //�ı������ΪҶ����
	}
	d[left] = a; //���������Ҷ���

	
}


template<class T>
void CSort<T>::HeapSort(T* d, const int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)HeapAdjust(d, i, n - 1); //����ʼ��
	for (int i = n - 1; i > 0; i--)
	{
		swap(d[0], d[i]);          //�����Ѷ����βԪ��
		HeapAdjust(d, 0, i - 1);   //ʣ��Ԫ�����½���
	}

	
}


/////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void CSort<T>::ShellSort(T* d, const int n)
{
	int h = 1;
	while (h < n / 3)h = h * 3 + 1; //��̬������������
	while (h > 0)                   //����С����h��ֱ�Ӳ�������
	{
		for (int i = h; i < n; i++) //�ڵ�ǰ����h�¶Ը���������ֱ�Ӳ�������
		{
			int j = i - h;      //��ǰ�����е������������һ��Ԫ�ص�����
			T a = d[i];         //�������еĵ�һ��Ԫ��			
			while (j >= 0 && comp(a, d[j]))
			{
				d[j + h] = d[j];
				j -= h;
			}
			d[j + h] = a;       //��d[i]�嵽j + h��λ��
		}
		h = h / 3;
	}

	
}


/////////////////////////////////////////////////////////////////////////////////////////
//�鲢����-�ǵݹ鷽ʽ
template<class T>
void CSort<T>::MergeSort(T* d, const int n)
{
	int size = 1, left, mid, right;//sizeΪ�����г���	
	T* w = new T[n];
	while (size < n)
	{
		left = 0;   //����������
		while (left + size < n)
		{
			mid = left + size - 1; //�������м���
			right = mid + size;    //�������ҽ��
			if (right >= n)right = n - 1;   //�����г���С��size				
			Merge(d, w, left, mid, right);  //�鲢��������
			left = right + 1;               //��һ�ι鲢ʱ�����е�������
		}
		size *= 2; //���г�������һ��		
	}
	delete[]w;

	
}


//������[first,mid]��[mid+1,right]�ϲ���һ���������� 
template<class T>
void CSort<T>::Merge(T* d, T* w, int left, int mid, int right)
{
	int i = left;      //��������ʼλ��  
	int j = mid + 1;   //��������ʼλ��   
	int k = left;      //����������ʼλ��
	while (k <= right) //��������������СԪ���ȷ��븨������
	{
		if (i > mid)w[k++] = d[j++];
		else if (j > right)	w[k++] = d[i++];
		else
		{
			if (comp(d[j], d[i])) w[k++] = d[j++];
			else w[k++] = d[i++];
		}
	}
	//�����������滻ԭ������
	for (int k = left; k <= right; k++) d[k] = w[k];

	
}


/////////////////////////////////////////////////////////////////////////////////////////
//��������
template<class T>
void CSort<T>::QuickSort(T* d, const int n)
{
	if (n <= 1)return;
	const int M = 7, NSTACK = 128; //�����г���С��7�����ò�������
	int i, j, k, jstack = -1, left = 0, mid, right = n - 1;
	int istack[NSTACK];
	while (true)
	{
		if (right - left < M)   //���뷨����
		{
			for (j = left + 1; j <= right; j++)
			{
				T a = d[j];
				for (i = j - 1; i >= left && comp(a, d[i]); i--)d[i + 1] = d[i]; //��λ				
				d[i + 1] = a; //���뵽׼ȷλ��
			}
			if (jstack < 0) break;     //������ֹ
			right = istack[jstack--];  //�������ҽ��
			left = istack[jstack--];  //����������
		}
		else   //��������
		{
			i = left + 1;      //��ָ��
			j = right;         //��ָ��
			k = i;             //��׼��������
			//��Ԫ����ֵ����Ϊ��׼������������Ϊ��������
			//d[left] < d[k] < d[right]
			mid = (left + right) / 2;
			swap(d[mid], d[k]);
			if (comp(d[right], d[left]))swap(d[left], d[right]);
			if (comp(d[right], d[k]))   swap(d[k], d[right]);
			if (comp(d[k], d[left]))    swap(d[left], d[k]);
			while (true)
			{
				//�ȴ��ұ߿�ʼѰ��С�ڻ�׼����d[j] 			
				do j--; while (comp(d[k], d[j]));
				//�ٴ���߿�ʼѰ�Ҵ��ڻ�׼����d[i] 		
				do i++; while (comp(d[i], d[k]));
				if (j < i)break;
				//����d[j]��d[i] 			
				swap(d[i], d[j]);
			}
			swap(d[j], d[k]);//��׼����λ	
			jstack += 2;
			if (right - i + 1 >= j - left) //�����г��ȴ��������г���
			{
				istack[jstack - 1] = i;    //����������
				istack[jstack] = right;    //�������ҽ��				
				right = j - 1;             //�������ҽڵ�
			}
			else                           //�����г��ȴ��������г���
			{
				istack[jstack - 1] = left; //����������
				istack[jstack] = j - 1;	   //�������ҽ��			
				left = i;                  //��������ڵ�
			}
		}
	}

	
}
