//hdj3294,203MS	1676K	1823 B	G++
//longest sub plalindrome，Manacher算法
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
void LongestSubPlalindrome(int& mid, int& len)
{
    int mx = 0, id ;
    len = 0;
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
        if(p[i] > len)
        {
            len = p[i];
            mid = i;
        }
    }
    --len;
}

int main()
{
    char real_char[1] ;//转换字符，输出时做映射real_char->a
    while(scanf("%s %s", real_char, str)!=EOF)
    {
        preprocess();
        int len = 1, mid = 1;
        LongestSubPlalindrome(mid, len);
        if(len > 1)
        {
            //cout<<"mid:"<<mid<<"  len:"<<len<<endl;
            int low = mid - len + 1, high = mid + len - 1;
            cout<<((low-2)>>1)<<" "<<((high-2)>>1)<<endl;
            while(low <= high)
            {
                if(str[low] != '#')
                {
                    str[low] = 'a' + ((str[low] - 'a') - (real_char[0] - 'a') + 26)%26;
                    cout<<str[low];
                }
                ++low;
            }
            cout<<endl;
        }
        else cout<<"No solution!"<<endl;

    }
    return 0;
}
