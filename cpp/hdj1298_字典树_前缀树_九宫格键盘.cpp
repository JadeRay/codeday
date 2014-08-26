//dictionary tree或前缀树，存储方式是每一层的兄弟节点形成单链表，父节点指向单链表的表头
//1247	171MS	2140K	3237 B	G++
//给定一组字符串，要求输出那些可以由其他任意两个字符串组合而成的字符串
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

//在某一层中查找给定字符的出现情况
//出现，则返回TRUE，同时now指向出现该字符的节点
//不出现，则返回FALSE，同时now指向本层的最后一个节点（便于将该字符插入到本层最后）
//如果now为null，则表明该层尚没有节点
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
 //返回以给定字符串为前缀的字符串的个数
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
//插入创建字典树（前缀树）
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
