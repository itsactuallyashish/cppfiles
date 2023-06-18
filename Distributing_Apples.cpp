#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
void toh(int,int,int,int);
const int mod = 1e9+7;
const int N = 3e5, M = N;
//=======================
 
vi g[N];
int a[N];
const int MAXN = 2e6+1;
const int MOD = 1e9 + 7;
 
ll fac[MAXN + 1];
ll inv[MAXN + 1];
inline void add(int& x, int y)
{
	x += y;
	if (x >= mod) x -= mod;
}
 
inline void sub(int& x, int y)
{
	x -= y;
	if (x < 0) x += mod;
}
 
inline int mult(int x, int y)
{
	return x * (long long) y % mod;
}
 
 
inline long long power(int x, int k, long long n)
{
	int64_t res = 1;
	while(k--) res *= x;
	if (res > n) res = n + 1;
	return (long long) res;
}
 
ll exp(ll x, ll y, ll p) {
	ll res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x;
		x %= p;
		y >>= 1;
	}
	return res;
}
 
void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
}
 
void inverses() {
	inv[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		inv[i] = exp(fac[i], MOD - 2, MOD);
	}
}
 
 
 
void solve() {
	factorial();
	inverses();
int n,m;
cin>>n>>m;
ll ans;
ans=mult(mult(fac[n+m-1],inv[m]),inv[n-1]);
 
cout<<ans;
}
  
    
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
    //  cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
 
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
 
void ipgraph(int n, int m){
	int  u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}
 
void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}