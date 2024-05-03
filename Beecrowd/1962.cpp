#include <iostream>

using namespace std;

int main(){
	int n,i,ano;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ano;
		if(ano>2015){
			cout<<ano+1-2015<<" A.C."<<endl;
		}else{
			if(ano<2015){
				cout<<2015-ano<<" D.C."<<endl;
			}else{
				if(ano==2015){
					cout<<"1 A.C."<<endl;
				}
			}
		}
	}
}
