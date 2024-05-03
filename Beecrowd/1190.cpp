#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long double mat[12][12],soma=0;
    int aux=1,cont2=11,media=0;
    char op;
    cin>>op;
    cout<<fixed<<setprecision(1);
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int k=11;k>=7;k--)
    {//colunas
        for(int cont=aux;cont<cont2;cont++)
        {//linhas
            soma+=mat[cont][k];
            media++;
        }
        aux++;
        cont2--;
    }
    if(op=='S')
    {
        cout<<soma<<endl;
    }
    else
    {
        cout<<soma/media<<endl;
    }
}

