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

    struct team{
        int pb,t;
        bool operator <(const team&other){
            if(other.pb==pb){
                return t <other.t;
            }else return pb>other.pb;
        }
    };
void solve() {
        int n,k;see(n,k);
        vector<team>teams,tmp;
        for(int i=0;i<n;i++){
            int x,y;
            see(x,y);
            teams.push_back({x,y});
        }
        sort(all(teams));
        // for(auto in:teams){
        //     putl(in.pb,in.t);
        // }
        int rank=1;
        int rnk[n+1]={0};
        pair<int,int>last;
        last.first=teams[0].pb;
        last.second=teams[0].t;
        rnk[0]=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(teams[i].pb==last.first && teams[i].t==last.second){
                cnt++;
                continue;
            }else{
                last ={teams[i].pb,teams[i].t};
                rnk[i-1]=cnt;
                cnt=1;
            }
        }
        if(last.first ==teams[n-1].pb && last.second==teams[n-1].t){
                rnk[n-1]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            if(rnk[i]==0){
                rnk[i]=rnk[i+1];
            }
        }
        put(rnk[k-1]);
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
