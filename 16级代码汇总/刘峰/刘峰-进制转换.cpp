//ʮת������֧��С��λ
//��תʮ����֧��С��λ
//ע�ͣ��� �϶�
//������B+ ����д
#include <stdio.h>
int main()
{
    int Type,a,b[10],i=0,c=0;
    printf("������ת�����ͣ�1��ʮ����ת�����ƣ�2��������תʮ����\n");
    scanf("%d",&Type);
    printf("������ԭ����\n");
    scanf("%d",&a);
    switch(Type)
	{
      case 1:
        while(a!=0)
		{
           b[i]=a%2;
		   a/=2;
           i++;
		}
         printf("������Ϊ��");
			 i--;
         for(;i>=0;i--)
			 printf("%d",b[i]);
             printf("\n");
            break;
	  case 2:
        while(a!=0)
        {
            b[i]=a%10;
            a/=10;
            i++;
        }
        i--;
        for(;i>=0;i--)
            c=c*2+b[i];
        printf("ʮ����Ϊ��%d\n",c);
        break;
    }
	return 0;
}
