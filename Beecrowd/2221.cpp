#include <iostream>

using namespace std;

int main(){
	int T,cont,B,A1,D1,L1,A2,D2,L2,VG1,VG2;
	cin>>T;
	cont=0;
	while(cont<T){
		cin>>B; //bônus
		cin>>A1>>D1>>L1;
		cin>>A2>>D2>>L2;
		if(L1%2==0){
			VG1=((A1+D1)/2)+B;
			}else{
				VG1=(A1+D1)/2;
				}
		if(L2%2==0){
			VG2=((A2+D2)/2)+B;
			}else{
				VG2=(A2+D2)/2;
				}
		if(VG1>VG2){
			cout<<"Dabriel"<<endl;
			}else{
				if(VG1<VG2){
					cout<<"Guarte"<<endl;
					}else{
						cout<<"Empate"<<endl;
						}
				}
		cont++;
		}
	return 0;
	}
