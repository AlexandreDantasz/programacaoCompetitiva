#include <iostream>

using namespace std;

int main(){
	int X,i;
	cin>>X;
	if(X%2==0){
	for(i=1;i<X;i=i+2){
		cout<<i<<endl;
		}	
		}else{
			for(i=1;i<X+1;i=i+2){
				cout<<i<<endl;
				}	
			}
	return 0;
	}

