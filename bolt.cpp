#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    float k1,k2,k3,v;
	    cin>>k1>>k2>>k3>>v;
	    float var = 100.00/(k1*k2*k3*v);
	    float k = 9.575;
	    if(var>=k)
	    cout<<"NO"<<endl;
	    else
	    cout<<"YES"<<endl;
	}
	return 0;
}
