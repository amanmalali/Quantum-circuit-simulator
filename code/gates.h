#include "header.h"

struct node
{
    int mat[2][2];
    int size;
    node *next;
}*polyzgate,*notgate,*hadamardgate,*newptr,*ptr,*rearpolyz,*rearnot,*rearhardamard;

node *createpoly(int n)
{
    ptr=new node;
    ptr->size=n;
    ptr->mat[0][0]=1;
    ptr->mat[0][1]=0;
    ptr->mat[1][0]=0;
    ptr->mat[1][1]=-1;
    ptr->next=NULL;
    return ptr;
}

node *createnot(int n)
{
    ptr=new node;
    ptr->size=n;
    ptr->mat[0][0]=0;
    ptr->mat[0][1]=1;
    ptr->mat[1][0]=1;
    ptr->mat[1][1]=0;
    ptr->next=NULL;
    return ptr;
}

node *createhadamard(int n)
{
    ptr=new node;
    ptr->size=n;
    ptr->mat[0][0]=1;
    ptr->mat[0][1]=1;
    ptr->mat[1][0]=1;
    ptr->mat[1][1]=-1;
    ptr->next=NULL;
    return ptr;
}

void insertpolyz(node *np)
{
    if(polyzgate==NULL)
        polyzgate=rearpolyz=np;
    else
    {
        rearpolyz->next=np;
        rearpolyz=np;
    }
}

void insertnot(node *np)
{
    if(notgate==NULL)
        notgate=rearnot=np;
    else
    {
        rearnot->next=np;
        rearnot=np;
    }
}

void inserthadamard(node *np)
{
    if(hadamardgate==NULL)
        hadamardgate=rearpolyz=np;
    else
    {
        rearpolyz->next=np;
        rearpolyz=np;
    }
}

void polyz(int n)
{
    int i,j,m=1;
    for(i=0;i<n-1;i++)
    {
        m=m*2;
        newptr=createpoly(m);
        insertpolyz(newptr);
    }
    while(polyzgate!=NULL)
    {
        /*cout<<"\n\n\n";
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                cout<<polyzgate->mat[i][j]<<"      ";
            }
            cout<<"\n";
        }*/
        P=Tensor_Product(P,polyzgate->mat,polyzgate->size,2);
        polyzgate=polyzgate->next;
    }
}

void qnot(int n)
{
    int i,j,m=1;
    for(i=0;i<n-1;i++)
    {
        m=m*2;
        newptr=createnot(m);
        insertnot(newptr);
    }
    while(notgate!=NULL)
    {
        /*cout<<"\n\n\n";
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                cout<<notgate->mat[i][j]<<"      ";
            }
            cout<<"\n";
        }*/
        N=Tensor_Product(N,notgate->mat,notgate->size,2);
        notgate=notgate->next;
    }
}

void hadamard(int n)
{
    int i,j,m=1;
    for(i=0;i<n-1;i++)
    {
        m=m*2;
        newptr=createhadamard(m);
        inserthadamard(newptr);
    }
    while(hadamardgate!=NULL)
    {
        /*cout<<"\n\n\n";
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                cout<<hadamardgate->mat[i][j]<<"      ";
            }
            cout<<"\n";
        }*/
        H=Tensor_Product(H,hadamardgate->mat,hadamardgate->size,2);
        hadamardgate=hadamardgate->next;
    }
}