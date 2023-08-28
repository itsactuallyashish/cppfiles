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
        int n,m,h;
        see(n,m,h);
        vector<pair<int,int>>ans;
        pair<int,int>tt;
        for(int i=0;i<n;i++){
            vector<int>v(m);
            for(auto &in:v) see(in);
            sort(all(v));
            int t=0,ii=0;
            int p=0;
            for(auto in:v){
                if((t+in)<=h){
                    p+=(t+in);
                    t+=(in);
                    ii++;
                }else break;
            }
            if(i==0) tt={ii,-1*p};
            ans.push_back({ii,-1*p});
        }
        sort(all(ans),greater<pair<int,int>>());
        for(int i=0;i<n;i++){
            // deb2(ans[i].first,ans[i].second);
            if(ans[i].first==tt.first and ans[i].second==tt.second){
              put(i+1);
                break;
            }
        }
    

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
