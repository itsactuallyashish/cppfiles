//ItsactuallyAshish
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,M;
vector<ll>x;
bool ispossible(int mdis){
          ll last_pos=-1;
          ll cows=M;
          for(int i=0;i<N;i++){
             if(x[i]-last_pos >= mdis || last_pos==-1){
                cows--;
                last_pos=x[i];
             }
             if(cows==0) break;

          }
          return cows==0;
}

int main(){
     int t;
     cin>>t;
     while(t--){
    cin>>N>>M;
    x.resize(N);
    
   for(int i=0;i<N;i++){
        cin>>x[i];
   }
   sort(x.begin(),x.end());
    ll s=0,e=1e9;
    while(e>s+1){
        ll mid=s+(e-s)/2;
        if(ispossible(mid)){
            s=mid;
        }
        else{
            e=mid-1;
        }
    }  
    if(ispossible(e)){
        cout<<e<<endl;
    }  
    else{
        cout<<s<<endl;
    }
    
 }
}