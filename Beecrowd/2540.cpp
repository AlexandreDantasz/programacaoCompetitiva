#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double voto,n,cont,i;
	while(cin>>n){
		cont=0;
		for(i=0;i<n;i++){
			cin>>voto;
			if(voto==1){
				cont++;
				}
			}
		if(cont>=(n*2)/3.0){
			cout<<"impeachment"<<endl;
			}else{
				cout<<"acusacao arquivada"<<endl;
			}
		}
}
