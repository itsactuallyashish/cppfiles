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
        int n,d,h;
        see(n,d,h);
        vector<ll>x;
        for(int i=0;i<n;i++){
            ll a;see(a);
            x.push_back(a);
        }
        sort(all(x));
        int l=h+x[0];
        long double ans=0.0;
        for(int i=1;i<n;i++){
            if(x[i]<l){
                ll dd=l-x[i];
                dd = d*dd;
                long double area = (long double)dd/h;
                area =area *0.5*(l-x[i]);
                ans+=area;
            }
             l=x[i]+h;
        }
        long double tot= 0.5 * d*h * n;
       
        tot-=ans;
        cout<<fixed<<setprecision(7)<<tot;
        
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
