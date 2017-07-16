#pragma once
#include"node.h"
#include"student.h"
class linkedlist
{
private:
	node *head;
public:
	
	linkedlist()
	{
		head=new node;
		head->next=NULL;
	}

	~linkedlist()
	{
		node *p =head;
		while(p!=NULL)
		{
			node *temp=p;
			p=p->next;			
			delete temp;
		}
	}
	



	void newstudent()
	{
		node *pTail=head;
		int num;
		long long student_id;
		int age,grade;
		double terminal_score;
		string name,sex,clas,major;

		cout<<"��������Ҫ�洢ѧ��������:";
		cin>>num;

		for(int i=1;i<=num;i++)
		{
			node *pNew=new node;

			cout<<"����ѧ�ţ�";cin>>student_id;
			cout<<"����������";cin>>name;
			cout<<"�����Ա�";cin>>sex;
			cout<<"�������䣺";cin>>age;
			cout<<"����רҵ��";cin>>major;
			cout<<"�����꼶��";cin>>grade;
			cout<<"����༶��";cin>>clas;
			cout<<"������ĩ�ɼ���";cin>>terminal_score;

			pNew->st.setname(name);
			pNew->st.setage(age);
			pNew->st.setsid(student_id);
			pNew->st.setgrade(grade);
			pNew->st.setsex(sex);
			pNew->st.setmajor(major);
			pNew->st.setclass(clas);
			pNew->st.setterminalscore(terminal_score);

			pTail->next=pNew;
			pTail=pNew;
			pTail->next=NULL;
		}

		cout<<"�ɹ����������������"<<num<<"��ѧ������Ϣ"<<endl;
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}



	void addstudent()
	{		
		long long student_id;
		int age,grade;
		double terminal_score;
		string name,sex,clas,major;
		node *p =head;
		node *pNew,*ptail=new node;;
		while(p!=NULL)
		{
			pNew=p;
			p=p->next; 
		}
		pNew->next=ptail; 
		ptail->next=NULL; 

		cout<<"����ѧ�ţ�";cin>>student_id;
		cout<<"����������";cin>>name;
		cout<<"�����Ա�";cin>>sex;
		cout<<"�������䣺";cin>>age;
		cout<<"����רҵ��";cin>>major;
		cout<<"�����꼶��";cin>>grade;
		cout<<"����༶��";cin>>clas;
		cout<<"������ĩ�ɼ���";cin>>terminal_score;

		ptail->st.setname(name);
		ptail->st.setage(age);
		ptail->st.setsid(student_id);
		ptail->st.setgrade(grade);
		ptail->st.setsex(sex);
		ptail->st.setmajor(major);
		ptail->st.setclass(clas);
		ptail->st.setterminalscore(terminal_score);
				
		cout<<"�ɹ���������м�����1��ѧ������Ϣ"<<endl;
					
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}

	void changestudent()
	{
		node *p =head;
		long long student_id;
		int flag = 0;
		cout<<"����������Ҫ�޸ĵ�ѧ����ѧ��:";
		cin>>student_id;
		while(p!=NULL)
		{
			if(student_id==p->st.getsid())
			{
				flag+=1;

				long long student_id;
				int age,grade;
				double terminal_score;
				string name,sex,clas,major;

				cout<<"����ѧ�ţ�";cin>>student_id;
				cout<<"����������";cin>>name;
				cout<<"�����Ա�";cin>>sex;
				cout<<"�������䣺";cin>>age;
				cout<<"����רҵ��";cin>>major;
				cout<<"�����꼶��";cin>>grade;
				cout<<"����༶��";cin>>clas;
				cout<<"������ĩ�ɼ���";cin>>terminal_score;
				

				p->st.setname(name);
				p->st.setage(age);
				p->st.setsid(student_id);
				p->st.setgrade(grade);
				p->st.setsex(sex);
				p->st.setmajor(major);
				p->st.setclass(clas);
				p->st.setterminalscore(terminal_score);

				cout<<"�޸���ɣ�"<<endl;
				break;
			}

			p=p->next;
		}

		if(flag==0)
		{
			cout<<"û�ҵ�����Ҫ�޸ĵ�ѧ����Ϣ!"<<endl;
			return;
		}
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}


