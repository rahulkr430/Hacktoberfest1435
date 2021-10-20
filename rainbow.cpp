#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int i=0;
        for(int i=0;i<n;i++)
        cin>>a[i];
        if(a[0]==1 &&  a[n-1]==1 && a[n/2]==7)
        {
            for(i;i<n/2;i++)
            {
                if(a[i]!=a[n-1-i])
                    break;
                if(a[i+1]-a[i]>1)
                    break;
            }
        }
        if(i==n/2)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
}
}
