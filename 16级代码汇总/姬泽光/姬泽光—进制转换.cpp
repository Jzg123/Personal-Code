// ǿ��ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
void result(int n, int i, int a[], int b[])						//�������ת����Ľ��
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

void dec_to_bin(double dec)								//ʮ���Ʊ�ɶ����ƺ���
{
	int ingeter_1;
	double ingeter;										//��ʾ����
	double small;										//��ʾС��
	int inge[1000];										//�������ʾ�������ָ���λ���ϵ�����
	int sma[1000];										//С��
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

void bin_to_dec(string in_str)
{
	int point_flag = 0;											//����ȷ���Ƿ���С����
	int num_flag = 0;											//����ȷ�������Ƿ�淶
	double  bin_ing[1000];										//����������λ�ϵ�ÿ������
	double  bin_sma[1000];										//������С��λ�ϵ�ÿ������
	double sum_ing = 0;											//sum_ing��ʾ�������ֵ�ֵ
	double sum_sma = 0;											//��ʼ��sum_sma���������С�����ֵ�ֵ
	int i;														//����һ��ѭ������
	int j;														//j����ȷ��С�����λ��
	for (i = 0; i < in_str.size(); i++)							//�����Ƿ���С����
	{
		if (in_str[i] == '.')									//����У���ô������ַ��η�ΪС�����������ηֱ����
		{
			point_flag = 1;											//flagΪ���ʾ�У�Ϊ����û��
			j = i;
			j++;
			break;
		}
		else
			j = in_str.size() + 1;								//Ϊ����j++����һ��
	}
	for (i = 0; i < j - 1; i++)
	{
		if (in_str[i] >= '2')
		{
			num_flag = 1;
			break;
		}
		if ((in_str[i] >= '0') && (in_str[i] <= '9'))		//��ȡÿһ�����ַ��뵽���������У�
		{
			bin_ing[i] = in_str[i] - '0';
			sum_ing = sum_ing + bin_ing[i] * pow(2, (j - i - 2));	//�����������ֵ�ֵ
		}
	}
	double m = 0.5;
	int k = 1;													//k��ʾ���������ڵ�λ����������Ϊת����10����ʱ��0.5��ָ��
	for (i = j; i < in_str.size(); i++)
	{
		if (in_str[i] >= '2')
		{
			num_flag = 1;
			break;
		}
		if ((in_str[i] >= '0') && (in_str[i] <= '9'))
		{
			bin_sma[i] = in_str[i] - '0';
			sum_sma = sum_sma + bin_sma[i] * pow(m, k);
			k++;
		}
	}
	if (num_flag == 0)
	{
		/*���ֱ�����sum������Կ�ѧ����������ʽ���������һ������һ�����ֵ����*/
		if (sum_ing == 0)											//�����������Ϊ�㣬�������������0��
		{
			cout << '0';
		}
		int ing_num;											//ing_num��ʾ�������ֵ�ÿ��λ���ϵ�����
		ing_num = (int)sum_ing;
		double num[1000];										//num��ʾÿ��λ���ϵ�����
		i = 0;
		while (ing_num != 0)									//����ѭ��ȡ���������ֵ�����
		{
			num[i] = ing_num % 10;
			ing_num = ing_num / 10;
			i++;
		}
		for (int k = i - 1; k >= 0; k--)										//�����������λ�ϵ�����
		{
			cout << num[k];
		}
		if (point_flag == 1)												//����������С���������������� ���С����
		{
			cout << '.';
		}
		int small_num;											//small_num��ʾС������ÿ��λ���ϵ�����
		while (sum_sma != 0)
		{
			sum_sma = sum_sma * 10;
			small_num = floor(sum_sma);
			cout << small_num;
			sum_sma = sum_sma - small_num;
		}
	}
	else
	{
		cout << "������������";
	}
	cout << endl;
}

int main()
{
	double way;											//ѡ��ķ�ʽ��
	while (1)
	{
		cout << "��1��ʾʮ����ת���ɶ����ƣ�2��ʾ������ת����ʮ���ƣ�0��ʾ�˳�����ѡ��";
		cin >> way;
		/*ʮ����ת���ɶ�����*/
		if (way == 1)
		{
			double dec;
			cout << "������ʮ��������";
			cin >> dec;
			dec_to_bin(dec);
		}
		/*������ת����ʮ����*/
		if (way == 2)
		{
			string bin_str;
			cout << "���������������" << endl;
			std::cin >> bin_str;
			bin_to_dec(bin_str);
		}
		if (way == 0)
			break;
		if (way != 1 && way != 2)
		{
			cout << "����ָ������";
		}
	}
	return 0;
}