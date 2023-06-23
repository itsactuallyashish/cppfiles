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
            vector<ll>v;
            for(int i=0;i<n;i++){
                ll x;see(x);
                v.push_back(x);
            }
            for(int i=1;i<n;i++){
                if(v[i]<v[i-1]){
                    v[i]=-v[i];
                }
            }
            int cnt=0;
           
            for(int i=1;i<n;i++){
                 if(v[i-1]*v[i]<0){
                    cnt++;
                 }
            }
            if(cnt>2){
                put("no");return;
            }
            int s,e=n;
            cnt=2;
            for(int i=1;i<n;i++){
                if(v[i]*v[i-1]<0){
                    if(cnt==2){
                        s=i;
                        cnt--;
                    }else {
                       e=i+1;
                    }
                }
            }
            putl("yes");
            put(s,e);
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
