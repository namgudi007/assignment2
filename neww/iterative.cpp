#include <iostream>

using namespace std;

 struct Node
    {
        int val;
        struct Node *left;
        struct Node *right;

    };
    typedef struct Node* node;

    node s[100];
    int size=100;
    int ar[100];
    int m=0;
    int top=-1;

node insert(node root,int item)
{
  int f;
  node p,q;
  f=0;
  p=root;
  while((p!=NULL)and not f)
  {
      q=p;

      if((p->val)<item)
        p=p->right;
      else if((p->val)>item)
         p=p->left;
      else {cout<<"Cant insert duplicate elements"<<endl;f=1;}
  }
  node temp;
  temp=(node)malloc(sizeof(struct Node));
  temp->right=NULL;
  temp->left=NULL;
  temp->val=item;
  if(not f)
  {
    if(root!=NULL)
    {
        if(q->val<item)q->right=temp;
        else q->left=temp;
    }
    else
        root=temp;
  }

return root;
}
void push(node root)
{
 if(top==size-1)
 return;
 s[++top]=root;
}
node pop()
{
    if(top==-1)
    return 0;
    return s[top--];

}
 void inorder(node root)
 {


   while(1)
   {
       while(root)
       {
          push(root);
          root=root->left;

       }
   if(top==-1)
   break;
   root=pop();
   cout<<root->val<<"\t";
   ar[m]=root->val;
   m++;
   root=root->right;

   }





 }

int main()
{

   int n,arr[1000];
   cout<<"Enter the number of elements"<<endl;
   cin>>n;
   cout<<"Enter the tree elements"<<endl;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   node root=NULL;
   for(int i=0;i<n;i++)
   {
       root=insert(root,arr[i]);
   }
   inorder(root);
   for(int k=0;k<m;k++)
   cout<<ar[k]<<"\t";

   return 0;
}

