#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	bool flag,flag2;
	double nota1,nota2;
	flag=true;
	flag2=true;
	while(flag){
	cin>>nota1;
		if(nota1>=0.0&&nota1<=10.0){
			flag=!flag;
			}else{
				cout<<"nota invalida"<<endl;
				}
			}
	while(flag2){
		cin>>nota2;
		if(nota2>=0&&nota2<=10){
				cout<<fixed<<setprecision(2);
				cout<<"media = "<<(nota1+nota2)/2<<endl;
				flag2=!flag2;
				}else{
					cout<<"nota invalida"<<endl;
					}
		}
	return 0;
	}
