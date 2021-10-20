#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,rc=0,gc=0,bc=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                rc+=1;
            }
            else if(s[i]=='G'){
                gc+=1;
            }
            else if(s[i]=='B'){
                bc+=1;
            }
        }
        int m=max(rc,max(bc,gc));
        cout<<n-m<<"\n";
    }
}