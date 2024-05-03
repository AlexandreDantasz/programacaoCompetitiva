#include <iostream>

using namespace std;

int main(){
	int J,I,cont,contf;
	cont=0;
	I=1;
	contf=0;
	for(J=7;contf<15;J=J-1){
		if(cont<3){
			cout<<"I="<<I<<" J="<<J<<endl;
			}else{
				if(cont==3){
					I=I+2;
					J=J+5;
					cout<<"I="<<I<<" J="<<J<<endl;
					cont=0;
					}
				}
		cont=cont+1;
		contf=contf+1;
		}
	
	return 0;
	}
