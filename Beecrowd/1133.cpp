#include <iostream>

using namespace std;

int main(){
	int X,Y,i,maior;
	cin>>X>>Y;
	if(X<Y){
		i=X+1;
		maior=Y;
		}else{
			i=Y+1;
			maior=X;
			}
	for(i=i;i<maior;i=i+1){
		if(i%5==2||i%5==3){
			cout<<i<<endl;
			}
		}
	return 0;
	}
