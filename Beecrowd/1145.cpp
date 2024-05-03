#include <iostream>

using namespace std;

int main(){
	int i,X,Y,cont;
	cin>>X>>Y;
	cont=0;
	for(i=1;i<=Y;i=i+1){
		cont=cont+1;
		if(i<=Y&&cont<X){
			cout<<i<<" ";
			}
		if(cont==X&&(i!=Y||i==Y)){
			cout<<i<<endl;
			cont=0;
			}
		}
	return 0;
	}
