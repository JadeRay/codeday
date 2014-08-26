#include<iostream>
#include<time.h>
#include<iomanip>

using namespace std;
void QuickSort(int* A,int low,int high);
int main()
{
    clock_t start,finish;
    double duration ;
    start = clock() ;
    int array_lenth,upper_bound;
    cout<<"enter the lenth of array:";
    cin>>array_lenth;
    cout<<"enter the upper bound of the number:";
    cin>>upper_bound;
	int A[array_lenth],i;
	srand(time(NULL));
	for( i = 0 ; i < array_lenth ; i++ )
		A[i] = rand()%upper_bound;
	cout<<endl<<"The unsorted array:"<<endl;
	for( i = 0 ; i < array_lenth ; i++ ){
		cout<<setw(4)<<A[i]<<"  ";
		if( (i+1) % 10 == 0 ) cout<<endl;
	}
	QuickSort(A,0,array_lenth-1);
	cout<<endl<<"The sorted array:"<<endl;
	for( i = 0 ; i < array_lenth ; i++ ){
		cout<<setw(4)<<A[i]<<"  ";
		if( (i+1) % 10 == 0 ) cout<<endl;
	}
	finish = clock() ;
	cout<<"数组大小:"<<array_lenth<<endl;
	cout<<"耗时："<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
	system("pause");
	return 0;   
}
int Partition(int* A,int m,int n){
     int v = A[m] ;
     int i = m, j = n ;
     while( i <= j ){
            for( i = i+1 ; A[i] < v && i <= j ; i++ );
            for( ; A[j] >= v && j >= i ; j-- );
            if( i <= j ){
                int temp;
                temp = A[i] ; 
                A[i] = A[j] ;
                A[j] = temp;
            }
     }
     A[m] = A[j] ;
     A[j] = v ;
     return j;
     }
void QuickSort(int* A,int low,int high){   
     if( low < high ){
         int par_loc = Partition(A,low,high);
         QuickSort(A,low,par_loc);
         QuickSort(A,par_loc+1,high);
     }
}
     
