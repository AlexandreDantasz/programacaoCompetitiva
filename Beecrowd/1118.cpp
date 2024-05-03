#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int r=1,x=0;
	double nota,soma=0,media;
	while(r==1&&scanf("%lf",&nota)){
		if(nota>=0&&nota<=10){
			x++;
			soma+=nota;
		}else{
			printf("nota invalida\n");
		}
		if(x==2){
			media=soma/2;
			cout<<fixed<<setprecision(2);
			cout<<"media = "<<media<<endl;
			soma=0;
			x=0;
			r=3;
			while(r!=1&&r!=2){
				printf("novo calculo (1-sim 2-nao)\n");
				scanf("%d",&r);
			}
		}
	}
}
