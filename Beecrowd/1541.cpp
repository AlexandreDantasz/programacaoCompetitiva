#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int A,B,C,mult,tot;
	while(cin){
		cin>>A;
		if(A==0){
			break;
			}else{
				cin>>B;
				if(B==0){
					break;
					}else{
						cin>>C;
						if(C==0){
							break;
							}else{
								mult=A*B;
								tot=(mult*100)/C;
								cout<<int(sqrt(tot))<<endl;
								}
						}
				}
		}
	return 0;
	}
