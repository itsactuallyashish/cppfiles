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
            int n,m;
            see(n,m);
            queue<int>q;
            int val[n];
            for(int i=1;i<=n;i++){
                see(val[i-1]);
                q.push(i);
            }
            int last=-1;
            while(!q.empty()){
                int x=q.front();
                last = x;
                q.pop();
                if(val[x-1]>m){
                    val[x-1]-=m;
                    q.push(x);
                }
            }
            put(last);
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
