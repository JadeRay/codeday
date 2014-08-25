//heap sort
#include <iostream>
#define LEFT(i) i<<1
#define RIGHT(i) (i<<1)+1
#define PARENT(i) i>>1
#define random(x) (rand()%x)
using namespace std;



int heap_size;
int a[20];
void swap(int* a, int* b)
{
     int tmp = *a;
     *a = *b;
     *b = tmp;     
}
void MAX_HEAPIFY(int* a, int i)
{
     int left =  LEFT(i), right = RIGHT(i);
     int largest;
     if(left <= heap_size && a[left] > a[i]) largest = left;
     else largest = i;
     if(right <= heap_size && a[right] > a[largest]) largest = right;
     if(largest != i)
     {
         swap(&a[i], &a[largest]);   
         MAX_HEAPIFY(a, largest);
     }
}

void BUILD_MAX_HEAP(int* a)
{
    for(int i = heap_size>>1 ; i >= 1 ; --i)
    {
            MAX_HEAPIFY(a, i); 
    }     
     
}

void HEAP_SORT(int* a)
{
    BUILD_MAX_HEAP(a);
    for(int i = heap_size ; i >= 2 ; --i)
    {
            swap(&a[i], &a[1]);
            --heap_size;
            MAX_HEAPIFY(a, 1);     
            
    }
}

void HEAP_INCREASE_KEY(int* a, int i, int key)
{
     if(key < a[i]) return;
     a[i] = key;
     while(i > 1 && a[PARENT(i)] < a[i])
     {
          swap(&a[i], &a[PARENT(i)]);
          i = PARENT(i);        
     }     
}

void HEAP_INSERT(int* a, int key)
{
     ++heap_size;
     a[heap_size] = key;
     int i = heap_size;
     while(i > 1 && a[PARENT(i)] < a[i])
     {
          swap(&a[i], &a[PARENT(i)]);
          i = PARENT(i);        
     }            
}

int HEAP_MAXIMUM(int* a)
{
    return a[1];  
}

int main()
{
    heap_size = 10;
    srand((int)time(0));
    for(int i = 1 ; i <= heap_size ; ++i) a[i] = random(100);
    cout<<"unsorted a:"<<endl;
    for(int i = 1 ; i <= heap_size ; ++i) cout<<a[i]<<"   ";
    cout<<endl;
    int n = heap_size;
    HEAP_SORT(a);
    heap_size = n;
    cout<<"sorted a:"<<endl;
    for(int i = 1 ; i <= heap_size ; ++i) cout<<a[i]<<"   "; 
    cout<<endl;   
    
    system("pause");
    return 0;   
}
