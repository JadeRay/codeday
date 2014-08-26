//归并排序算法
//作者：钱玉磊(2013/2/28)
//只需要输入数组长度以及数组中数据大小的上界
//数组元素由随机数生成 
//输出排序前的数组，排序后的数组，排序用时 

#include<iostream>
#include<vector>
#include<time.h>
#include<iomanip>

using namespace std;
void InSort(int* A,int low,int high);
void Merge(int* A,int low,int mid,int high);
void MergeSort(int* A,int low,int high);

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
	MergeSort(A,0,array_lenth-1);
	cout<<endl<<"The sorted array:"<<endl;
	for( i = 0 ; i < array_lenth ; i++ ){
		cout<<setw(4)<<A[i]<<"  ";
		if( (i+1) % 10 == 0 ) cout<<endl;
	}
	finish = clock() ;
	cout<<endl<<"数组大小:"<<array_lenth<<endl;
	cout<<"耗时："<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;	
	system("pause");
	return 0;
}

void MergeSort(int* A,int low,int high){
	if( high-low+1 < 16 ){
		InSort(A,low,high);
	}else{
		int mid = (high+low)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}

}

void Merge(int* A,int low,int mid,int high){
	vector<int> Temp;
	int p = low ,q = mid+1;
	
	while( p <= mid && q <= high ){
		if( A[p] < A[q] ){
			Temp.push_back(A[p]);
			p++;
		}else{
			Temp.push_back(A[q]);
			q++;
		}
	}
	
	for( ; p <= mid ; p++)	Temp.push_back(A[p]);
	for( ; q <= high ; q++)	Temp.push_back(A[q]);
	vector<int>::iterator iter = Temp.begin();
	
	for( p = low ; iter != Temp.end() ; ++iter ){
		A[p] = *iter;
		p++;
    }
    
}


void InSort(int* A,int low,int high){
	int i;
	for( i = low+1 ; i <= high ; i++ ){
		int t = A[i];
		int j;
		for( j = i-1 ; j >=low && A[j] > t ; j-- ){
			A[j+1] = A[j];
		}
		A[j+1] = t;
	}
}
