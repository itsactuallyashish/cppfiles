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
                     for(int i=0;i<n;i++)see(v[i]);
             ll cnt=0;
             vector<int>tmp;
             tmp.push_back(1);
             for(int i=0;i<n;i++){
                if(v[i]==0) continue;
                else tmp.push_back(v[i]);
             }
             for(int i=1;i<tmp.size();i++){
                  if(tmp[i]<0 && tmp[i-1]>0) cnt++;
                 
             }
             ll sum=0;
             for(int i=1;i<tmp.size();i++){
                    sum+=abs(tmp[i]);
             }
             put(sum,cnt);
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
