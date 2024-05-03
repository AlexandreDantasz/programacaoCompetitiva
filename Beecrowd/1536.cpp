#include <iostream>

using namespace std;

int main(){
	int n,saldo1,saldo2,t1a,t1b,t2a,t2b,res1,res2,i;
	char lix;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		res1=0;
		res2=0;
		scanf("%d %c %d %d %c %d",&t1a,&lix,&t2a,&t2b,&lix,&t1b);
		saldo1=(t1a+t1b)-t2a-t2b;
		saldo2=(t2a+t2b)-t1a-t1b;
		if(t1a>t2a||t1b>t2b){
			res1+=3;
		}
		if(t1a<t2a||t1b<t2b){
			res2+=3;
		}else{
			if(t1a==t2a||t1b==t2b){
				res1++;
				res2++;
			}
		}
		if(res1==res2){
			if(saldo1>saldo2||t1b>t2a){
				res1+=3;
			}else{
				if(saldo2>saldo1||t1b<t2a){
					res2+=3;
				}
			}	
		}
		if(res1>res2){
			printf("Time 1\n");
		}else{
			if(res2>res1){
			printf("Time 2\n");
			}else{
				printf("Penaltis\n");
			}
		}
	}
}
