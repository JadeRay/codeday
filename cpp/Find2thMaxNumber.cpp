//�����������еڶ������
//˵�����ڶ������Ӧ������ֵ�ϵڶ���ģ��������ȫ����ֵ����û�еڶ������
#include <iostream>
#include<string.h>
using namespace std;

const int INT_MINNUM = 0xFFFFFFFF;
bool Find2thMaxNum(int* arr, int n, int& secondMax)
{
    int max = arr[0];
    secondMax = INT_MINNUM;
    for(int i = 1 ; i < n ; ++i)
    {
        if(arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] < max)
        {
            secondMax = arr[i];
        }
    }
    if(secondMax == INT_MINNUM) return false;
    else return true;
}

void f(char *x)
{
         x++;
         *x= 'a';
}

int main()
{
       char str [ sizeof ("hello")];
         strcpy(str, "hello");
         f(str);
         cout<< str;
    int a[10];
    for(int i = 0 ; i < 10 ; ++i) cin>>a[i];
    int x;
    if(Find2thMaxNum(a, 10, x)) cout<<"second max:"<<x<<endl;
    else cout<<"no second max!"<<endl;
    return 0;
}
