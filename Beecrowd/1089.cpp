#include <iostream>

using namespace std;

int main()
{
    int pico=0,n,ant,prox;
    scanf("%d",&n);
    while(n!=0)
    {
        int mag[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&mag[i]);
        }
        for(int j=0;j<n;j++)
        {//analisando os picos com o conceito de memória circular
            ant=(j+n-1)%n;
            prox=(j+1)%n;
            if(mag[ant]>mag[j]&&mag[j]<mag[prox])
            {
                pico++;
            }
            else
            {
                if(mag[ant]<mag[j]&&mag[j]>mag[prox])
                {
                    pico++;
                }
            }
        }
        printf("%d\n",pico);
        scanf("%d",&n);
        pico=0;
    }
}
