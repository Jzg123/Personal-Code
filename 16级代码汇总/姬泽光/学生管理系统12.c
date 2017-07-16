#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
/*����ṹ��*/ 
struct student
{
	char num[20];
 	char name[20];
 	int cgrade;
 	int	mgrade;
 	int egrade;
 	int total;
 	float ave;
 	struct  student  *next;
} *head=NULL;

/*��ʾѧ���ɼ���Ϣ*/
void dayin(struct student *p,struct student *head)
{
	if(p==NULL)															//ȫ����ʾ 
	{
		p=head;
		while(p!=NULL)
		{
			printf("ѧ�ţ�%-5s������%-5sC���Գɼ���%-5d��ѧ�ɼ�: %-5dӢ��ɼ���%-5d�ܳɼ�Ϊ��%-5dƽ���ɼ�Ϊ��%-5.2f\n",p->num,p->name,p->cgrade,p->mgrade,p->egrade,p->total,p->ave);
			p=p->next;
		}
	}
	else																//��ʾ�ض�ѧ�Ż��������ĳɼ���Ϣ 
	{
		p->total=p->cgrade+p->egrade+p->mgrade;
		p->ave=p->total/3;
		printf("ѧ�ţ�%-5s������%-5sC���Գɼ���%-5d��ѧ�ɼ�: %-5dӢ��ɼ���%-5d�ܳɼ�Ϊ��%-5dƽ���ɼ�Ϊ��%-5.2f\n",p->num,p->name,p->cgrade,p->mgrade,p->egrade,p->total,p->ave);
	}
} 

/*����ú���*/ 
struct student *addnew(struct student *head,char *num,char *name,int *cgrade,int *mgrade,int *egrade)
{
	struct student *p0,*p1;
	int *total;
	float *ave;
	p0=(struct student *)malloc(sizeof(struct student));
	strcpy(p0->num,num);
	strcpy(p0->name,name);
	p0->cgrade=*cgrade;
	p0->mgrade=*mgrade;
	p0->egrade=*egrade;
	p0->total=p0->cgrade+p0->egrade+p0->mgrade;
	p0->ave=p0->total/3;
	if(head==NULL)
		head=p0;
	else
	{
		p1=head;
		while(p1->next!=NULL)					//��ͷ��ʼ�����ң������� û������
		{
			p1=p1->next;
		}
		p1->next=p0;
	}
	p0->next=NULL;
	return head;
}

/*��ʾ���˵�����*/
void menu()
{
	printf("******************************* ѧ���ɼ�����ϵͳ *******************************\n");
	printf("*                                                                              *\n");
	printf("*          1 ����ѧ���ɼ�                           2 ɾ��ѧ���ɼ�             *\n");
	printf("*                                                                              *\n");
	printf("*          3 ����ѧ���ɼ�                           4 �޸�ѧ���ɼ�             *\n");
	printf("*                                                                              *\n");
	printf("*          5 ����ѧ���ɼ�                           6 ͳ��ѧ���ɼ�             *\n");
	printf("*                                                                              *\n");
	printf("*          7 ����ѧ���ɼ�                           8 ����ѧ���ɼ�             *\n");
	printf("*                                                                              *\n");
	printf("*          9 ��ʾѧ���ɼ�                           0 �˳�����ϵͳ             *\n");
	printf("******************************* ѧ���ɼ�����ϵͳ *******************************\n");
}

/*����ѧ����Ϣ*/
struct student *find1(struct student *head,char *num) 							//��ѧ�Ų���  
{
	if(head==NULL)
	{
		printf("��������ѧ���ɼ���\n");
		return head;
	}
	struct student *p1,*p2;
	p1=head;
	p2=NULL;
	while(p1!=NULL)
	{
		if(strcmp(p1->num,num)==0)
		{
			p2=p1;
			printf("\n�ҵ������ݣ�\n");	
			dayin(p1,head);							
		}
		p1=p1->next;
	}
	if(p2==NULL)
	{
		printf("\nδ�ҵ������ݣ�\n");
	}
	return p2;
}

struct student *find2(struct student *head,char *name) 								//����������  
{
	struct student *p1,*p2;
	p1=head;
	p2=NULL;
	if(head==NULL)
	{
		printf("��������ѧ���ɼ���");
		return head;
	}
	while(p1!=NULL)
	{
		if(strcmp(p1->name,name)==0)
		{
			p2=p1;
			printf("\n�ҵ������ݣ�\n");	
			dayin(p1,head);							//���������� 
		}
		p1=p1->next;
	}
	if(p2==NULL)
	{
		printf("\nδ�ҵ������ݣ�\n");
	}
	return p2;
}

