#include <iostream>

using namespace std;
struct node
{
    int info;
    int bal;
    node *left, *right;
};
node *minim(node *x)
{
    while(x->left)
        x=x->left;
    return x;
}
int minim(int x, int y)
{
    if(x<y)
        return x;
    return y;
}
int maxim(int x, int y)
{
    if(x>y)
        return x;
    return y;
}
void simple_rotation_to_left(node *p)
{
    node *t=p->right;
    p->right=t->left;
    t->left=p;
    p->bal=p->bal-(1+maxim(t->bal, 0));
    t->bal=t->bal-(1-minim(p->bal, 0));
    p=t;

}
void simple_rotation_to_right(node *p)
{
    node *t=p->left;
    p->left=t->right;
    t->right=p;
    p->bal=p->bal+(1-minim(t->bal, 0));
    t->bal=t->bal+(1+maxim(p->bal, 0));
    p=t;
}
void rotation_left_right(node *p)
{
    simple_rotation_to_left(p->left);
    simple_rotation_to_right(p);
}
void rotation_right_left(node *p)
{
    simple_rotation_to_right(p->right);
    simple_rotation_to_left(p);
}
void echilibrare(node *p)
{
    if(p->bal==2)
    {
        if(p->left->bal==1)
            simple_rotation_to_left(p);
        else
            rotation_left_right(p);
    }
    else if(p->bal==-2)
    {
        if(p->right->bal==-1)
            simple_rotation_to_right(p);
        else
            rotation_right_left(p);
    }
}
void search_insert(node *p, int val)
{
    if(p==NULL)
    {
        p=new node;
        p->info=val;
        p->bal=0;
        p->left=NULL;
        p->right=NULL;
    }
    else
    {
        if(p->info==val)
            return ;
        else
        {
            if(p->info>val)
            {
                search_insert(p->left, val);
                p->bal--;
            }
            else
            {
                search_insert(p->right, val);
                p->bal++;
            }
        }
    }
    if(p->bal==-2||p->bal==2)
        echilibrare(p);
}
/*void cautare_delete(node *p, int val)
{
    if(p->info==val)
    {
        if(p->left!=NULL)
      {p->info=p->left->info;
      p->bal++;
      p->left=NULL;
      }
      else
        if(p->right!=NULL)
      {
          p->info=p->right->info;
          p->bal--;
          p->right=NULL;
      }
    }
    else
    {
        if(p->info<val)
            cautare_delete(p->right, val);
        else
            cautare_delete(p->left, val);
    }

    echilibrare(p);
}*/
bool delete(node *p,int val)
{
    if(p==NULL) return false;
    if(p->info>val)
        if(delete(p->left,val)==true)
            p->bal++;
        else
            return false;
    else if(p->info<val)
        if(delete(p->right,val)==true)
            p->bal--;
        else
            return false;
    else if(p->left==NULL||p->right==NULL)
    {
        if(p->left!=NULL)
        {
            p->info=p->left->info;
            p->left=NULL;
            p->bal++;
            return true;
        }
        else if(p->right!=NULL)
        {
            p->info=p->right->info;
            p->right=NULL;
            p->bal--;
            return true;
        }
        else
        {
            node *y=minim(p->right);
            p->info=y->info;
            if(delete(p->right,y->info)==true)
                p->bal--;
            else
                return false;
        }
        if(p->bal==2||p->bal==-2)
            echilibrare(p);
        if(p->bal==0)
            return true;
        else
            return false;
    }

}

void display(node *p)
{
    cout<<p->info;
    if(p->left)
        display(p->left);
    else
        display(p->right);
}
int main()
{
    int n, x;
    node *cap=NULL;
    cout<<"n=";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        search_insert(cap,x);
    }
    cin>>x;
    delete(cap, x);
    display(cap);

    return 0;
}
