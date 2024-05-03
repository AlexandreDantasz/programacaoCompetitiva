#include <iostream>

using namespace std;

int main(){
	char M,conv;
	int N,i,comp,comp2;
	while(cin){
		cin>>N;
		comp2=78;
		i=0;
		if(N==0){
			break;
			}
		while(i<N){
			cin>>M;
			comp=M;
			if(comp==68&&comp2==78){
				comp2=76; // LESTE
				}else{
					if(comp==68&&comp2==76){
						comp2=83; // SUL
						}else{
							if(comp==68&&comp2==83){
								comp2=79; // OESTE
								}else{
									if(comp==68&&comp2==79){
										comp2=78; // NORTE
										}else{
											if(comp==69&&comp2==78){
												comp2=79; // OESTE
												}else{
													if(comp==69&&comp2==79){
														comp2=83; // SUL
														}else{
															if(comp==69&&comp2==83){
																comp2=76; // LESTE
																}else{
																	if(comp==69&&comp2==76){
																		comp2=78; // NORTE
																		}
																	}
															}
													}
											}
									}
							}
					}
			i++;
			}
			conv=comp2;
			cout<<conv<<endl;
	}
	return 0;
	}
