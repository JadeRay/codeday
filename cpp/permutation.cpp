//343MS	1592K	G++

#include<iostream>
#include<cstdio>
using namespace std;

//TLE
void permutation(int* arr, int n)
{
    int* visited = new int[n+1];
    for(int i = 1; i <= n; ++i) visited[i] = 0;
    bool first = true;
    for(int i = 1 ; i <= n ; ++i)
    {
            int t = i;
            while(visited[t]==0)
            {
                if(first)
                {
                    cout<<"("<<t;
                    first = false;
                }
                else cout<<" "<<t;
                visited[t] = 1;
                t = arr[t];
            }
            if(!first) cout<<")";
            first = true;
    }
    cout<<endl;
    delete [] visited;
}

void permutation1(int* arr, int n)
{
    bool first = true;
    for(int i = 1 ; i <= n ; ++i)
    {
            int t = i;
            while(arr[t]!=0)
            {
                if(first)
                {
                    cout<<"("<<t;
                    first = false;
                }
                else cout<<" "<<t;

                int tmp = t;
                t = arr[t];
                arr[tmp] = 0;
            }
            if(!first) cout<<")";
            first = true;
    }
    cout<<endl;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        int* arr = new int[n+1];

        for(int i = 1 ; i <= n ; ++i)
        {
            scanf("%d", &arr[i]);//一定要用scanf，数据量大时cin会超时
        }
        permutation1(arr, n);
        delete [] arr;

    }
    return 0;
}
