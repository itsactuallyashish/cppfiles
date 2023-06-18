#include <bits/stdc++.h>
using namespace std;
const int mx=1e5+3;
int ar[mx];
vector<bool>is_amicable(mx,0);
vector<int>sto(mx,0);
vector<long long>result(mx,0);
void sieve(){
    ar[0]=ar[1]=1;
    for(int i=2;i<mx;i++) ar[i]=i;
    for(int i=2;i*i<mx;i++){
        if(ar[i]==i){
            for(int j=i*i;j<mx;j+=i) {
                if(ar[j]==j) ar[j]=i;
            }
        }
    }
}
vector<int> factor(int x){
    vector<int>v;
    while(x!=1){
        v.push_back(ar[x]);
        x/=ar[x];
    }
    return v;
}
int gp(int p , int m){
    int xx = pow(p,m+1)-1;
    xx/=(p-1);
    return xx;
}

int solve(int x){
    
    int sm=1;
    vector<int>d=factor(x);
    int cnt=1;
    for(int i=1;i<(int)d.size();i++){
        if(d[i-1]==d[i]){
            cnt++;
        }else{
            sm=sm*gp(d[i-1],cnt);
            // ans=ans*(cnt+1);
            
            cnt=1;
        }
    }
    // ans=ans*(cnt+1);
    sm=sm*gp(d.back(),cnt);
    if(sm > x) sm-=x; 
    return sm;
}
    
int main(){
    sieve();
    for(int i=2;i<100001;i++){
        sto[i]=solve(i);
    }
    for(int i=2;i<100001;i++){
        if(sto[i]<mx && sto[i]>=0){
            if(i==sto[sto[i]] && i!=sto[i]){
                is_amicable[i]=1;
                is_amicable[sto[i]]=1;
            }
        }
    }
    for(int i=1;i<mx;i++){
           result[i]=result[i-1] +(is_amicable[i]?i:0);
        }

    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        cout<<result[x-1] <<"\n";
    }
}