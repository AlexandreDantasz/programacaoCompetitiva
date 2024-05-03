#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	float gd,n1,soma,maior,menor;
	string nome;
	int n,i=0,j;
	cin>>n;
	while(i<n){
		cin>>nome>>gd;
		soma=0.0;
		menor=0.0;
		maior=0.0;
		for(j=0;j<7;j++){
			cin>>n1;
			if(j==0){
				menor=n1;
				}else{
					if(n1<menor){
						menor=n1;
						}
					}
			if(n1>maior){
				maior=n1;
				}
			soma=soma+n1;
			}
		cout<<fixed<<setprecision(2);
		cout<<nome<<" "<<abs((soma-maior-menor))*gd<<endl;
		i++;
		}
	return 0;
	}
