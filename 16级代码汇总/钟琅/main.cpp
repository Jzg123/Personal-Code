#include<iostream>
#include<iomanip>
#include <cstdlib>
#include"student.h"
#include"linkedlist.h"

using namespace std;

int main()
{
	linkedlist students;
	cout<<"��Ϣ����ϵͳ"<<endl;
	cout<<"��δ������Ϣ������"<<endl;
	students.newstudent();

tt:

	cout<<"                   ѡ�����"<<endl;
	cout<<"a.����     b.�޸�     c.��ѯ     d.ɾ��     e.����     f.��ʾ������Ϣ     g.�˳�"<<endl;

	char choice;
	cin>>choice;

	switch(choice)
	{
	case 'a':
		{
			students.addstudent();break;
		}

	case 'b':
		{
			students.changestudent();break;
		}

	case 'c':
		{
			students.searchstudent();break;
		}

	case 'd':
		{
			students.deletestudent();break;
		}

	case 'e':
		{
			students.sortstudents();break;
		}

	case 'f':
		{
			students.showallstudents();break;
		}

	case 'g':
		{
			goto exit;
		}

	default:
		break;
	}

	goto tt;

exit:

	return 0;
}

