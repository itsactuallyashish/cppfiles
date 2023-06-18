#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
uniform_int_distribution<int> uid(0,lim-1);
return uid(rang);
}
const int mod = 1e9+7;
//=======================
#define ll long long
#define pr pair<ll,ll>
#define prr pair<pr,ll>
int main() {
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
int n , m;
cin>>n>>m;
// rotating the axis by 45 degree since a guards can see the jewellery at an angle of -45 to + 45 degree 
vector<pair<pr,ll>> pnts;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    pnts.push_back({{x+y,y-x},i});// indexing the guards to indentify them
}
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    pnts.push_back({{x+y,y-x},-1});
}
// sort the guards and jew points on a line since a guard can see jew point ahead of it
sort(pnts.begin(),pnts.end(),[](prr a, prr b){
    return a.F.F!=b.F.F?a.F<b.F :a.F.S<b.F.S;
});
set<pr>vis_guard;
vector<bool> need_guard(n+1,false);
for(auto elem: pnts ){
  if(elem.S != -1){
    vis_guard.insert(make_pair(elem.F.S,elem.S));
    continue;
    }
    // auto it=lower_bound(vis_guard.begin(),vis_guard.end(),make_pair(elem.F.S,0))-vis_guard.begin();
    auto it=vis_guard.lower_bound(make_pair(elem.F.S,0));
    assert(it!=vis_guard.end());
   set<pair<ll,ll>>::iterator it2= it;
   it2++;
  
    if(it2!=vis_guard.end())
      continue;

      need_guard[it->S]=1;
}
int ans=0;
for(int i=0;i<n;i++)
ans+=!need_guard[i];

cout<<ans;
// cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
return 0;
}

