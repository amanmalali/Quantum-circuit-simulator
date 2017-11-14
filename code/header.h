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
