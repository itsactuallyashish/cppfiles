#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mx=10e6+1;
int ar[mx];

int solve(int x){
    int cnt=0;
        if(x==1) return 1;
        for(int i=1;i*i<=x;i++){
            if(x % i ==0){
                if(i == x/i){
                    cnt+=1;
                }
                else cnt+=2;
            }
        }
        return cnt;
}
ll test(int y){
    ll tnum;
 for(int t=2;;t++){
         tnum=t*(t+1)/2;
        int cnt;
        if(t%2==0){
            cnt=solve(t/2)*solve(t+1);
        }
        else{
            cnt=solve(t)*solve((t+1)/2);
        }
        
        if(cnt > y) break;
    }
    return tnum;
}

int main(){
    int t; cin>>t;
    
   
    while(t--){
        int x;
        cin>>x;
       cout<<test(x)<<endl;
    }
    
}