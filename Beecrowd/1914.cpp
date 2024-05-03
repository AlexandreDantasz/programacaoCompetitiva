#include <iostream>

using namespace std;

int main(){
	int QT,cont,tot,N,M;
	string nome1,nome2,esc1,esc2;
	cin>>QT;
	cont=0;
	while(cont<QT){
		cin>>nome1>>esc1>>nome2>>esc2;
		cin>>N>>M;
		tot=N+M;
		if(tot%2==0){
			if(esc1=="PAR"){
				cout<<nome1<<endl;
				}else{
					if(esc2=="PAR"){
						cout<<nome2<<endl;
						}
					}
			}else{
				if(esc1=="IMPAR"){
					cout<<nome1<<endl;
					}else{
						if(esc2=="IMPAR"){
							cout<<nome2<<endl;
							}
						}
				}
		cont++;
		}
	return 0;
	}
