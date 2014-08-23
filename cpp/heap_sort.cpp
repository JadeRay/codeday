#include <iostream>
#include <ostream>
#include <iomanip>
namespace heap_sort{

	template<class valueType, int Size = 25>
		class HeapSort
		{
		private:
			valueType* _nValue;	//未排序的堆，第一个元素未用

			int		nMaxSize;	//数组最大长度
			int		heap_size;	//heap_size永远指向最后一个元素

#define LEFT(i) i<<1
#define RIGHT(i) (i<<1)+1
#define PARENT(i) i>>1
#define random(x) (rand()%x) 

			void swap(valueType& _value1, valueType& _value2)
			{
				valueType* _tmpV = new valueType;
				memcpy(_tmpV, &_value1, sizeof(valueType));
				memcpy(&_value1, &_value2, sizeof(valueType));
				memcpy(&_value2, _tmpV, sizeof(valueType));
				delete _tmpV;
			}

			void max_heapify(int i)
			{
				int left =  LEFT(i), right = RIGHT(i);
				int largest;
				if(left <= heap_size && _nValue[left] > _nValue[i]) largest = left;
				else largest = i;
				if(right <= heap_size && _nValue[right] > _nValue[largest]) largest = right;
				if(largest != i)
				{
					swap(_nValue[i], _nValue[largest]);   
					max_heapify(largest);
				}
			}

		public:
			HeapSort()
			{
				nMaxSize = Size;
				heap_size = 0;
				_nValue = new valueType[nMaxSize + 1];

			}
			HeapSort(valueType* arr, int arrSize = Size)
			{
				nMaxSize = Size;
				heap_size = arrSize;
				_nValue = new valueType[nMaxSize + 1];
				memcpy(_nValue + 1, arr, arrSize*sizeof(valueType));

			}
			~HeapSort()
			{
				if (_nValue)
				{
					delete [] _nValue;
					_nValue = NULL;
				}

			}
			void build_max_heap()
			{
				for(int i = heap_size>>1 ; i >= 1 ; --i)
				{
					max_heapify(i); 
				}     

			}

			void heap_sort()
			{

				build_max_heap();
				int nSize = heap_size;
				for(int i = heap_size ; i >= 2 ; --i)
				{
					swap(_nValue[i], _nValue[1]);
					--heap_size;
					max_heapify(1);     
				}
				heap_size = nSize;
			}

			void heap_increase_key(int i, int key)
			{
				if(key < _nValue[i]) return;
				_nValue[i] = key;
				while(i > 1 && _nValue[PARENT(i)] < _nValue[i])
				{
					swap(_nValue[i], _nValue[PARENT(i)]);
					i = PARENT(i);        
				}     
			}

			void heap_insert(int key)
			{
				++ heap_size;
				_nValue[heap_size] = key - 1;
				heap_increase_key(heap_size, key);    
			}

			int heap_maximum()
			{
				return _nValue[1];  
			}

			typedef void (*printFun)(const valueType& v);

			void printHeap(printFun fun)
			{
				for (int i = 1; i <= heap_size ; ++i)
				{
					fun(_nValue[i]);
					std::cout<<endl;
				}
				std::cout<<endl;
			}
		};
}
using namespace std;
void printInt(const int& n)
{
	cout<<n;
}

int main()
{
	using namespace heap_sort;
	

	HeapSort<int> heap;

	int n;
	cout<<"input max num:";
	cin>>n;

	for (int i = 0 ; i < n ; ++i)
	{
		int num;
		cout<<"input "<<i+1<<" num:";
		cin>>num;
		heap.heap_insert(num);
	}

	heap.printHeap(printInt);

	heap.heap_sort();

	heap.printHeap(printInt);


	system("pause");
	return 0;
}