//single-source shortest path
//Dijkstra Algorithm
//û��ʹ��С������ѡ�񶥵㣬ֱ�ӱ������㣬ʱ�临�Ӷ�O(n^2)
//�ö���ʵ�ֵ��鷳�ط����ڴӶ����ҵ��ڽӵ㲢�ɳ�
//�����ڲ�����Ȩֵ��ͼ
//���ݽṹ���ڽӾ���
/*
Input: n m
       a1 b1 c1
       a2 b2 c2
       ........
       am bm cm
       s d
Description:
        n:��������� m���ߵĸ���
        ai->bi�ıߵ�ȨֵΪci���ߵı�Ŵ�0~n
        s��Դ�㣬d��Ŀ�Ķ���


*/
#include <iostream>
#define INF 99999
#define MaxN 20

using namespace std;
//���ڽӾ�������ʾͼ
int c[MaxN][MaxN];

//�����㷨ͨ���������ж������ҵ�������S���ϵ���С����
int Dijkstra_SSSP(int n, int source, int dest, int* dist, int* prev)
{
     bool sq[n+1];  //�ѷ��ʽڵ��ϣ�ΪTRUE��ʾ�ѷ���
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
     for(int i = 1 ; i < n ; ++i)//�ܹ�Ҫ��ʣ��n-1��������뵽����S�У�Ҳ������sq��
     {
             int temp = INF;
             int u = source;
             //�ҵ� V-S �У�ʣ��ڵ㣩dist��С�Ķ���
             for(int j = 0; j < n; ++j)
             {
                     //s[j] = false �Ƕ��� j ��V-S�е�һ���ж�����
                     if((sq[j]==false) && (dist[j] < temp))
                     {
                                u = j;
                                temp = dist[j];
                     }
             }
             sq[u] = true;  //��u��ӵ����㼯��S��
             //�ɳ� V-S �� u �ɴ�Ķ���
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
    int n;//������
    while(cin>>n && n)
    {
        for(int i = 0 ; i < n; ++i)
           for(int j = 0; j < n; ++j) c[i][j] = INF;
        int m;
        cin>>m;//����
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
