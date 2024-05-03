#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i;
	double divi,S;
	S=1;
	for(i=2;i<=100;i=i+1){
		divi=(float)1/i;
		S=S+divi;
		}
		cout<<fixed<<setprecision(2);
		cout<<S<<endl;
	return 0;
	}
