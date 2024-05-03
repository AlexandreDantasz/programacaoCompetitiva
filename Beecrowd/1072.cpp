#include <iostream>

using namespace std;

int main(){
	int N,X,ok,no,i;
	ok=0;
	no=0;
	cin>>N;
	for(i=0;i<N;i=i+1){
		cin>>X;
		if(X>=10&&X<=20){
			ok=ok+1;
			}else{
				no=no+1;
				}
		}
		cout<<ok<<" in"<<endl;
		cout<<no<<" out"<<endl;
	return 0;
	}


