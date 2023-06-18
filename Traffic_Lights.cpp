#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()

void solve()
{
    ll n,k;see(n,k);
    vector<ll>lights(k);
    for(auto &it:lights) cin>>it;
    set<ll>st{0,n};
    for(auto it:lights) st.insert(it);
    ll max_gap=0,pre=0;
    for(auto it:st){
        max_gap=max(max_gap,it-pre);
        pre=it;
    }
    vector<ll>gap(k);
    gap.back()=max_gap;
    for(int i=k-1;i>0;i--){
        st.erase(lights[i]);
        auto it=st.upper_bound(lights[i]);
        ll high = *it;
        ll low= *(--it);
        max_gap = max(max_gap,high-low);
        gap[i-1]=max_gap;
    }
    for(int i=0;i<k;i++) put(gap[i]);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
        cout << '\n';
    }
}
