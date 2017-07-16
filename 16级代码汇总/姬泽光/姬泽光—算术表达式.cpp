// ���ʽ�ļ򵥼���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<double>num_stk;			//����ջ
stack<char>opr_stk;				/*�������ջ*/


void oprate()
{
	char op = opr_stk.top();		//ȡ���������ջ�еĶ�����������������
	double a, b, res;			//����ʱȡ���������ֲ������
	a = num_stk.top();			//ȡ����һ��
	num_stk.pop();				//ɾȥ����ջ����Ԫ�أ��Ӷ�ȡ���ڶ���
	b = num_stk.top();
	num_stk.pop();
	switch (op)					//��������Ž��з������
	{
	case'+':
		res = a + b;
		break;
	case'-':
		res = a - b;
		break;
	case'*':
		res = a * b;
		break;
	case'/':
		res = a / b;
		break;
	default:							//�����������ֱ�ӽ���������
		break;
	}
	opr_stk.pop();					//ɾȥ������������
	num_stk.push(res);				//���������ŵ�ջ�����Ա�������� 
}

int opr_rank(char x)					//����������ȼ��жϺ���
{
	if (x == '(')
		return 0;
	if (x == '+')
		return 1;
	if (x == '-')
		return 2;
	if (x == '*')
		return 3;
	if (x == '/')
		return 4;
}

int main()
{
	int i;
	double x = 0;						//x��ʾ���ʽ�е���					
	string in_str;
	cout << "��������ʽ��" << endl;
	cin >> in_str;
	for (i = 0; i < in_str.size(); i++)
	{ 
		if ((in_str[i] >= '0')&&(in_str[i] <= '9'))
		{
			x = x * 10 + in_str[i]-'0';				//����ַ����е�������12 ��һλ��1 �ڶ�λ��2���� Ҫ��1*10+2 ����x*10+x 
			if (i == in_str.size() - 1)			//�����ж���������ʱ������������������Ե��г�������������  
			{
				num_stk.push(x);
			}
			
		}
													//����ַ���Ϊ���֣�����������ţ������������Ҫ�����ַŵ�����ջ�У�Ȼ���ȡ�����
		else                              
		{
			if (x)
			{
				num_stk.push(x);					//��ĩλ��������ջ��
				x = 0;								//���¹���
			}
			if (opr_stk.empty())					//�������ջΪ�� ���ȡһ������
			{
				opr_stk.push(in_str[i]);
			}
			else if ((in_str[i] == '(')||(in_str[i] == '��'))
			{
				opr_stk.push(in_str[i]);
				
			}
			else if ((in_str[i] == ')') || (in_str[i] == '��'))
			{
				while (opr_stk.top() != '(')
				{
					oprate();								//�ڴ���ǰ���ź����½����жϣ����൱�����������ڵģ���������������ʱ�����Ѿ����й�����������
				}
				opr_stk.pop();								//ɾ��ǰ����
			}
			else if (opr_rank(in_str[i]) <= opr_rank(opr_stk.top()))//�������ڵķ��Ž������ȼ��Ƚϣ������һ��ûǰһ�����ȼ��� ���������
			{
				oprate();
				opr_stk.push(in_str[i]);
			}
			else
				opr_stk.push(in_str[i]);
		}
	}
	while (!opr_stk.empty())
		oprate();
	double res = num_stk.top();
	cout << res << endl;
    return 0;
}