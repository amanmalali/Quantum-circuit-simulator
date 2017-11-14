#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
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
        cout<<"1.ADD NOT GATE\n2.ADD HGATE\n3.ADD PGATE\n4.DISPLAY\n5.CALCULATE & EXIT\nChoice : ";
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
