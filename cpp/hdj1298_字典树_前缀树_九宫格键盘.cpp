//dictionary tree��ǰ׺�����洢��ʽ��ÿһ����ֵܽڵ��γɵ��������ڵ�ָ������ı�ͷ
//1247	171MS	2140K	3237 B	G++
//����һ���ַ�����Ҫ�������Щ�������������������ַ�����϶��ɵ��ַ���
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MaxWordLen = 100 + 1;
char tel[8][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int press[MaxWordLen] ;
char output[MaxWordLen];

int num(char ch)
{
    for(int i = 0 ; i < 8 ; ++i)
    {
        for(int j = 0 ; j < 5 ; ++j)
        {
            if(tel[i][j] == ch) return i+1;
        }
    }
    return 0;
}
typedef struct node
{
   char value;
   int nCount;
   bool isWord;    //to extend
   node* fChild;
   node* brother[MaxWordLen];
   int brotherSize;
   node():nCount(0), isWord(false), fChild(NULL), brotherSize(0){}
   node(char ch, int freq):nCount(freq), isWord(false), fChild(NULL), brotherSize(0), value(ch){}
   ~node()
   {
       if(fChild) delete fChild;
       fChild = NULL;
       for(int i = 0 ; i < brotherSize ; ++i) delete brother[i];
   }
}node;

bool compare(const node* p1, const node* p2)
{
    return p1->nCount > p2->nCount;  //��������ĳ�С�ںţ�������
}

class Trie
{
public:
    node* Tree;
    Trie():Tree(new node()){}

    ~Trie()
    {
        if(Tree)
        {
            delete Tree;
        }
        Tree = NULL;
    }
    void clear()
    {
        if(Tree->fChild)
        {
            delete Tree->fChild;
            Tree->fChild = NULL;
        }
    }

//��ĳһ���в��Ҹ����ַ��ĳ������
//���֣��򷵻�TRUE��ͬʱnowָ����ָ��ַ��Ľڵ�
//�����֣��򷵻�FALSE��ͬʱnowָ�򱾲�����һ���ڵ㣨���ڽ����ַ����뵽�������
//���nowΪnull��������ò���û�нڵ�
//rootΪ��ǰ�㸸�ڵ�
    bool findInLevel(node* root, node** now, char ch)
    {
        if(!root || !root->fChild) return false;
        root = root->fChild;
        if(root->brotherSize == 0)
        {
            return false;
        }
        for(int i = 0 ; i < root->brotherSize ; ++i)
        {
            if(root->brother[i]->value == ch)
            {
                *now = root->brother[i];
                return true;
            }
        }
        *now = root->brother[root->brotherSize-1];
        return false;
    }
 //�����Ը����ַ���Ϊǰ׺���ַ����ĸ���
    bool isWord(const char* str)
    {
        int i = 0 ;
        node* now = NULL;
        node* root = Tree;
        while(i<strlen(str) && root)
        {
            if(!findInLevel(root->fChild, &now, str[i])) return false;
            i++;
            root = now;
        }
        if(i>=strlen(str) ) return root->isWord;
        else return false;
    }
    //�߼��������⣬��Ҫ���¿���
    void insert(char* str, int freq)
    {
        int i = 0;
        node* pNowLevel = Tree;
        while(i < strlen(str))
        {
             node* now = NULL;
             if(!findInLevel(pNowLevel, &now, str[i]))
             {
                 node* pNode = new node(str[i], freq);
                 if(now) pNowLevel->fChild->brother[pNowLevel->fChild->brotherSize ++] = pNode;
                 else pNowLevel->fChild = pNode;
                 now = pNode;
             }
             else
             {
                 now->nCount += freq;
             }
             if(i == strlen(str)-1) now->isWord = true;
             pNowLevel = now;
             ++i;
        }
    }

    void find(int len)
    {
        memcpy(output, 0, sizeof(char)*MaxWordLen);
        int  pout = 0;
        bool isFind = false;
        for(int i = 0;i < len; ++i)
        {
            if(_find(Tree->fChild, 0, len, pout))
            {
                isFind = true;
                break;
            }
        }
        if(isFind) cout<<output<<endl;
        else cout<<"MANUALLY"<<endl;
    }

    bool _find(node* nowLevel, int index, int len, int pout)
    {
        if(nowLevel == NULL && index < len) return false;
        if(index >= len) return true;
        sort(nowLevel->brother, nowLevel->brother + nowLevel->brotherSize, compare);
        for(int i = 0; i < nowLevel->brotherSize ; ++i)
        {
            output[pout] = nowLevel->brother[i]->value;
            if(num(nowLevel->brother[i]->value) == press[index])
            {
                if(_find(nowLevel->brother[i]->fChild, ++index, len, ++pout))  return true;
            }
        }
        return false;
    }
};



int main()
{

    int scenario;
    Trie tree;
    cin>>scenario;
    for(int i = 1 ; i <= scenario ; ++i)
    {
        tree.clear();
        cout<<"Scenario #"<<i<<":"<<endl;
        int n;
        cin>>n;
        for(int j = 1; j <= n ; ++j)
        {
            char word[26];
            int freq;
            cin>>word>>freq;
            tree.insert(word, freq);
        }
        int m;
        cin>>m;
        int len = 0 ;
        while(cin>>press[len] && press[len] != 1) ++len;
        for(int j = 0 ; j < len ; ++j) tree.find(j+1);
    }



    return 0;
}
