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
            ll n;see(n);
            if(n==3){
                    put("NO");
                    return;
            } 
            int i=2;
            ll lo=2,high=sqrt(n);
            bool flag=0;
            while(lo<=high){
                ll mid=lo + (high-lo)/2;
                ll ans=1;
                ll t=mid;
                 ans+=t;
                while(ans+t*mid<=n){
                    ans+=t*mid;
                    t=t*mid;
                }
                if(ans>n) high=mid-1;
                else if(ans==n) {
                    flag=1;
                    lo=mid+1;
                }
                else lo=mid+1;

            }
            ll ans=1;
             ll t=lo;
                 ans+=t;
                while(ans+t*lo<=n){
                    ans+=t*lo;
                    t=t*lo;
                }
            if(ans==n || flag) put("YES");
            else
            put("NO");
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
