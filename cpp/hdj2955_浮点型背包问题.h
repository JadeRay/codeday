//hdj 2955, knapsack problem
//�����ͱ�������
#include <iostream>

using namespace std;
#define MaxN 101
#define MaxNode 300       
int value[MaxN];//money
float cost[MaxN];//probability
struct node{
      float x;  
      int y;
}JumpNode[MaxNode];

void Traceback(int n, int* head, int x[] )
{
    float j = JumpNode[head[0]-1].x ;
    int m = JumpNode[head[0]-1].y;
    for(int i = 1 ; i <= n ; i++)
    {
        x[i] = 0 ;
        for(int k = head[i+1] ; k <= head[i]-1 ; k++)
        {
             if(JumpNode[k].x + cost[i] == j && JumpNode[k].y + value[i] == m)
             {
                   x[i] = 1; j = JumpNode[k].x ; m = JumpNode[k].y; break;
             }
        }
    }                      
}

int Knapsack(int n, float pMax )
{
   JumpNode[0].x = 0 ;
   JumpNode[0].y = 0 ;
   int left = 0, right = 0, next = 1;
//   int* head = new int[n+2];
//   int* rx = new int[n+2];
//   head[n] = 1;
   for(int i = n ; i >= 1 ; i--)
   {
      int k = left;     
      for(int j = left ; j <= right ; j++)
      {   
          if( JumpNode[j].x + cost[i] > pMax) break;
          float x = JumpNode[j].x + cost[i];
          int y = JumpNode[j].y + value[i];  
          while(k<=right && JumpNode[k].x < x)
          //��֮ǰ��Ծ�㼯��С�ڸõ㣨λ�ڸõ���ߣ��Ľ�㿽�����µ���Ծ�㼯�� 
          {
               JumpNode[next].x = JumpNode[k].x ;
               JumpNode[next++].y = JumpNode[k++].y;
          }
          if(k<= right && JumpNode[k].x == x)
          //��xֵ��ͬ����Ծ�㣬ȡ��yֵ����һ�� 
          {
               if(y < JumpNode[k].y ) y = JumpNode[k].y;
               k++;       
          }        
          if(y > JumpNode[next-1].y)
          //����x,y����ӵ���ǰ��Ծ�㼯��ĩβ 
          {
               JumpNode[next].x = x;
               JumpNode[next++].y = y;
          }
          //�ҵ�ԭ��Ծ�㼯�бȣ�x,y�����ߵ���Ծ�� 
          while(k<=right && JumpNode[k].y <= JumpNode[next-1].y) k++;  
      }
      while(k <= right)
      {
          JumpNode[next].x = JumpNode[k].x;
          JumpNode[next++].y = JumpNode[k++].y;
      }
      left = right+1;
      right = next-1;
//      head[i-1] = next;    
//
//      cout<<"JumpNode when adding:("<<cost[i]<<","<<value[i]<<")"<<endl;
//      for(int k = left ; k <= right ; k++)
//        cout<<"("<<JumpNode[k].x<<","<<JumpNode[k].y<<")  ";
//      cout<<endl; 
          
    } 
    return JumpNode[next-1].y ;           
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       float pMax;
       int n;
       //memset(JumpNode, 0, MaxNode*sizeof(JumpNode));
       cin>>pMax>>n;
       
       for(int i = 1 ; i <= n; i++) cin>>value[i]>>cost[i];
      // for(int i = 0 ; i < MaxNode ; i++) JumpNode[i].x = 0, JumpNode[0].y = 0 ;
       cout<<Knapsack(n, pMax)<<endl;
                 
    }
    system("pause");
    return 0;   
}
