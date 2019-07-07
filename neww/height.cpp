#include <iostream>

using namespace std;

struct Node
    {
        int val;
        struct Node *left;
        struct Node *right;

    };
    typedef struct Node* node;
node insert(node root,int item)
{
  int f;
  node p,q;
  f=0;
  p=root;
  while((p!=NULL)and not f)
  {
      q=p;

      if((p->val)>item)
        p=p->left;
      else
         p=p->right;
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
int max_height(node root)
{
    if(root==NULL)
        return 0;
    if(root->right==NULL and root->left==NULL)
        return 1;
    return 1+max(max_height(root->left),max_height(root->right));

}
int min_height(node root)
{
    if(root==NULL)
        return 0;
    if(root->right==NULL and root->left==NULL)
        return 1;
    return 1+min(min_height(root->left),min_height(root->right));

}
int main()
{
   int n,ar[1000];
   cout<<"Enter the number of elements"<<endl;
   cin>>n;
   node root=NULL;
   for(int i=0;i<n;i++)
   {
       //cin>>ar[i];
       ar[i]=(rand()%1000)+10;
       cout<<ar[i]<<"\t";
       root=insert(root,ar[i]);
   }
   int max_ht=max_height(root);
   cout<<"Max height="<<max_ht;
   int min_ht=min_height(root);
   cout<<"Min height="<<min_ht;
    return 0;
}
