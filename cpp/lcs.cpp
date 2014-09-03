#include<iostream>
#include<string.h>
using namespace std;

int longest_common_substring(char *query, char *text)
{
	int max_len = -1;
	int len1 = strlen(query);
	int len2 = strlen(text);
	int* len_arr = new int[len2];
	for(int i = 0; i < len2; ++i)
    {
        len_arr[i]= (query[0]==text[i])?1:0; //��query[0]==text[i]���������ʼ����������
        max_len = max(max_len , len_arr[i]);
    }

	for(int i = 1 ; i < len1 ; ++i)//����query
	{
	    int store = len_arr[0];//����һ���������Խ���������Ӷ�ά��Ϊһά
	    len_arr[0] = (query[i]==text[0])?1:0;
		for(int j = 1; j < len2; ++j)
		{
		    int tmp = len_arr[j];
			len_arr[j] = (query[i] == text[j])?(store+1):0;
			max_len=max(max_len, len_arr[j]);
			store = tmp;
		}
	}
	delete [] len_arr;
	return max_len;
}

int longest_common_substring2(char *str1, char *str2)
{
	int i,j,k,len1,len2,max,x,y;
	len1 = strlen(str1);
	len2 = strlen(str2);
	int **c = new int*[len1+1];
	for(i = 0; i < len1+1; i++)
		c[i] = new int[len2+1];
	for(i = 0; i < len1+1; i++)
		c[i][0]=0;        //��0�ж���ʼ��Ϊ0
	for(j = 0; j < len2+1; j++)
		c[0][j]=0;        //��0�ж���ʼ��Ϊ0
	max = -1;
	for(i = 1 ; i < len1+1 ; i++)
	{
		for(j = 1; j < len2+1; j++)
		{
			if(str1[i-1]==str2[j-1])     //ֻ��Ҫ�����Ϸ���c[i-1][j-1]�ȽϾͿ�����
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=0;
			if(c[i][j]>max)
			{
				max=c[i][j];
				x=i;
				y=j;
			}
		}
	}
	for(i = 0; i < len1+1; i++)         //�ͷŶ�̬����Ķ�ά����
		delete[] c[i];
	delete[] c;
	return max;
}
int main()
{
    char str1[50], str2[50];
    while(cin>>str1>>str2)
    {
        cout<<longest_common_substring(str1, str2)<<endl;
    }
    return 0;
}
