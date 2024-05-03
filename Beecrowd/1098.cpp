#include <iostream>

using namespace std;

int main(){
	double I,J;
	int contf,conti;
	contf=0;
	conti=0;
	J=1;
	for(I=0;contf<33;J=J+1){
		if(conti==3){
			I=I+0.2;
			J=J-2.8;
			cout<<"I="<<I<<" J="<<J<<endl;
			conti=0;
			}else{
				cout<<"I="<<I<<" J="<<J<<endl;
				}
		contf=contf+1;
		conti=conti+1;
		}
	return 0;
	}
