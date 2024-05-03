#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	float v,d,h,area;
	while(cin>>v>>d){
		cout<<fixed<<setprecision(2);
		h=v/(3.14*pow(d/2,2));
		area=3.14*pow(d/2,2);
		cout<<"ALTURA = "<<h<<endl;
		cout<<"AREA = "<<area<<endl;
	}
	
}
