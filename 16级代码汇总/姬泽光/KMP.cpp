// iMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#include<string>
using namespace std;
void get_next(string tar_str, int next[])								//������ƥ����ַ���Ŀ��ȷ�������ƶ����ٸ�����
{
	int i = 0;
	next[0] = -1;
	int j = -1;
	while (i < tar_str.size())											//Ѱ�����ַ�������ȷ��ƥ��������ƶ������Ĺ�ϵ
	{
		if (j == -1 || tar_str[i] == tar_str[j])						//j=-1��ʾ��δ��ʼƥ��
		{
			i++;
			j++;
			next[i] = j;												//�����ͬ�����´�ʱ��j��ֵ��Ϊ�ƶ�����
		}
		else
		{
			j = next[j];												//���Ⱦ���ǰ�ƣ�Ѱ����ȵ����
		}
	}
}
void iMP(string in_str,string tar_str)
{
	int flag = 0;								//ƥ���Ƿ�ɹ��ı�ʶ
	int i = 0, j = -1;
	int next[1000];								//�ƶ�λ����ƥ������Ĺ�ϵ����
	get_next(tar_str, next);
	for (i = 0; i < in_str.size(); i++)							//����˫ѭ��ƥ��,��������ͬλ���ϵĽ��
	{
		for (j = 0; j < tar_str.size(); )
		{
			if (in_str[i] == tar_str[j])						//�жϸ���λ���Ƿ����
			{
				if ((j == tar_str.size() - 1))			/*���ģʽ�������һλҲ����ˣ���ô������ƥ��ɹ���*/
				{
					cout << "���ַ�����λ�ã�" << i + 2 - tar_str.size() << endl;
					flag = 1;								/*ƥ��ɹ���ʶ��Ϊ1*/
				}
				else
				{
					i++;								//��������ȶ�
				}
				j++;
			}
			else
			{
				j = next[j];							//�ȶԲ��ɹ�������get_next����Ѱ���ƶ�λ��
			}
		}
	}
	if (flag == 0)
		cout << "ƥ��ʧ�ܣ�" << endl;
}

int main()
{
	string in_str;
	cout << "���������ַ�����";
	cin >> in_str;
	string tar_str;
	cout << "������ģʽ����";
	cin >> tar_str;
	iMP(in_str, tar_str);
    return 0;
}

