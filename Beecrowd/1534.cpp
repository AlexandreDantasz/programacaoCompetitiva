#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int mat[n][n];
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<n-1;k++)
            {//espaços que devem ser preenchidos por 3
				mat[j][k]=3;
                mat[k][j]=3;
            }
        }
        for(int i=0;i<n;i++)
        {
            mat[i][i]=1;
            mat[i][n-1-i]=2;
        }
        for(int l=0;l<n;l++)
        {
            for(int m=0;m<n;m++)
            {
                cout<<mat[l][m];
            }
            cout<<endl;
        }
    }
}

