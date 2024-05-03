#include <iostream>

using namespace std;

int main()
{
	int hora,min,matcomp1[4]={8,4,2,1},matcomp2[6]={32,16,8,4,2,1};
	char lixo;
	string mat1[2][4]={"8","4","2","1"},mat2[2][6]={"32","16","8","4","2","1"};
	while(cin>>hora>>lixo>>min)
	{
		for(int i=0;i<4;i++)
		{
			if(hora>=matcomp1[i])
			{
				mat1[1][i]='o';
				hora-=matcomp1[i];
			}
			else
			{
				mat1[1][i]=' ';
			}
		}
		for(int j=0;j<6;j++)
		{
			if(min>=matcomp2[j])
			{
				mat2[1][j]='o';
				min-=matcomp2[j];
			}
			else
			{
				mat2[1][j]=' ';
			}
		}
		cout<<" ____________________________________________\n";
		for(int i=0;i<14;i++)
		{
			if(i==0)
			{
				cout<<"|                                            |\n";
			}
			else
			{
				if(i==1)
				{
					cout<<"|    ____________________________________    |_\n";
				}
				else
				{
					if(i==2)
					{
						cout<<"|   |                                    |   |_)\n";
					}
					else
					{
						if(i==3)
						{
							cout<<"|   |   ";
							for(int x=0;x<4;x++)
							{
								if(x!=3)
								{
									cout<<mat1[0][x]<<"         ";
								}
								else
								{
									cout<<mat1[0][x]<<"  |   |\n";
								}
							}
						}
						else
						{
							if(i==4)
							{
								cout<<"|   |                                    |   |\n";
							}
							else
							{
								if(i==5)
								{
									cout<<"|   |   ";
									for(int x=0;x<4;x++)
									{
										if(x!=3)
										{
											cout<<mat1[1][x]<<"         ";
										}
										else
										{
											cout<<mat1[1][x]<<"  |   |\n";
										}
									}
								}
								else
								{
									if(i==8)
									{
										cout<<"|   |   ";
										for(int x=0;x<6;x++)
										{
											if(x<2)
											{
												cout<<mat2[1][x]<<"     ";
											}
											else
											{
												if(x<3)
												{
													cout<<mat2[1][x]<<"     ";
												}
												else
												{	
													if(x==3)
													{			
														cout<<mat2[1][x]<<"    ";
													}
													else
													{
														if(x<5)
														{
															cout<<" "<<mat2[1][x]<<"     ";
														}
														else
														{
															cout<<mat2[1][x]<<"  |   |"<<'\n';
														}
													}
												}
											}
										}
									}
									else
									{
										if(i==9)
										{
											cout<<"|   |                                    |   |\n";
										}
										else
										{
											if(i==10)
											{
												cout<<"|   |   ";
												for(int x=0;x<6;x++)
												{
													
													if(x<2)
													{
														cout<<mat2[0][x]<<"    ";
													}
													else
													{
														if(x<5)
														{
															cout<<mat2[0][x]<<"     ";
														}
														else
														{
															cout<<mat2[0][x]<<"  |   |_\n";	
														}
													}
												}
											}
											else
											{
												if(i==6)
												{
													for(int x=0;x<2;x++)
													{
														cout<<"|   |                                    |   |\n";
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
		}
		cout<<"|   |____________________________________|   |_)\n";
		cout<<"|                                            |\n";
		cout<<"|____________________________________________|\n";
		cout<<'\n';
	}
}
