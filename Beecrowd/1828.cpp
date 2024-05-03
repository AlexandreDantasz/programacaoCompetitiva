#include <iostream>

using namespace std;

int main(){
	int T,i;
	string she,raj,R;
	cin>>T;
	for(i=1;i<=T;i=i+1){
		cin>>she>>raj;
		if(she=="tesoura"&&raj=="papel"){
			R="Bazinga!";
			}else{
				if(she=="papel"&&raj=="pedra"){
					R="Bazinga!";
					}else{
						if(she=="pedra"&&raj=="lagarto"){
							R="Bazinga!";
							}else{
								if(she=="lagarto"&&raj=="Spock"){
									R="Bazinga!";
									}else{
										if(she=="Spock"&&raj=="tesoura"){
											R="Bazinga!";
											}else{
												if(she=="tesoura"&&raj=="lagarto"){
													R="Bazinga!";
													}else{
														if(she=="lagarto"&&raj=="papel"){
															R="Bazinga!";
															}else{
																if(she=="papel"&&raj=="Spock"){
																	R="Bazinga!";
																	}else{
																		if(she=="Spock"&&raj=="pedra"){
																			R="Bazinga!";
																			}else{
																				if(she=="pedra"&&raj=="tesoura"){
																					R="Bazinga!";
																					}else{
																						R="Raj trapaceou!";
																						}
																				}
																		}
																}
														}
												}
										}
								}
						}
				}
		if(she==raj){
			R="De novo!";
			}
		cout<<"Caso #"<<i<<": "<<R<<endl;
		}
	return 0;
	}
