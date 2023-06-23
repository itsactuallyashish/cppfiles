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
            int n,m;see(n,m);
            vector<pair<int,int>>seg(m);
            for(int i=0;i<m;i++){
                see(seg[i].first,seg[i].second);
            }
            int q;see(q);
            vector<int>qu(q);
            for(int i=0;i<q;i++){
                see(qu[i]);
                qu[i]--;
            }
            int ans=-1;
            int start=0,end=q-1;
            while(start<=end){
                int mid = start + (end - start)/2;
                vector<int>t(n+1,0);
                for(int i=0;i<=mid;i++){
                        t[qu[i]]=1;
                }
                vector<int>pre(n+1,0);
                for(int i=1;i<=n;i++){
                    pre[i]=pre[i-1]+t[i-1];
                }
                bool good =false;
                for(auto s:seg){
                    if((pre[s.second] -pre[s.first-1])>(s.second - s.first+1)/2){
                        good =1;
                    }
                }
                if(good){
                    ans = mid+1;
                    end = mid-1;
                }else start =mid+1;
            }
            put(ans);
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
