#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()


void solve() {
        ll n,k;see(n,k);
        ll machines[n];
        for(int i=0;i<n;i++) see(machines[i]);
        auto check=[](ll n,ll machines[],ll x)->ll{
            ll ans=0;
                for(int i=0;i<n;i++){
                    ans += min(x/machines[i],(ll)1e9);
                }
                return ans;
        };
        ll low=1;
        ll high=1e18;
        ll amnt;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(n,machines,mid)>=k){
                amnt=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        put(amnt);
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
