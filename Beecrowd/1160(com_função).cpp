#include <iostream>

using namespace std;

int Pamaior(int pa,int pb,float ga,float gb)
{
    int cont=0;
    while(pa<=pb&&cont<=100)
    {
        pa=pa+(int)pa*ga/100;
        pb=pb+(int)pb*gb/100;
        cont++;
    }
    return cont;
}

int main()
{
    int n,ppA,ppB;
    float g1,g2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %f %f",&ppA,&ppB,&g1,&g2);
        if(Pamaior(ppA,ppB,g1,g2)<=100)
        {
            printf("%d anos.\n",Pamaior(ppA,ppB,g1,g2));
        }
        else
        {
            printf("Mais de 1 seculo.\n");
        }
    }
}
