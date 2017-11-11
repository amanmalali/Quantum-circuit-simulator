#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<std::vector<int> > multiply(vector<vector<int> >a,int b[2][2],int n,int m);
vector<std::vector<int> >z;
struct node 
{
int mat[2][2];
int siz;
node *next;
}*start,*newptr,*save,*ptr,*rear;

node *create(int n)
{
	ptr=new node;
	ptr->siz=n;
	ptr->mat[0][0]=1;
    ptr->mat[0][1]=0;
    ptr->mat[1][0]=0;
    ptr->mat[1][1]=-1;
    ptr->next=NULL;
    return ptr;
}

void insert(node *np)
{
	if(start==NULL)
		start=rear=np;
	else
	{
		rear->next=np;
		rear=np;
	}
}

void pauli(int n)
{
int i,j,m=1;
for(i=0;i<n-1;i++)
{   
	m=m*2;
	newptr=create(m);
	insert(newptr);
}
while(start!=NULL)
{   
	cout<<"\n\n\n";
	for(i=0;i<2;i++)
    {
	for(j=0;j<2;j++)
	{
		cout<<start->mat[i][j]<<"      ";
	}
	cout<<"\n";
   }
	z=multiply(z,start->mat,start->siz,2);
	start=start->next;
};
}











vector<std::vector<int> > multiply(vector<vector<int> >a,int b[2][2],int n,int m)
{
/*int**c = new int*[n*m];
for(int p=0;p<n*m;++p)
    c[p]=new int[n*m];*/
vector<std::vector<int> >c;
c.resize(n*m, std::vector<int>(n*m,0));
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






int main()
{   start=rear=NULL;
	int b[2][2];
	int n,m,i,j,ele;
	cin>>n;
	int k=pow(2,n);
	
    z.resize(k, std::vector<int>(k,0));
	z[0][0]=1;
    z[0][1]=0;
    z[1][0]=0;
    z[1][1]=-1;
    b[0][0]=1;
    b[0][1]=0;
    b[1][0]=0;
    b[1][1]=-1;
    m=1;
    pauli(n);
    /*for(i=1;i<n;i++)
    {	
    m=m*2;
	z=multiply(z,b,m,2);
    }
	//m=m*2;
    //a=multiply(a,b,m,2);
    */
    
	cout<<"\nOutput\n";
    for(i=0;i<k;i++)
    {
	for(j=0;j<k;j++)
	{
		cout<<z[i][j]<<"      ";
	}
	cout<<"\n\n";
}

	return 0;
}