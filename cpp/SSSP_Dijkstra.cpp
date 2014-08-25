//single-source shortest path
//Dijkstra Algorithm
//没有使用小顶堆来选择顶点，直接遍历顶点，时间复杂度O(n^2)
//用堆来实现的麻烦地方在于从堆中找到邻接点并松弛
//适用于不带负权值的图
//数据结构是邻接矩阵
/*
Input: n m
       a1 b1 c1
       a2 b2 c2
       ........
       am bm cm
       s d
Description:
        n:顶点个数， m：边的个数
        ai->bi的边的权值为ci，边的编号从0~n
        s：源点，d：目的顶点


*/
#include <iostream>
#define INF 99999
#define MaxN 20

using namespace std;
//用邻接矩阵来表示图
int c[MaxN][MaxN];

//下面算法通过遍历所有顶点来找到待加入S集合的最小顶点
int Dijkstra_SSSP(int n, int source, int dest, int* dist, int* prev)
{
     bool sq[n+1];  //已访问节点结合，为TRUE表示已访问
     for(int i = 0 ; i < n ; ++i)
     {
             dist[i] = c[source][i];
             sq[i] = false;
             if(dist[i] == INF) prev[i] = -1 ;
             else prev[i] = source;
     }
     prev[source] = -1;
     dist[source] = 0 ;
     sq[source] = true;
     for(int i = 1 ; i < n ; ++i)//总共要将剩余n-1个顶点加入到集合S中，也即数组sq中
     {
             int temp = INF;
             int u = source;
             //找到 V-S 中（剩余节点）dist最小的顶点
             for(int j = 0; j < n; ++j)
             {
                     //s[j] = false 是顶点 j 在V-S中的一个判断依据
                     if((sq[j]==false) && (dist[j] < temp))
                     {
                                u = j;
                                temp = dist[j];
                     }
             }
             sq[u] = true;  //将u添加到顶点集合S中
             //松弛 V-S 中 u 可达的顶点
             for(int j = 0; j < n; ++j)
             {
                     if((sq[j]==false) && (c[u][j] < INF))
                     {
                               if(dist[u] + c[u][j] < dist[j])
                               {
                                          dist[j] = dist[u] + c[u][j];
                                          prev[j] = u;
                               }
                     }
             }
     }
     return dist[dest];
}

void print_path(int* prev, int source, int dest)
{
    if(dest >= 0)
    {
        print_path(prev, source, prev[dest]);
        if(dest == source) cout<<dest;
        else cout<<"->"<<dest;
    }
}
int main()
{
    int n;//顶点数
    while(cin>>n && n)
    {
        for(int i = 0 ; i < n; ++i)
           for(int j = 0; j < n; ++j) c[i][j] = INF;
        int m;
        cin>>m;//边数
        for(int i = 1; i <= m; ++i)
        {
             int x,y,z;
             cin>>x>>y>>z;
             c[x][y] = z;
        }
        int s, d;
        while(cin>>s>>d)
        {
            int* dist = new int[n+1];
            int* prev = new int[n+1];
            Dijkstra_SSSP(n, s, d, dist, prev);
            if(dist[d] != INF)
            {
                cout<<"shortest pathlenth is:"<<dist[d]<<endl;
                cout<<"the shortest path is:";
                print_path(prev, s, d);
                cout<<endl;
            }
            else
            {
                cout<<"No shortest path from "<<s<<" to "<<d<<endl;
            }

            delete [] dist;
            delete [] prev;
        }
    }
    return 0;
}
