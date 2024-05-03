#include <iostream>

using namespace std;

int main()
{
	string s1,s2,s3,s4;
	int n1,n2,m,lim;
	char c;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	lim=s1.size();
	n1=(s1[0]-48)*1000+(s2[0]-48)*100+(s3[0]-48)*10+(s4[0]-48);
	n2=(s1[lim-1]-48)*1000+(s2[lim-1]-48)*100+(s3[lim-1]-48)*10+(s4[lim-1]-48);
	for(int i=1;i<lim-1;i++)
	{
		m=(s1[i]-48)*1000+(s2[i]-48)*100+(s3[i]-48)*10+(s4[i]-48);
		c=(n1*m+n2)%257;
		cout<<c;
	}
	cout<<'\n';
}