/*����һ����˵������ɾ�����ݵĺ���~*/ 
struct student *dele(struct student *head,struct student *p)
{
	struct student *p1,*p2;
	p1=head;
	if(head==NULL)
	{
		printf("��������ѧ���ɼ���\n");
		return head;
	}
	while(p1 != p && p1!=NULL)
	{
		p1=p1->next;
	}
	if(p1==NULL)
		printf("δ�ҵ������ݣ����֤����������\n");
	if(p1==p)
	{
		if(p1==head)																	//Ҫ����һ��ɾ����ͷ���ݵ���� ��Ȼ�ᡭ��ֹͣ����&����
		{
			head=p1->next;
		}	
		else													 
			{
				p2=head;
				while(p2->next!=p1)														//��Ҫɾ���Ľṹ���������ɾȥ 
				{
					p2=p2->next;
				}
				p2->next=p1->next;
				printf("ɾ���ɹ���\n");
			}
	}
	return head;
} 

/*�޸��ú���*/ 
void xiugai(struct student *p)
{
	int n;
	int score;
	if(p==NULL)
	{
		printf("\n�޸�ʧ�ܣ�");
		printf("\nԭʼ����Ϊ��\n"); 
		return;
	}
	else
	{
		printf("\n���������޸ĵĳɼ����ţ�1��ʾC���Գɼ���2��ʾ��ѧ�ɼ���3��ʾӢ��ɼ�\t");
		scanf("%d",&n);
		printf("\n����������ÿƳɼ���");
		scanf("%d",&score);
		switch(n)
		{
			case 1:
				p->cgrade=score;
				printf("�޸ĳɹ���");
				break;
			case 2:
				p->mgrade=score;
				printf("�޸ĳɹ���");
				break;
			case 3:
				p->egrade =score;
				printf("�޸ĳɹ���");
				break;
			default:
				printf("��������������������룡"); 
				break;
		}
	}
} 

/*��ѯǰ��ѯ��*/
struct student *before()
{
		int way;
		char num[20],name[20];
		struct student *p1;
		scanf("%d",&way);
		if(way==1)
		{
			printf("\n��������Ҫ��ѯ��ѧ�ţ�");
			scanf("%s",num);
			p1=find1(head,num);
		} 
		if(way==2)
		{
			printf("\n��������Ҫ��ѯ��������");
			scanf("%s",name);
			p1=find2(head,name);
		}
		if(way!=1&&way!=2)
		{
			printf("\n����ȷ����~");
			return NULL;
		}
		return p1;
}

/*���������ṹ�������*/
void exchange(struct student *p1,struct student *p2) 
{
	char data[20];
	strcpy(data,p1->name);
	strcpy(p1->name,p2->name);
	strcpy(p2->name,data);
	strcpy(data,p1->num);
	strcpy(p1->num,p2->num);
	strcpy(p2->num,data);
	int data2;
	data2=p1->cgrade;
	p1->cgrade=p2->cgrade;
	p2->cgrade=data2;
	data2=p1->mgrade;
	p1->mgrade=p2->mgrade;
	p2->mgrade=data2;
	data2=p1->egrade;
	p1->egrade=p2->egrade;
	p2->egrade=data2;
	data2=p1->ave;
	p1->ave=p2->ave;
	p2->ave=data2;
	data2=p1->total;
	p1->total=p2->total;
	p2->total=data2;
	
}

/*��ѧ������*/
void sort(struct student *head)										//ѧ��λ����ͬ������������ 
{
	struct student *p1,*p2,*p0;
	p1=head;
	if(head==NULL)
	{
		printf("\n��������ѧ���ɼ���\n");
		return;
	}
	else
	{
		while(p1->next!=NULL)
		{	
			p0=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if(strcmp(p0->num,p2->num)>0)
					p0=p2;
				p2=p2->next;
			}
			if(p0!=p1)
				exchange(p0,p1);
			p1=p1->next;
		}
	}
}

