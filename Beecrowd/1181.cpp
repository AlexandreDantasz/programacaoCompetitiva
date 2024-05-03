#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int lin;
    char op;
    double soma=0;
    cin>>lin>>op;
    cout<<fixed<<setprecision(1);
    long double mat[12][12];
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int k=0;k<12;k++)
    {
        soma+=mat[lin][k];
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
