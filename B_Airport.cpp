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
        priority_queue<int,vector<int>>pq;
        priority_queue<int,vector<int>,greater<int>>pqq;
        for(int i=0;i<m;i++){
            int x;see(x);
            pq.push(x);
            pqq.push(x);
        }
        int mncost=0,mxcost=0;
        while(n--){
            int x=pq.top();
            pq.pop();
            mxcost+=x;
            x--;
            if(x>0)
            pq.push(x);

            int xx=pqq.top();
            pqq.pop();
            mncost+=xx;
            xx--;
            if(xx>0)
                pqq.push(xx);
        }
        put(mxcost,mncost);
    
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
