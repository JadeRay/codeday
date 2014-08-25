//hdj3068
//longest sub plalindrome
#include<iostream>
#include<string.h>
using namespace std;

const int MaxLen = 2*110002;
const int MaxLen2 = 110002 ;
char str[MaxLen];
char s[MaxLen2];
void preprocess()
{
    int j = 2;
    int n = strlen(s);
    str[0] = '$';
    str[1] = '#';

    for(int i = 0 ; i < n ; ++i)
    {
        str[j++] = s[i];
        str[j++] = '#';
    }
    str[j] = '\0';
}

int main()
{
    while(cin>>s)
    {
        preprocess();
        cout<<str<<endl;
    }
    return 0;
}
