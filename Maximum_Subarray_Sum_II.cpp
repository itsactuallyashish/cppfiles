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
const long long inf=LONG_LONG_MIN;

void solve() {
        ll n,a,b;
        see(n,a,b);
        ll val[n];
        for(int i=0;i<n;i++) see(val[i]);
        ll pre[n+1];
        pre[0]=0;
        for(int i=1;i<=n;i++){
             pre[i]=pre[i-1]+val[i-1];
        }
        set<pair<ll,ll>>st;
        for(int i=a; i<=b;i++){
            st.insert({pre[i],i});
        }
        ll sum,maxsum=-inf;
        for(int i=1;i<=n-a+1;i++){
            sum = st.rbegin()->first - pre[i-1];
            st.erase({pre[i+a-1],i+a-1});
            if(i+b<=n)
            st.insert({pre[i+b],i+b});
            maxsum=max(maxsum,sum);
        }
        put(maxsum);
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
