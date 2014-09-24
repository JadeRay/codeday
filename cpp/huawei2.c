#include<stdio.h>
#include<stdlib.h>//for qsort
const int Max = 10;

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
void reorder(int* arr, int n)
{
    int s1[n], s2[n];
    int index1 = 0, index2 = 0 ;

    int i;
    for(i = 0 ; i < n ; ++i)
    {
        if(arr[i] & 0x01) s1[index1 ++] = arr[i];
        else s2[index2 ++] = arr[i];
    }
    qsort(s1, index1, sizeof(int), cmp);
    qsort(s2, index2, sizeof(int), cmp);
    int max_index = index1>index2?index1:index2;
    for(i = 0 ; i < max_index ; ++i)
    {
        if(i < index1) printf("%d ", s1[i]);
        else i<max_index-1?printf("0 "):printf("\n");
        if(i < index2) printf("%d ", s2[i]);
        else i<max_index-1?printf("0 "):printf("\n");
    }
}

int main()
{
    int arr[Max];
    int i;
    for(i = 0 ; i < Max ; ++i) scanf("%d", &arr[i]);
    reorder(arr, Max);
    return 0;
}
