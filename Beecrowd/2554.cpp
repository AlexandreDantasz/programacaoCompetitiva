#include <iostream>

using namespace std;

int main(){
	int d,n,j,i,cont,conf;
	bool v;
	string guarde,str;
	while(cin>>n>>d){
		guarde="b";
		v=true;
		for(i=0;i<d;i++){
			cin>>str;
			cont=0;
			for(j=0;j<n;j++){
				cin>>conf;
				if(conf==1){
					cont++;
					if(cont==n&&v){
						guarde=str;
						v=false;
						}
					}
				}
			}
		if(guarde!="b"){
			cout<<guarde<<endl;
			}else{
				cout<<"Pizza antes de FdI"<<endl;
				}
		}
	
	return 0;
	}
