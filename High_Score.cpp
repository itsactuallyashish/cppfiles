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
const ll inf=1e17;
const ll ninf=-1*inf;
struct edge{
		int v,u;
		ll w;
};
void solve() {
		int n,m;
		see(n,m);
		if(n==1){
			put(-1);return;
		}
		vector<edge>g(m);
		for(int i=0;i<m;i++){
				see(g[i].u,g[i].v,g[i].w);
				g[i].w=-1*g[i].w;
		}
		vector<ll>d(n+1,inf);
		d[1]=0;
		for(int i=1;i<n;i++){
			for(auto e:g){
				int u=e.u;
				int v=e.v;
				ll w=e.w;
				if(d[u]==inf) continue;
				d[v]=min(d[v],d[u]+w);
				d[v]=max(d[v],ninf);
			}
		}
		// for -ve cycles
		for(int i=1;i<n;i++){
			for(auto e:g){
				int u=e.u;
				int v=e.v;
				ll w=e.w;
				if(d[u]==inf) continue;
				d[v] = max(ninf,d[v]);
				if(d[u]+w < d[v]){
					d[v]=ninf;
				}
			}
		}
		if(d[n]==ninf){
			put(-1);
			return;
		}
		put(-1*d[n]);

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
