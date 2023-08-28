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
            int n;see(n);
        ll a[n];
        for(int i=0;i<n;i++) see(a[i]);
        ll sum=0,big=0;
        ll d=big;
        ll m;
        for(int i=0;i<n;i++){
            sum+=a[i];
            big =max(sum,big);
           ll diff=big-sum;
            if(diff>d){
                d=diff;
                m=big;
            }
        }
          put(m);
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
