//hdj1874, AC��0MS	400K	2234 B
//�����Ҫע����Ǵ�һ�����㵽��һ��������ܴ��ڶ���·��
//���Գ�ʼ����ʱ��ȡ��Сֵ
//ͬʱӦ��ע������������ͼ

#include <iostream>
#define INF 9999999
#define MaxN 200

using namespace std;
//���ڽӾ�������ʾͼ
int c[MaxN][MaxN];
bool sq[MaxN];  //�ѷ��ʽڵ��ϣ�ΪTRUE��ʾ�ѷ���
int dist[MaxN];


//�����㷨ͨ���������ж������ҵ�������S���ϵ���С����
int Dijkstra_SSSP(int n, int source, int dest)
{

     for(int i = 0 ; i < n ; ++i)
     {
             dist[i] = c[source][i];
             sq[i] = false;
     }
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
                               }
                     }
             }
     }
     return dist[dest];
}


int main()
{
    int n, m;//n������, m����
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
