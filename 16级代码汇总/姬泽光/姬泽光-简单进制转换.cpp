// ǿ��ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//ʮת����A+
//��תʮ����֧��̫��λ
//ע�ͣ��� �϶�
//������B+ ����д
//#include "stdafx.h"
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
void result(int n, int i,int a[],int b[])						//�������ת����Ľ��
{
	i--;														//��ѭ������ʱ��������һ��
	n--;														//ͬ��
	if (i == -1)												//ȷ��С�����������һλ
	{
		i = 0;
		b[0] = 0;
	}
	if (n == -1)												//ȷ��С�����������һλ
	{
		n = 0;
		a[0] = 0;
	}
	if (i > 5)													//������λС��
	{
		i = 5;
	}
	for (; n >= 0; n--)											//�������ֵ������
	{
		cout << a[n];
	}
	cout << ".";												//���С����
	for (int j = 0; i >= j; j++)								//С�������������
	{
		cout << b[j];
	}
	cout << endl;
}
int main()
{
	double bin;											//��ʾ������
	double dec;											//��ʾʮ����
	double ingeter;										//��ʾ����
	double small;										//��ʾС��
	int inge[1000];										//�������ʾ�������ָ���λ���ϵ�����
	int sma[1000];										//С��
	double way;											//ѡ��ķ�ʽ��
	int ingeter_1;
	while (1)
	{
		cout << "1��ʾʮ����ת���ɶ����ƣ�2��ʾ������ת����ʮ���ƣ�0��ʾ�˳�����ѡ��";
		cin >> way;
		if (way == 1)
		{
			cout << "������ʮ��������";
			cin >> dec;
			ingeter = floor(dec);								//floor��������ȡ����������ֵΪdouble����
			small = dec - ingeter;								//��ȥ������С����
			ingeter_1 = ingeter;								//ǿ��ת����int���ͣ��Ա�ʹ��%ȡ����λ���ϵ�����
			int n = 0;
			while (ingeter_1 != 0)
			{
				int num = ingeter_1 % 2;						//num��ʾ����λ���ϵ���ֵ
				inge[n] = num;
				ingeter_1 = ingeter_1 / 2;
				n++;
			}
			int i = 0;
			while (small != 0)
			{
				int num = small * 2;								//��10����С��ת����2����
				sma[i] = num;
				small = small * 2 - num;
				i++;
			}
			cout << "ת���ɶ����ƺ�Ľ��Ϊ��";
			result(n, i, inge, sma);
		}

		/*������ת����ʮ����*/
		if (way == 2)
		{
			int flag = 1;
			cout << "���������������";
			cin >> bin;
			ingeter = floor(bin);								//floor��������ȡ����������ֵΪdouble����
			small = bin - ingeter;								//��ȥ������С������
			ingeter_1 = ingeter;								//ǿ��ת����int���ͣ��Ա�ʹ��%ȡ����λ���ϵ�����
			int n = 0;
			int bin_inge = 0;
			while (ingeter_1 != 0)
			{
				int num = ingeter_1 % 10;						//num��ʾ����λ���ϵ���ֵ
				if (num > 1)									//�������в�����2
				{
					cout << "������������" << endl;
					flag = 0;
					break;
				}
				inge[n] = num*pow(2, n);
				ingeter_1 = ingeter_1 / 10;
				bin_inge = bin_inge + inge[n];
				n++;
			}
			int i = 0;
			double bin_small = 0;
			while (small != 0)
			{
				int k = i;
				small = small * 10;
				int num = (int)small;
				if (small > 3&&i <= 6)
				{
					cout << "������������" << endl;
					flag = 0;
					break;
				}
				double m = 0.5;										//1/2��n�η�
				for (; k > 0; k--)
				{
					m = m*m;
				}
				bin_small = bin_small + num*m;
				i++;
				small = small - (int)small;
			}
			dec = bin_small + bin_inge;
			if (flag == 1)
			{
				cout << "ת����ʮ���ƺ�Ľ��Ϊ��" << dec << endl;
			}

		}
		if (way == 0)
			break;
		if (way != 1 && way != 2)
		{
			cout << "����ָ������";
		}
		system("pause");
	}
	return 0;
}
