#include <iostream>

using namespace std;

int main(){
	int n,i,m,guarde;
	double nota,notabase;
	cin>>n;
	guarde=0;
	notabase=0;
	for(i=0;i<n;i=i+1){
		cin>>m>>nota;
		if(nota>=8&&nota>notabase){
			guarde=m;
			notabase=nota;
			}
		}
		if(guarde==0){
			cout<<"Minimum note not reached"<<endl;
			}else{
				cout<<guarde<<endl;
				}
	return 0;
	}
