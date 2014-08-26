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
   //int nCount;
   bool isWord;    //to extend
   struct node* fChild;
   struct node* brother;
   node():isWord(false), fChild(NULL), brother(NULL){}
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
    char word[26];

    Trie tree;
    vector<string> data;
    while(scanf("%s", word)!=EOF)
    {
           tree.insert(word);
           data.push_back(string(word));
    }

    for(int i = 0 ; i < data.size() ; ++i)
    {
        string nowStr = data[i];
        if(nowStr.length() < 2) continue;
        string left, right;
        for(int j = 0 ; j < nowStr.length() ; ++j)
        {
            left = nowStr.substr(0, j+1);
            right = nowStr.substr(j+1, nowStr.length());
            if(tree.isWord(left.c_str()) && tree.isWord(right.c_str()))
            {
                cout<<nowStr<<endl;
                break;
            }
        }
    }
    return 0;
}
