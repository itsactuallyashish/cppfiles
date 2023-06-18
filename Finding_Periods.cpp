#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
struct hsh{
   const ll m= 1e9+7;
   const ll p=31;
    string s="";
    vector<ll>pre,bpow;
    int n;
    void read(){
        cin>>s;
    }
    void init(){
        n=s.size();
        pre.resize(n+1);
        bpow.resize(n+1);
        bpow[0]=1;
        for(int i=1;i<n;i++)
         bpow[i]=bpow[i-1]*p %m;
        for(int i=1;i<=n;i++){
            pre[i] = (pre[i-1]* p + s[i-1])%m;
        }
        
    }
    ll get_hash(int l,int r){
        ll h= pre[r+1] - (bpow[r-l+1]*pre[l]%m)%m;
        return h<0?h+m:h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    hsh st;st.read();st.init();
    int n=st.n;
	for (int i = 0; i < n; i++) {
		int curidx = 0;
		bool ok = true;
		while (curidx < n) {
			int len = min(i + 1, n - curidx);
			ok &= st.get_hash(0, len - 1) ==st.get_hash(curidx, curidx + len - 1);
			curidx += len;
		}
		if (ok) { put(i+1);}
	}
}