#include <iostream>

using namespace std;

int main(){
	int n,i=2,atual=,ant1=13,ant2=3,aux;
	while(scanf("%d",&n)){
		while(i<n){
			aux=atual;
			atual=ant1+ant2;
			ant2=ant1;
			ant1=aux;
			i++;
			}
		if(n==1){
			printf("3\n");
			}else{
				if(n==2){
					printf("13\n");
					}
				printf("%d\n",atual);
				}
		}
	
	//~ nao entendi a logica da threebonacci
	}
