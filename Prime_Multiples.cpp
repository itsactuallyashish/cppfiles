#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const ll siz =1e18;
int main(){
    ll n;cin>>n;
    int k;cin>>k;
    vector<ll>primes(k+1);
    for(auto &in :primes) cin>>in;
    vector<ll>sumofdivisors(k+1,0);
    for(int mask=1;mask< (1<<k);mask++){
        int cnt=0;
        ll tmp=n;
        for(int i=0;i<k;i++){
            if(mask &(1<<i)){
                cnt++;
                tmp/=primes[i];
            }
        }
        sumofdivisors[cnt]+=tmp;
    }
    ll ans=0;
    for(int i=1;i<=k;i++){
        if(i%2) ans+= sumofdivisors[i];
        else ans+= -1 * sumofdivisors[i];
    }
    cout<<ans;

}