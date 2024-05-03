#include <iostream>

using namespace std;

int main(){
	int N,i,cont;
	cin>>N;
	cont=0;
	i=1;
	while(cont<N){
		cout<<i<<" "<<i+1<<" "<<i+2<<" PUM"<<endl;
		cont++;
		i=i+4;
		}
	return 0;
	}
