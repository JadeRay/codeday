//dictionary tree或前缀树，存储方式是每一层的兄弟节点形成单链表，父节点指向单链表的表头
//140MS	9012K	2046 B
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct node
{
   char value;
   int nCount;
   //bool isWord;    //to extend
   struct node* fChild;
   struct node* brother;
};

struct node* Tree=NULL;

//在某一层中查找给定字符的出现情况
//出现，则返回TRUE，同时now指向出现该字符的节点
//不出现，则返回FALSE，同时now指向本层的最后一个节点（便于将该字符插入到本层最后）
//如果now为null，则表明该层尚没有节点
bool findInLevel(struct node* q, struct node** now, char ch)
{
   struct node* p = q;   
   while(p)
   {
           *now = p ;
           if(p->value != ch) p = p->brother;
           else return true;
   }     
   return false;    
}

//返回以给定字符串为前缀的字符串的个数
int getCount(struct node* root, char* str)
{
    int i = 0 ;
    struct node* now = NULL;
    while(i<strlen(str) && root)
    {
        if(!findInLevel(root->fChild, &now, str[i])) return 0;
        i++;
        root = now;                   
    }   
    if(i>=strlen(str)) return root->nCount;
    else return 0;
    
}
//插入创建字典树（前缀树）
void insert(struct node* root, char* str)
{
    int i = 0;
    struct node* pNowLevel = root;
    while(i < strlen(str))
    { 
         struct node* now = NULL; 
         //cout<<"now for "<<str[i]<<endl;
         //system("pause");
         if(findInLevel(pNowLevel->fChild, &now, str[i]))
         {
             //cout<<"adding: "<<now->value<<endl;
             //system("pause");
             now->nCount++;                                     
         }
         else
         {
             struct node* pNode = (struct node*)malloc(sizeof(struct node));
             if(now) now->brother = pNode;
             else pNowLevel->fChild = pNode;
             pNode->value = str[i];
             pNode->nCount = 1;
             pNode->fChild = NULL;
             pNode->brother = NULL;
             now = pNode;   
         }
         pNowLevel = now;
         i++;                                        
    }      
}



int main()
{
    Tree = (struct node*)malloc(sizeof(struct node));
    Tree->nCount = 0;
    Tree->fChild = NULL;
    Tree->brother = NULL;
    char word[26];
    
    while(gets(word), strcmp(word, ""))
    {
           insert(Tree, word);                             
    }
    
    while(cin>>word)
    {
          cout<<getCount(Tree, word)<<endl;                          
    }
    return 0;
}
