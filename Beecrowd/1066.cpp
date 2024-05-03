#include <iostream>

using namespace std;

int main(){
	int n,pos,neg,pares,impares,i;
	pos=0;
	neg=0;
	pares=0;
	impares=0;
	for(i=0;i<5;i=i+1){
		cin>>n;
		if(n>0){
			pos=pos+1;
			}else{
				if(n<0){
					neg=neg+1;
					}
				}
		if(n%2==0){
			pares=pares+1;
			}else{
				impares=impares+1;
				}
		}
		cout<<pares<<" valor(es) par(es)"<<endl;
		cout<<impares<<" valor(es) impar(es)"<<endl;
		cout<<pos<<" valor(es) positivo(s)"<<endl;
		cout<<neg<<" valor(es) negativo(s)"<<endl;
	return 0;
	}
