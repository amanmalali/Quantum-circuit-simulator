#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
vector<vector<int> >Q;
vector<vector<int> >P;
vector<vector<int> >N;
vector<vector<int> >H;
vector<vector<int> >Output,out;
vector<vector<int> > Tensor_Product(vector<vector<int> >a,int b[2][2],int n,int m);
vector<vector<int> > matmul(vector<vector<int> > a,vector<vector<int> > b);
void init_output(int n);

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

struct component
{
vector<vector<int> >gate;
string type;
int t;
component *wire;
}*cstart,*crear,*cnewptr,*cptr;

component *createcomponent(int f,int n)
{
    cptr=new component;
    cptr->gate.resize(n,vector<int>(n,0));
    if(f==1)
        {
            cptr->gate=N;
            cptr->type="NOT";
        }
    else if(f==2)
        {
            cptr->gate=H;
            cptr->type="HGATE";
        }
    else
        {
            cptr->gate=P;
            cptr->type="PGATE";
        }
    cptr->wire=NULL;
    return cptr;
};


void insert_component(component *cnp)
{
    if(cstart==NULL)
        cstart=crear=cnp;
    else
    {
        crear->wire=cnp;
        crear=cnp;
    }
}

void display(component *np)
{   cout<<"\n"<<"INPUT--->";
    while(np!=NULL)
    {
        cout<<np->type<<"--->";
        np=np->wire;
    }    

    cout<<"OUTPUT"<<"\n\n\n";
}

void calculate(component *np)
{   
    while(np!=NULL)
    {
    Output=matmul(Output,np->gate);
    np=np->wire;
    }
out=matmul(Q,Output);
int i,j,k=N[0].size();

for (i=0; i<k; i++) {
        for (j=0; j<k; j++) {
            cout<<out[i][j]<<"  ";
        }
        cout<<"\n\n";
    }


}


void gateselection(int n)
{   
    int choice=0;
    while(choice!=5)
    {
        cout<<"\n\n";
        cout<<"1.ADD NOT GATE\n2.ADD HGATE\n3.ADD PGATE\n4.DISPLAY\n5.EXIT\nChoice : ";
        cin>>choice;

        switch(choice)
        {
            case 1: cnewptr=createcomponent(1,n);
                    insert_component(cnewptr);
                    break;
            case 2: cnewptr=createcomponent(2,n);
                    insert_component(cnewptr);
                    break;
            case 3: cnewptr=createcomponent(3,n);
                    insert_component(cnewptr);
                    break;
            case 4: display(cstart);
                    break;
            case 5: cout<<"Calculating final \n\n\n";
                    break;
            default : cout<<"\nWrong choice\n";


        }
    }
    calculate(cstart);
}




vector<vector<int> > Tensor_Product(vector<vector<int> >a,int b[2][2],int n,int m)
{
    vector<vector<int> >c;
    c.resize(n*m,vector<int>(n*m,0));
    int i,j,l,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(l=0;l<m;l++)
            {
                for(k=0;k<m;k++)
                {
                    c[i*m+l][j*m+k]=a[i][j]*b[l][k];
                }
            }
        }
    }
    return c;
}

void init_output(int n)
{
 Output.resize(n,vector<int>(n,0));
 out.resize(n,vector<int>(n,0));
 int i,j;
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
        if(i==j)
        {
            Output[i][j]=1;
            out[i][j]=1;
        }
    }
 }   
}


vector<vector<int> > matmul(vector<vector<int> > a,vector<vector<int> > b)
{   int i,j,k;
    vector<vector<int> > c;
    c.resize(a[0].size(),vector<int>(a[0].size(),0));
    for(i=0;i<a[0].size();i++)
    {
        for(j=0;j<a.size();j++)
        {
            c[i][j]=0;
            for(k=0;k<a.size();k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    return c;
}


void input()
{
    int n,i,j;
    cout<<"enter the number of qubits"<<endl;
    cin>>n;
    int k=pow(2,n);
    init_output(k);
    Q.resize(k,vector<int>(k,0));
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            if(i==j)
            {
                Q[i][j]=1;
            }
            else
            {
                Q[i][j]=0;
            }
        }
    }
    /*for (i=0; i<k; i++) {
        for (j=0; j<k; j++) {
            cout<<Q[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    polyzgate=rearpolyz=NULL;
    P.resize(k,vector<int>(k,0));
    P[0][0]=1;
    P[0][1]=0;
    P[1][0]=0;
    P[1][1]=-1;
    polyz(n);
    /*cout<<"\nOutput\n";
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            cout<<P[i][j]<<"      ";
        }
        cout<<"\n\n";
    }*/
    
    notgate=rearnot=NULL;
    N.resize(k,vector<int>(k,0));
    N[0][0]=0;
    N[0][1]=1;
    N[1][0]=1;
    N[1][1]=0;
    qnot(n);
    /*cout<<"\nOutput\n";
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            cout<<N[i][j]<<"      ";
        }
        cout<<"\n\n";
    }*/
    
    hadamardgate=rearhardamard=NULL;
    H.resize(k,vector<int>(k,0));
    H[0][0]=1;
    H[0][1]=1;
    H[1][0]=1;
    H[1][1]=-1;
    hadamard(n);
    /*cout<<"\nOutput\n";
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            cout<<H[i][j]<<"      ";
        }
        cout<<"\n\n";
    }*/
   
    gateselection(k);
}

/*void clear(node *first)
{
    node *temp;
    while(*temp)
    {
        temp=first;
        *first=(*first)->next;
        delete temp;
    }
}*/

int main()
{
    input();

    
    return 0;
}
