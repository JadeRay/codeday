/*
内存中有一个长数组，条目数为10万，数组单元为结构体struct array，sizeof(struct array)为512字节。
结构有一int型成员变量weight。现需要取得按weight值从大到小排序的前500个数组单元，
请实现算法，要求效率尽可能高
*/

#include <iostream>//for cout
#include <algorithm>//for make_heap, pop_heap
#include <cstdlib>//for rand
#include <vector>//for vector
#include <ctime>//for time
#include <iomanip>//for setw
using namespace std;

const int MaxW = 32768;
const int MaxN = 100000;
struct node
{
	int weight;
	int arr[511];
}data[MaxN];

typedef vector<int> NodeVec;//只存每个节点的下标即可，节约空间

//产生数据
void GenData()
{
	srand((int)time(0));
	for(int i = 0 ; i < MaxN ; ++i)
	{

		data[i].weight = rand()%MaxW;
	}
}

void print(int i)
{
    static int index = 0;
    cout<<setw(7)<<data[i].weight;
    if(++index%10 == 0) cout<<endl;
}
//这样设计并不规范，因为compare中出现的data定义在外部
//但是这样有利于配合NodeVec的定义，节省空间
class compare:public binary_function < int, int, bool >
{
public:
	bool operator()(int& i, int& j) const
	{
		return data[i].weight > data[j].weight;//为了获得小顶堆，逆序排列
	}
};
void GetkMax(NodeVec& rtv, int k)
{
	int i ;
	for( i = 0 ; i < k ; ++i) rtv.push_back(i);
	make_heap(rtv.begin(), rtv.end(), compare());
	while(i < MaxN)
	{
		if(compare()(i, rtv[0]))
		{
			pop_heap(rtv.begin(), rtv.end(), compare());
			rtv.pop_back();
			rtv.push_back(i);
			push_heap(rtv.begin(), rtv.end(), compare());
		}
		++i;
	}
}
int main()
{
	NodeVec kmax;
	kmax.reserve(600);
	int k = 500;
	GenData();
	GetkMax(kmax, k);
	for_each(kmax.begin(), kmax.end(), print); //输出是按照堆的顺序输出，如果要有序的话，可以先sort_heap一下
    cout<<endl;
	return 0;
}
