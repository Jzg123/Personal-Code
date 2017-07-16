#include "vector"  
#include "string"  
#include <iostream>  
#include "algorithm"    
using namespace std;  
  
void MakeNext(const string &P, vector<int> &next)  
{  
    int q,k;    
    int m = P.size();    
    next[0] = 0;    
    for (q = 1, k = 0; q < m; ++q)    
    {  
           
        while (k > 0 && P[q] != P[k])  
            k = next[k - 1];  
        if (P[q] == P[k])  
            k++;    
        next[q] = k;    
    }  
}  
    
void KmpMatch(const string &T, const string &P, vector<int> &next)  
{  
    int n, m;  
    n = T.size();  
    m = P.size();  
    MakeNext(P, next);  
    for (int i = 0, q = 0; i < n; ++i)  
    {  
        while (q > 0 && P[q] != T[i])  
            q = next[q - 1];  
        if (P[q] == T[i])  
            q++;  
        if (q == m)  
        {  
            cout << "ģʽ�ı���ƫ��Ϊ��" << (i - m + 1) << endl;  
            q = next[q - 1];  
        }  
    }  
}    
int main()  
{  
    system("color 0A");  
    vector<int> next(20,0);
    string T = "xyxababcaxxxababca";  
    string P = "ababca";  
    cout <<"�ı��ַ�����"<< T << endl;  
    cout <<"ģʽ�ַ�����"<< P << endl;  
    KmpMatch(T, P, next);  
    cout << "ģʽ�ַ�����ǰ׺������"<< endl;  
    for (int i = 0; i < P.size(); i++)  
        cout<< next[i];  
    cout << endl;  
    system("pause");  
    return 0;  
}  
