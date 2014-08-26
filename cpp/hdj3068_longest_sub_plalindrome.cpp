//hdj3068,265MS	1348K	986 B	G++
//longest sub plalindrome£¬ManacherËã·¨
#include<iostream>
#include<string.h>
#include<cstdio> //scanf
using namespace std;

const int MaxLen = 2*110002;
char str[MaxLen];
int p[MaxLen];
int n;
inline int min(int a, int b)
{
    return a<b?a:b;
}
inline int max(int a, int b)
{
    return a>b?a:b;
}
void preprocess()
{
    n = strlen(str);
    for(int i = n ; i >= 0 ; --i)
    {
        str[(i<<1)+2] = str[i];
        str[(i<<1)+1] = '#';
    }
    str[0] = '$';
    n = (n<<1)+1;
}
int LongestSubPlalindrome()
{
    int mx = 0, id ;
    int len = 0;
    for(int i = 1 ; i < n ; ++i)
    {
        if(mx > i) p[i] = min(p[(id<<1) - i], p[id] + id - i);
        else p[i] = 1;
        while(str[i + p[i]] == str[i - p[i]]) ++p[i];
        if(p[i] + i > mx)
        {
            mx = p[i] + i;
            id = i;
        }
        len = max(len, p[i]);
    }
    return len;
}

int main()
{
    while(cin>>str)
    {
        preprocess();
        cout<<LongestSubPlalindrome()-1;
        cout<<endl;

    }
    return 0;
}
