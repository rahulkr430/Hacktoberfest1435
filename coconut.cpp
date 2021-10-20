#include<bits/stdc++.h>
using namespace std;
int main()

{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int water,pulp;
        water=c/a;
        pulp=d/b;
        int ans=water+pulp;
        cout<<ans<<endl;
    }
}