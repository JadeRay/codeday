//hdj1875��78MS	452K	2715 B	G++
//minimun spanning tree
//�㷨�Ӵ�ѡ�Ķ�����ѡ��Ȩֵ��С�Ķ���ʱ��ʹ�õ��Ǳ������ʶ����Ӷ�ΪO(n^2)
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
    T:��������
    n1:������
    ai bi ����������
����С��10�����1000�Ķ�����Ϊ�ǲ��ɴ��
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
    //��MST���㼯��ΪV��U=G-V
    double* adj = new double[num_of_vertex];
    //visited[i] = false && adj[i]��ʾi��U��i��V�ж�����̵ľ���Ϊadj[i]
    for(int i = 0 ; i < num_of_vertex ; ++i)
    {
        visited[i] = false;
        adj[i] = graph[i][0];
    }
    visited[0] = true;//��ӵ�һ�����㵽V��
    double len = 0.0;//MST�ܳ���
    for(int i = 0 ; i < num_of_vertex ; ++i)
    {
        double nlen = INF;
        int u = 0;
        //��U��ѡ��adj��С�Ķ����Ϊu
        for(int j = 0 ; j < num_of_vertex ; ++j)
        {
            if(!visited[j] &&  adj[j] < nlen)
            {
                nlen = adj[j];
                u = j;
            }
        }
        if(u == 0) break;//u=0��ʾ��U��û���ҵ�����V��̵ĵ㣬ֱ���˳�ѭ��
        visited[u] = true;
        len += nlen;
        //����u����ӵ�V�У�����ˢ��U�и�������V�и�����ľ���
        //���ﲻ��Ҫ���α�������ΪV��ֻ����һ��u��ֻˢ��U�и�������u�ľ��뼴��
        for(int j = 0 ; j < num_of_vertex ; ++j)
        {
            if(!visited[j] &&  graph[j][u] < adj[j]) adj[j] = graph[j][u];
        }
    }
    delete [] adj;
    for(int i = 0 ; i < num_of_vertex ; ++i)
        if(!visited[i]) return -1; //����δ�����ʵĽڵ㣬����������ͨͼ
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
