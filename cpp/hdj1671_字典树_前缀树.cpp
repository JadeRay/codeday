//tree, hdj 1671
//359MS	2032K	2330 B
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct node
{
   char value;
   int nCount;
   struct node* fChild;
   struct node* brother;
   bool isWord;
};


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

bool insert(struct node* root, char* str)
{
    int i = 0;
    struct node* pNowLevel = root;
    bool flag = true;
    while(i < strlen(str))
    { 
         struct node* now = NULL; 
         if(findInLevel(pNowLevel->fChild, &now, str[i]))
         {
             now->nCount++;   
             if(now->isWord && flag) flag = false;                                  
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
             pNode->isWord = false;
             now = pNode;   
         }
         pNowLevel = now;
         i++;                                        
    }  
    pNowLevel->isWord = true;
    if(pNowLevel->fChild && flag) flag = false;
    return flag;   
}

void clear(struct node* root)
{
     if(!root) return;
     struct node* p = root;
     if(p->brother) clear(p->brother);
     if(p->fChild) clear(p->fChild);
     free(p);   
}

int main()
{
    struct node* Tree=NULL;
    Tree = (struct node*)malloc(sizeof(struct node));
    Tree->nCount = 0;
    Tree->fChild = NULL;
    Tree->brother = NULL;
    
    int T;
    cin>>T;
    while(T--)
    {
         char word[15];
         int n;
         bool isOk = true;
         cin>>n;
         for(int i = 1 ; i <= n; i++)
         {
            cin>>word;  
            if(!insert(Tree, word)) isOk = false;     
         }   
         if(isOk) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;      
         clear(Tree->fChild); 
         Tree->fChild = NULL;      
    }  
    return 0;
}
