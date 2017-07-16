#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
bool Comp(const int &a,const int &b)
	{
		return a>b;
	}

//������ʵ������
template<class T,class InputIterator,class OutputInterator>
void mySort(InputIterator first,InputIterator last,OutputInterator result)
{
	vector<T>s;
	for(;first!=last;++first)
	{
		s.push_back(*first);
	}
	sort(s.begin(),s.end());
	copy(s.begin(),s.end(),result);
}

int main()
{
	//size()
	vector<int>vec;
	for(int i=0;i<=9;i++)
	{
		vec.push_back(i);
	}
	cout<< "������СΪ: "<<vec.size()<<endl<<endl;
	cout<<"�����е����ݷֱ�Ϊ��";
	for(int i=0;i<=9;i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl<<endl;

	//��������insert()
	cout<<"�ֱ���������a��b���ڵ�b��Ԫ�غ������a��:";
	int a,b;
	cin>>a>>b;
	cout<<endl;
	vec.insert(vec.begin()+b,a);
	cout<<"�������ݺ������е����ݷֱ�Ϊ��";
	for(int i=0;i<=10;i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl<<endl;

	//sort()
	vector<int>::iterator first=vec.begin();
	vector<int>::iterator last=vec.end();
	sort(first,last,Comp);
	cout<<"�Ӵ�С���У�";
	for(int i=0;i<=10;i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl<<endl;

	//reverse()
	cout<<"��Ԫ�ط�ת:";
	reverse(first,last);
	for(int i=0;i<=10;i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl<<endl;

	//erase()
	cout<<"����x,y,ɾ����x��y���Ԫ�أ�";
	int x,y;
	cin>>x>>y;
	cout<<endl;
	vec.erase(first+x,first+y-1);
	cout<<"ɾ����������е�Ԫ�أ�";
	for(int i=0;i<=10-(y-x-1);i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl<<endl;

	//resize()
	vec.resize(100);
	cout<<"����������Ϊ��"<<vec.capacity();
	cout<<endl<<endl;

	//������ʵ��
	cout<<"������ʵ������";cout<<endl;
	cout<<"���������������س�--Ctrl+z--�س� �������룩��";
	mySort<int>(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout," "));

	return 0;
}