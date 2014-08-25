// minimum spanning tree
// hdj1232 
//kruskal
//515MS	448K	1757 B
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define Max 5000
using namespace std;
struct Node{
       int v1, v2;
       int edg;
       //升序用 
       bool operator<(const Node& node) const
       {
            return edg < node.edg;
       }
       //降序用
       bool operator>(const Node& node) const
       {
            return edg > node.edg;
       }
};
int find(int id[],  int p)
{
    while( p != id[p] )
    {
           id[p] = id[id[p]];
           p = id[p];       
    }
    return id[p];   
}       
void merge(int id[], int p, int q)
{
    if( id[p] == id[q] ) return;
    
    id[p] = id[q];    
    
}

int main()
{

    int n;
    int id[Max];
    while(cin>>n && n)
    {
        int m = n*(n-1)/2;
        int i;
        for( int i = 1 ; i <= m ; i++ ) id[i] = i ;
        vector<struct Node> vec;
        for(  i = 1 ; i <= m ; i++ )
        {
            int x, y, w;
            cin>>x>>y>>w;
            struct Node node;
            node.v1 = x;
            node.v2 = y;
            node.edg = w;
            vec.push_back(node);
        }
        sort(vec.begin(), vec.end());

        vector<struct Node>::iterator it;
        int cnt = 0 ;
        int sum = 0 ;
        for( it = vec.begin() ; it != vec.end() && cnt != n-1; it++ )
        {
             int v1 = (*it).v1, v2 = (*it).v2;
             int r1 = find(id, v1), r2 = find(id, v2);
             if( r1 != r2 )
             {
                 merge(id, r1, r2);
                 sum+= (*it).edg;
                 cnt++;
             } 
        }  
        cout<<sum<<endl;      
                 
    }   
    
    
}       
