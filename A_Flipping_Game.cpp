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
                 vector<ll>v(n);
                 for(auto &in :v)see(in);
            int sum=accumulate(all(v),0);
         int cnt =INT_MIN;
        for(int r=0;r<n;r++){
            for(int l=0;l<=r;l++){
                int c=sum;
                for(int k=l;k<=r;k++)
                     if(1-v[k]==1){
                        c++;
                     }else{
                        c--;
                     }
                cnt=max(cnt,c);
            }
        }
        put(cnt);
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
