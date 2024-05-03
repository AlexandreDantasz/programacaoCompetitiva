#include <iostream>

using namespace std;

int main(){
		int mes,dia,df,fim;
		while(cin>>mes>>dia){
			if(mes==1){
				df=31-dia;
				fim=5*31+4*30+29+25+df;
				}else{
					if(mes==2){
						df=29-dia;
						fim=5*31+4*30+25+df;
						}else{
							if(mes==3){
								df=31-dia;
								fim=4*31+4*30+25+df;
								}else{
									if(mes==4){
										df=30-dia;
										fim=4*31+3*30+25+df;
										}else{
											if(mes==5){
											df=31-dia;
											fim=3*31+3*30+25+df;
											}else{
												if(mes==6){
													df=30-dia;
													fim=3*31+2*30+25+df;
													}else{
														if(mes==7){
															df=31-dia;
															fim=2*31+2*30+25+df;
															}else{
																if(mes==8){
																	df=31-dia;
																	fim=1*31+2*30+25+df;
																	}else{
																		if(mes==9){
																			df=30-dia;
																			fim=1*31+1*30+25+df;
																			}else{
																				if(mes==10){
																					df=31-dia;
																					fim=30+25+df;	
																					}else{
																						if(mes==11){
																							df=30-dia;
																							fim=df+25;
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
			if(mes==12&&dia==25){
				cout<<"E natal!"<<endl;
				}else{
					if(mes==12&&dia==24){
						cout<<"E vespera de natal!"<<endl;
						}else{
							if(mes==12&&dia>25){
								cout<<"Ja passou!"<<endl;
								}
							}
					}
			if(mes!=12){
				cout<<"Faltam "<<fim<<" dias para o natal!"<<endl;
				}
			if(mes==12&&dia<25&&dia<24){
				cout<<"Faltam "<<25-dia<<" dias para o natal!"<<endl;
				}
			}
		return 0;
		}
