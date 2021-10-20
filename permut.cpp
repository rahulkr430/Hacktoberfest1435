#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
 while(true)
 {
     int t;
     cin>>t;
     if(t==0)
     break;
     vector<int> a(t+1),b(t+1);
     string ans="ambiguous";
     for(int i=1;i<=t;i++){
         cin>>a[i];
         b[a[i]]=i;
     }
     for(int i=1;i<=t;i++)
     {
         if(a[i]!=b[i])
         ans="not ambiguous";
     }
     cout<<ans<<endl;
     
 }
}