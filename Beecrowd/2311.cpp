#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int N,i=0,j;
	string nome;
	float gd,maior,menor,soma,vec[7]; 
	cin>>N;
	while(i<N){
		maior=0.0;
		menor=0.0;
		soma=0.0;
		cin>>nome>>gd;
		for(j=0;j<7;j++){
			cin>>vec[j];
			menor=vec[0]; 
			soma=soma+vec[j];
			}
		for(j=0;j<7;j++){
			if(vec[j]>maior){
				maior=vec[j];
				}
			if(vec[j]<menor){
				menor=vec[j];
				}
			}
		cout<<fixed<<setprecision(2);
		cout<<nome<<" "<<abs((soma-maior-menor))*gd<<endl;
		i++;
		}
	return 0;
	}
