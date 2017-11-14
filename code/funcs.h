#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
void init_output(int n);
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