/*���浽�ļ�*/
void savefile(struct student *head)
{	
	char filename[200];
	printf("�����뱣����ļ�����");
	scanf("%s",filename); 
	struct student *p;
	p=head;
	FILE *fp;
	if(head==NULL)
	{
		printf("\n������ѧ����Ϣ��\n");
		return; 
	}
	else
	{
		if((fp=fopen(filename,"wb+"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�"); 
			return;
		}
		while(p!=NULL)
		{
			if(fwrite(p,sizeof(struct student),1,fp)!=1)
			{
				printf("д���ļ�ʧ�ܣ�");
				fclose(fp);
				break;
			}
			p=p->next;
		}
		fclose(fp);
		printf("����ɹ���\n"); 
	}
} 

/*���ɼ�����*/
struct student *sortbygrade(struct student *head,int n)
{
	struct student *p1,*p2,*p0;
	p1=head;
	if(head==NULL)
	{
		printf("\n��������ѧ���ɼ���\n");
		return head;
	}
	if(n==1)														//��C���Գɼ����� 
	{
		while(p1->next!=NULL)
		{	
			p0=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if((p0->cgrade)>(p2->cgrade))
					p0=p2;
				p2=p2->next;
			}
			if(p0!=p1)
				exchange(p0,p1);
			p1=p1->next;
		}
	}
	if(n==2)
	{
		while(p1->next!=NULL)
		{	
			p0=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if(p0->mgrade>p2->mgrade)							//����ѧ�ɼ�����
					p0=p2;
				p2=p2->next;
			}
			if(p0!=p1)
				exchange(p0,p1);
			p1=p1->next;
		}
	}
	if(n==3)														//��Ӣ��ɼ����� 
	{
		while(p1->next!=NULL)
		{	
			p0=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if(p0->egrade>p2->egrade)
					p0=p2;
				p2=p2->next;
			}
			if(p0!=p1)
				exchange(p0,p1);
			p1=p1->next;
		}
	}
	if(n==4||n==5)													//���ܳɼ�����ƽ���ɼ��ɼ����� 
	{
		while(p1->next!=NULL)
		{	
			p0=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if(p0->total>p2->total)
					p0=p2;
				p2=p2->next;
			}
			if(p0!=p1)
				exchange(p0,p1);
			p1=p1->next;
		}
	if(n!=1&&n!=2&&n!=3&&n!=4&&n!=5)
	{
		printf("�����������");
		return head;
	} 
	}
	return head;
} 

/*ͳ�����ݸ�ʽ������*/
void form(int n9,int n8,int n7,int n6,int n0)
{
	printf("90~100��	%d  ��\n",n9);
	printf("80~90 ��	%d  ��\n",n8);
	printf("70~80 ��	%d  ��\n",n7);
	printf("60~70 ��	%d  ��\n",n6);
	printf("60���£�	%d  ��\n",n0);
}

/*ͳ�ƺ���*/
void count(struct student *head)
{
	struct student *p1,*p2;
	int n9=0,n8=0,n7=0,n6=0,n0=0;
	p1=head;
	if(head==NULL)
	{
		printf("��������ѧ���ɼ���");
		return;
	}
	while(p1!=NULL)
	{
		if((p1->cgrade)>=90&&(p1->cgrade)<100)
		{
			n9++;
		}
		if((p1->cgrade)>=80&&(p1->cgrade)<90)
		{
			n8++;
		}
		if((p1->cgrade)>=70&&(p1->cgrade)<80)
		{
			n7++;
		}
		if((p1->cgrade)>=60&&(p1->cgrade)<70)
		{
			n6++;
		}
		if((p1->cgrade)<60)
		{
			n0++;
		}
		p1=p1->next;
	}
	printf("\nC���Գɼ������\n");
	form(n9,n8,n7,n6,n0);
	p1=head;
	n9=0,n8=0,n7=0,n6=0,n0=0;
	while(p1!=NULL)
	{
		if((p1->mgrade)>=90&&(p1->mgrade)<100)
		{
			n9++;
		}
		if((p1->mgrade)>=80&&(p1->mgrade)<90)
		{
			n8++;
		}
		if((p1->mgrade)>=70&&(p1->mgrade)<80)
		{
			n7++;
		}
		if((p1->mgrade)>=60&&(p1->mgrade)<70)
		{
			n6++;
		}
		if((p1->mgrade)<60)
		{
			n0++;
		}
		p1=p1->next;
	}
	printf("��ѧ�ɼ������\n");
	form(n9,n8,n7,n6,n0);
	p1=head;
	n9=0,n8=0,n7=0,n6=0,n0=0;
	while(p1!=NULL)
	{
		if((p1->egrade)>=90&&(p1->egrade)<100)
		{
			n9++;
		}
		if((p1->egrade)>=80&&(p1->egrade)<90)
		{
			n8++;
		}
		if((p1->egrade)>=70&&(p1->egrade)<80)
		{
			n7++;
		}
		if((p1->egrade)>=60&&(p1->egrade)<70)
		{
			n6++;
		}
		if((p1->egrade)<60)
		{
			n0++;
		}
		p1=p1->next;
	}
	printf("Ӣ��ɼ������\n");
	form(n9,n8,n7,n6,n0);
}

