#include<stdio.h>
#define false 0
#define true 1
const int Max = 129;
int check(char* str)
{
    if(str==NULL) return false;
    if(str[0] <= 'Z' && str[0] >= 'A')
    {
        char* p = str + 1;
        while(*p)
        {
            if(*p <= 'Z' && *p >= 'A') return false;
            ++ p;
        }
        return true;
    }
    else return false;
}

int main()
{
    char str[Max];
    gets(str);
    //while(gets(str))
    //{
        if(check(str)) printf("true\n");
        else printf("false\n");
    //}
    return 0;
}
