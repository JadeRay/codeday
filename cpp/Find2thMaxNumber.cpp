//找整形数组中第二大的数
//说明：第二大的数应该是数值上第二大的，如果数组全部等值，则没有第二大的数
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