/*����ͳ�����ֵ�ĺ���*/
void countmax(struct student *head)
{
	struct student *p1,*p2;
	if(head==NULL)
	{
		printf("��������ѧ���ɼ���");
		return;
	}
	p1=sortbygrade(head,1);
	p2=p1->next;
	int max1,max2,max3,max0;
	char num1[20],num2[20],num3[20],num0[20];
	while(p2!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	max1=p1->cgrade;
	strcpy(num1,p1->num);
	p1=sortbygrade(head,2);
	p2=p1->next;
	while(p2!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	max2=p1->mgrade;
	strcpy(num2,p1->num);
	p1=sortbygrade(head,3);
	p2=p1->next;
	while(p2!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	max3=p1->egrade;
	strcpy(num3,p1->num);
	p1=sortbygrade(head,4);
	p2=p1->next;
	while(p2!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	max0=p1->total;
	strcpy(num0,p1->num);
	printf("\nC������߷��ǣ�%d\tѧ��Ϊ��%s\n",max1,num1);
	printf("��ѧ��߷��� ��%d\tѧ��Ϊ��%s\n",max2,num2);
	printf("Ӣ����߷��� ��%d\tѧ��Ϊ��%s\n",max3,num3);
	printf("�ܷ���߷��� ��%d\tѧ��Ϊ��%s\n",max0,num0);
}

int main()
{
	int key;
	char num[20] = {0},name[20] = {0};
	int cgrade;
 	int	mgrade;
 	int egrade;
 	int total;
 	float ave;
 	struct student *p1;
 	int way;
	menu();
	printf("������������еĲ������ţ�");
	scanf("%d",&key); 
	while(key!=0)
		{
			switch(key)
			{
				case 1:
					printf("\n������ѧ��ѧ�� ");
					scanf("%s",num);
					printf("\n������ѧ������ "); 
					scanf("%s",name);
					printf("\n������ѧ��C���Գɼ� "); 
					scanf("%d",&cgrade);
					printf("\n������ѧ����ѧ�ɼ� "); 
					scanf("%d",&mgrade);
					printf("\n������ѧ��Ӣ��ɼ� "); 
					scanf("%d",&egrade);
					head=addnew(head,num,name,&cgrade,&mgrade,&egrade);
					break;
				case 2:
					printf("\n��ѡ��ɾ����ʽ��1��ʾѧ�ţ�2��ʾ����:");
					p1=before();
					head=dele(head,p1);
					break;
				case 3:
					printf("\n��ѡ���ѯ��ʽ��1��ʾѧ�ţ�2��ʾ����:");
					p1=before();
					break;
				case 4:
					printf("\n��ѡ���޸ĵĶ���1��ʾѧ�ţ�2��ʾ������");
					p1=before();
					xiugai(p1);
					printf("\n");
					dayin(p1,head);
					break;
				case 5:
					printf("\n���������ѧ��ѧ�� ");
					scanf("%s",num);
					printf("\n���������ѧ������ "); 
					scanf("%s",name);
					printf("\n���������ѧ��C���Գɼ� "); 
					scanf("%d",&cgrade);
					printf("\n���������ѧ����ѧ�ɼ� "); 
					scanf("%d",&mgrade);
					printf("\n���������ѧ��Ӣ��ɼ� "); 
					scanf("%d",&egrade);
					head=addnew(head,num,name,&cgrade,&mgrade,&egrade);
					sort(head);
					printf("\n����ɹ�!\n");
					break;
				case 6:
					count(head);
					countmax(head);
					break;
				case 7:
					printf("��ѡ������ʽ��1��ʾ��C���Գɼ���2��ʾ��ѧ�ɼ���3��ʾӢ��ɼ���4��ʾ�ܷ֣�5��ʾƽ���֣�"); 
					scanf("%d",&way);
					sortbygrade(head,way);
					dayin(p1,head);
					break;
				case 8:
					savefile(head);
					break;
				case 9:
					sort(head);
					dayin(p1,head);
					break; 
				case 0:
					break;
				default:
					printf("�����ʽ����"); 
			}
			p1=NULL;
			printf("\n������������еĲ������ţ�");
			scanf("%d",&key);
			system("CLS");
			menu();
		}
	return 0;
} 
