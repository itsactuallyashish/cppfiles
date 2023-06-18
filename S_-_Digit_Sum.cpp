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
long long dp[10001][100];
int add(int i, int j){
    if((i+=j)>=mod)
    i-=mod;
    return i;
}
void init(int l,int d){
    dp[l][0]=1;
    for(int i=l-1;i>=0;--i){
        for(int j=0;j<d;++j)
         for(int k=0;k<10;k++)
          dp[i][j]=add(dp[i][j],dp[i+1][(j+k)%d]);
    }
}
int query(const string &s,int d){
    int ans=0,carry=0;
    int i=0;
    fo(i,(int)s.length()){
      for(int j=0;j<(s[i]-'0');j++)
      ans=add(ans,dp[i+1][(carry+j) %d]);
      carry =(carry+(s[i]-'0'))%d;

}
if(carry==0) ans++;
if(--ans<0) ans+=mod;
return ans;
}
int main() {
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
srand(chrono::high_resolution_clock::now().time_since_epoch().count());

string s;int d;
cin>>s>>d;
init((int)s.size(),d);
cout<<query(s,d)<<'\n';

// cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
return 0;
}

