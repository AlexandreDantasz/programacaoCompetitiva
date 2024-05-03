#include <iostream>

using namespace std;

int main(){
	int N,i,X;
	cin>>N;
	for(i=0;i<N;i=i+1){
		cin>>X;
		if(X%2==0&&X!=0){
			cout<<"EVEN ";
			}else{
				if(X%2!=0&&X!=0){
				 cout<<"ODD ";
				 }
				}
		if(X>0){
			cout<<"POSITIVE"<<endl;
			}else{
				if(X<0){
				 cout<<"NEGATIVE"<<endl;
				 }
				}
		if(X==0){
			cout<<"NULL"<<endl;
			}
		}
	return 0;
	}
