#include <iostream>

using namespace std;

int main()
{
    int n,aux=0,guarde,freq=0;
    scanf("%d",&n);
    int notas[n];
    for(int i=0;i<n;i++)
    {//leitura de notas
        scanf("%d",&notas[i]);
    }
    for(int j=0;j<n;j++)
    {//posição da nota
        for(int k=0;k<n;k++)
        {//varredura da listaa de notas
            if(notas[j]==notas[k])
            {//analisando frequência
                freq++;
            }
        }
    if(freq>aux)
    {//priorizando a maior frequência
        aux=freq;
        guarde=notas[j];
    }
    else
    {//não há maior frequência
        if(freq==aux)
        {//analisando igualdade de frequências
            if(notas[j]>guarde)
            {//priorizando a maior nota
                guarde=notas[j];
            }
        }
    }
    freq=0;
    }
    printf("%d\n",guarde);
}
