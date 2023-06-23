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
        int n,k,d;
        see(n,k,d);
        vector<int>a;
        for(int i=1;i<=n*k;i++){
                int x;see(x);
                // if((x+d)%d !=(x-d)%d){
                //     put(-1);
                //     return;
                // }
                a.push_back(x);
        }
        sort(all(a));
        int median = a[(a.size()-1)/2];
        
        ll ans=0;
        for(int i:a){
            ans += abs(i-median);
        }
        if(ans%d==0){

        put(ans/d);
        }else put(-1);

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
