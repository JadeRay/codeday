//hdj1874, AC，0MS	400K	2234 B
//这道题要注意的是从一个顶点到另一个顶点可能存在多条路径
//所以初始化的时候取最小值
//同时应该注意这题是无向图

#include <iostream>
#define INF 9999999
#define MaxN 200

using namespace std;
//用邻接矩阵来表示图
int c[MaxN][MaxN];
bool sq[MaxN];  //已访问节点结合，为TRUE表示已访问
int dist[MaxN];


//下面算法通过遍历所有顶点来找到待加入S集合的最小顶点
int Dijkstra_SSSP(int n, int source, int dest)
{

     for(int i = 0 ; i < n ; ++i)
     {
             dist[i] = c[source][i];
             sq[i] = false;
     }
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
                               }
                     }
             }
     }
     return dist[dest];
}


int main()
{
    int n, m;//n顶点数, m边数
    while(cin>>n>>m)
    {
        for(int i = 0 ; i < n; ++i)
           for(int j = 0; j < n; ++j) c[i][j] = INF;


        for(int i = 1; i <= m; ++i)
        {
             int x,y,z;
             cin>>x>>y>>z;
             if(z < c[x][y]) c[x][y] = c[y][x] = z;
        }
        int s, d;
        cin>>s>>d;
        if(s == d) cout<<"0"<<endl;
        else
        {
            Dijkstra_SSSP(n, s, d);
            if(dist[d] < INF)
            {
                cout<<dist[d]<<endl;
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }


    }
    return 0;
}
