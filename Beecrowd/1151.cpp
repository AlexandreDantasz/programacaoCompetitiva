#include <iostream>

using namespace std;

int main(){
	int N,i,ant,atual,aux,cont;
	cin>>N;
	ant=0;
	atual=1;
	cont=0;
	for(i=3;i<=N;i=i+1){
	if(N==1){
		cout<<ant<<endl;
		}else{
			if(N==2){
				cout<<ant<<" "<<atual<<endl;
				}else{
					if(N>2&&cont!=1){
						cout<<ant<<" "<<atual<<" ";
						cont=cont+1;
						}
					if(N>2&&i<N){
						aux=atual;
						atual=atual+ant;
						ant=aux;
						cout<<atual<<" ";
						}else{
							if(N!=2&&i==N){
								aux=atual;
								atual=atual+ant;
								ant=aux;
								cout<<atual<<endl;
								}
							}
					}
			}
		}
	return 0;
	}
