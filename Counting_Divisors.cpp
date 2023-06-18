#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=20e6;


int main(){
    int n;cin>>n;
    for(int j=0;j<n;j++){
        int x;cin>>x;
        int cnt=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(x/i==i) cnt+=1;
                else
                cnt+=2;
            }
            
        }
        cout<<cnt<<"\n";
    }
}