//dictionary tree��ǰ׺�����洢��ʽ��ÿһ����ֵܽڵ��γɵ��������ڵ�ָ������ı�ͷ
//1247	171MS	2140K	3237 B	G++
//����һ���ַ�����Ҫ�������Щ�������������������ַ�����϶��ɵ��ַ���
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

typedef struct node
{
   char value;
   int nCount;
   bool isWord;    //to extend
   struct node* fChild;
   struct node* brother;
   node():nCount(0), isWord(false), fChild(NULL), brother(NULL){}
   ~node()
   {
       if(fChild) delete fChild;
       fChild = NULL;
       if(brother) delete brother;
       brother = NULL;
   }
}node;

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
    bool findInLevel(node* q, node** now, char ch)
    {
       node* p = q;
       while(p)
       {
               *now = p ;
               if(p->value != ch) p = p->brother;
               else return true;
       }
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

    void insert(char* str, int freq)
    {

    }
    void insert(char* str)
    {
        _insert(Tree, str);
    }
//���봴���ֵ�����ǰ׺����
    void _insert(node* root, char* str)
    {
        int i = 0;
        struct node* pNowLevel = root;
        while(i < strlen(str))
        {
             node* now = NULL;
             if(!findInLevel(pNowLevel->fChild, &now, str[i]))
             {
                 node* pNode = new node();
                 if(now) now->brother = pNode;
                 else pNowLevel->fChild = pNode;
                 pNode->value = str[i];
                 now = pNode;
             }
             if(i == strlen(str)-1) now->isWord = true;
             pNowLevel = now;
             i++;
        }
    }
};


int main()
{

    int scenario;
    Trie tree;
    cin>>scenario;
    for(int i = 1 ; i <= scenario ; ++i)
    {
        int n;
        cin>>n;
        for(int j = 1; j <= n ; ++j)
        {
            char word[26];
            int freq;
            cin>>word>>freq;

        }
    }
    vector<string> data;
    while(scanf("%s", word)!=EOF)
    {
           tree.insert(word);
           data.push_back(string(word));
    }

    return 0;
}
