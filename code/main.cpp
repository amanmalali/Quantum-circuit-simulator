#include "gates.h"
#include "components.h"
#include "funcs.h"



void input()
{
    int n,i,j;
    cout<<"Enter The Number of Qubits"<<"\n";
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
   
    polyzgate=rearpolyz=NULL;
    P.resize(k,vector<int>(k,0));
    P[0][0]=1;
    P[0][1]=0;
    P[1][0]=0;
    P[1][1]=-1;
    polyz(n);

    notgate=rearnot=NULL;
    N.resize(k,vector<int>(k,0));
    N[0][0]=0;
    N[0][1]=1;
    N[1][0]=1;
    N[1][1]=0;
    qnot(n);

    hadamardgate=rearhardamard=NULL;
    H.resize(k,vector<int>(k,0));
    H[0][0]=1;
    H[0][1]=1;
    H[1][0]=1;
    H[1][1]=-1;
    hadamard(n);
    gateselection(k);
}


int main()
{
    input();

    
    return 0;
}
