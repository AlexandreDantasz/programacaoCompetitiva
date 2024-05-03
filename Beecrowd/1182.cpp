#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double mat[12][12],soma=0;
    int col;
    char op;
    cin>>col>>op;
    cout<<fixed<<setprecision(1);
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int k=0;k<12;k++)
    {
        soma+=mat[k][col];
    }
    if(op=='S')
    {
        cout<<soma<<endl;
    }
    else
    {
        cout<<soma/12<<endl;
    }
}
