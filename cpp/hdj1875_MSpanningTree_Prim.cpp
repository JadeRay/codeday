//hdj1875，78MS	452K	2715 B	G++
//minimun spanning tree
//算法从待选的顶点中选择权值最小的顶点时，使用的是遍历，故而复杂度为O(n^2)
/*
input:
    T
    n1
    a1 b1
    a2 b2
    .....
    a[n1] b[n1]
    n2
    ...
    ...
description:
    T:测试组数
    n1:顶点数
    ai bi ：顶点坐标
距离小于10或大于1000的顶点认为是不可达的
*/
#include<iostream>
#include<cmath> //for sqrt
#include<iomanip> // for setprecision(1)
#define MaxVertex 101

using namespace std;
const double INF = (double)99999999;
typedef struct
{
    int x, y;
}Point;

Point vertexes[MaxVertex];
double graph[MaxVertex][MaxVertex];
bool visited[MaxVertex];

double dist(Point a, Point b)
{
    int x = abs(a.x - b.x);
    int y = abs(a.y - b.y);
    return sqrt((double)(x * x + y * y));
}

void genGraph(int num_of_vertex)
{
        for(int i = 0 ; i < num_of_vertex ; ++i)
        {
            graph[i][i] = 0;
            for(int j = i+1 ; j < num_of_vertex ; ++j)
            {
                double d = dist(vertexes[i], vertexes[j]);
                if(d < 10 || d > 1000) graph[i][j] = graph[j][i] = INF;//-1 means unreachable
                else
                {
                    graph[i][j] = graph[j][i] = d;
                }

            }
        }
}
double MST_Prim(int num_of_vertex)
{
    //设MST顶点集合为V，U=G-V
    double* adj = new double[num_of_vertex];
    //visited[i] = false && adj[i]表示i∈U且i到V中顶点最短的距离为adj[i]
    for(int i = 0 ; i < num_of_vertex ; ++i)
    {
        visited[i] = false;
        adj[i] = graph[i][0];
    }
    visited[0] = true;//添加第一个顶点到V中
    double len = 0.0;//MST总长度
    for(int i = 0 ; i < num_of_vertex ; ++i)
    {
        double nlen = INF;
        int u = 0;
        //从U中选择adj最小的顶点记为u
        for(int j = 0 ; j < num_of_vertex ; ++j)
        {
            if(!visited[j] &&  adj[j] < nlen)
            {
                nlen = adj[j];
                u = j;
            }
        }
        if(u == 0) break;//u=0表示在U中没有找到距离V最短的点，直接退出循环
        visited[u] = true;
        len += nlen;
        //由于u新添加到V中，所以刷新U中各顶点与V中各顶点的距离
        //这里不需要两次遍历，因为V中只多了一个u，只刷新U中各顶点与u的距离即可
        for(int j = 0 ; j < num_of_vertex ; ++j)
        {
            if(!visited[j] &&  graph[j][u] < adj[j]) adj[j] = graph[j][u];
        }
    }
    delete [] adj;
    for(int i = 0 ; i < num_of_vertex ; ++i)
        if(!visited[i]) return -1; //存在未被访问的节点，表明不是连通图
    return len;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int num_of_vertex;
        cin>>num_of_vertex;
        for(int i = 0 ; i < num_of_vertex ; ++i) cin>>vertexes[i].x>>vertexes[i].y;
        genGraph(num_of_vertex);
        double len = MST_Prim(num_of_vertex);
        if(len < 0) cout<<"oh!"<<endl;
        else cout<<setiosflags(ios::fixed)<<setprecision(1)<<100*len<<endl;
    }

    return 0;
}