	void searchstudent()
	{
		node *p =head;
		long long student_id;
		int flag = 0;
		cout<<"����������Ҫ���ҵ�ѧ����ѧ��:";
		cin>>student_id;
		while(p!=NULL)
		{
			if(student_id==p->st.getsid())
			{
				flag+=1;
				cout<<"������"<<p->st.getname()<<endl;
				cout<<"�Ա�"<<p->st.getsex()<<endl;
				cout<<"���䣺"<<p->st.getage()<<endl;
				cout<<"רҵ��"<<p->st.getmajor()<<endl;
				cout<<"�꼶��"<<p->st.getgrade()<<endl;
				cout<<"�༶��"<<p->st.getclass()<<endl;
				cout<<"��ĩ�ɼ���"<<p->st.getterminalscore()<<endl;
				break;
			}

			p=p->next;
		}

		if(flag==0)
		{
			cout<<"û�ҵ�����Ҫ�޸ĵ�ѧ����Ϣ!"<<endl;
			return;
		}
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}

	

	void deletestudent()
	{
		node *p =head,*pnew;
		long long student_id;
		int flag=0;
		cout<<"����������Ҫɾ����ѧ����ѧ��:";
		cin>>student_id;
		while(student_id!=p->st.getsid())
		{
			pnew=p;
			if(p->next==NULL)
			{
				flag=0;
				break;
			}
			p=p->next;	
			flag++;
		}
		if(flag!=0)
		{
			pnew->next=p->next;
			free(p);
			cout<<"ɾ���ɹ���"<<endl;
		}
		if(flag==0)
		{
			cout<<"û�ҵ�����Ҫɾ����ѧ��!"<<endl;
			return;
		}
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}


	void sortstudents()
	{
		node *p,*q;
		node temp;
		cout<<"��ѧ�Ż��ǰ��������򣿣�ѧ��x,����f��";
		char a;
		cin>>a;
		if(a=='x')
		{
			for(p=head;p!=NULL;p=p->next)
			{
				for(q=p->next;q!=NULL;q=q->next)
				{
					if(p->st.getsid()>q->st.getsid())
					{
						temp.st=p->st;
						p->st=q->st;
						q->st=temp.st;
					}
				}
			}
		}
		if(a=='f')
		{
			for(p=head;p!=NULL;p=p->next)
			{
				for(q=p->next;q!=NULL;q=q->next)
				{
					if(p->st.getterminalscore()>q->st.getterminalscore())
					{
						temp.st=p->st;
						p->st=q->st;
						q->st=temp.st;
					}
				}
			}
		}
		cout<<"������ɣ�"<<endl;
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}


	void showallstudents()
	{
		node *p=head;
		cout<<"==============================================================================="<<endl;
		cout<<"|     ѧ��     |  ����  |�Ա�|����|     רҵ     |�꼶|     �༶     |��ĩ�ɼ�|"<<endl;
		cout<<"==============================================================================="<<endl;
		while(p!=NULL)
		{	
			if(p->st.getsid()==0)
				{p=p->next;continue;}

			cout<<"|"<<setw(14)<<p->st.getsid()
				<<"|"<<setw(8)<<p->st.getname()
				<<"|"<<setw(4)<<p->st.getsex()
				<<"|"<<setw(4)<<p->st.getage()
				<<"|"<<setw(14)<<p->st.getmajor()
				<<"|"<<setw(4)<<p->st.getgrade()
				<<"|"<<setw(14)<<p->st.getclass()
				<<"|"<<setw(8)<<p->st.getterminalscore()
				<<"|"<<endl;
			cout<<"==============================================================================="<<endl;
			p=p->next;
		}
		cout<<"�����������"<<endl;
		system("pause");
		system("cls");
	}
		
};

