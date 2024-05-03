#include <iostream>

using namespace std;

int main(){
	int base,pos,n,i,maior,posi;
	pos=0;
	base=0;
	for(i=0;i<100;i=i+1){
		cin>>n;
		if(n>base){
			maior=n;
			posi=pos+1; 
			}
		base=maior;
		pos=pos+1;
		}
	cout<<maior<<'\n';
	cout<<posi<<endl;
	return 0;
	}
