#include <iostream>

using namespace std;

int main(){
	int n,n1,i,j,soma;
	cin>>n;
	for(j=0;j<n;j++){
		soma=0;
		cin>>n1;
		for(i=1;i<n1;i++){
			if(n1%i==0){
				soma=soma+i;
			}
		}
		if(soma==n1){
			cout<<n1<<" eh perfeito"<<endl;
		}else{
			cout<<n1<<" nao eh perfeito"<<endl;
		}
	}
	return 0;
}
