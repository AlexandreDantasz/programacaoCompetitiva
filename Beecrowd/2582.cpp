#include <iostream>

using namespace std;

int main(){
	int C,X,Y,cont,soma;
	bool flag;
	cin>>C;
	cont=0;
	flag=true;
	while(flag){
		cin>>X>>Y;
		soma=X+Y;
		if(soma==0){
			cout<<"PROXYCITY"<<endl;
			}else{
				if(soma==1){
					cout<<"P.Y.N.G."<<endl;
					}else{
						if(soma==2){
							cout<<"DNSUEY!"<<endl;
							}else{
								if(soma==3){
									cout<<"SERVERS"<<endl;
									}else{
										if(soma==4){
											cout<<"HOST!"<<endl;
											}else{
												if(soma==5){
													cout<<"CRIPTONIZE"<<endl;
													}else{
														if(soma==6){
															cout<<"OFFLINE DAY"<<endl;
															}else{
																if(soma==7){
																	cout<<"SALT"<<endl;
																	}else{
																		if(soma==8){
																			cout<<"ANSWER!"<<endl;
																			}else{
																				if(soma==9){
																					cout<<"RAR?"<<endl;
																					}else{
																						if(soma==10){
																							cout<<"WIFI ANTENNAS"<<endl;
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
				}
		cont++;
		if(cont==C){
			flag=!flag;
			}
		}
	return 0;
	}
