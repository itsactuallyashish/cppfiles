#include <bits/stdc++.h>
using namespace std;

template<class T> struct SegTree {
	T U = 1e9; T F(T a, T b) { return min(a,b); }
	int N; vector<T> t; SegTree() {}
	SegTree(int N) : N(N), t(4*N,U) {}
	void upd(int I, T V) { upd(I,V,1,1,N); }
	void upd(int I, T V, int i, int l, int r) {
		if(l==r) { t[i]=V; return; } int m=(l+r)/2;
		if(I<=m) upd(I,V,i*2,l,m);
		else upd(I,V,i*2+1,m+1,r);
		t[i] = F(t[i*2], t[i*2+1]); }
	T qry(int L, int R) { return qry(L,R,1,1,N); }
	T qry(int L, int R, int i, int l, int r) {
		if(L<=l && r<=R) return t[i];
		if(R<l || L>r) return U; int m=(l+r)/2;
		return F(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r)); }
};
const int mx=2e5+2;
int n,q;
vector<int> p(mx);
SegTree<int> down,up;
void pull(int i){
    down.upd(i,p[i]-i);
    up.upd(i,p[i]+i);
}
int main(){
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin>> p[i];
    down=up=SegTree<int>(n);
    for(int i=1;i<=n;i++) pull(i);
    while(q--){
        int t,x; cin >> t;
        if(t ==1){
            int k,x;
            cin>> k >> x;
        p[k]=x;
        pull(k);
        }
        else{
            int k; cin >> k;
            int D=down.qry(1,k)+k;
            int U=up.qry(k,n)-k;
            cout<< min(D,U) << "\n";
        }
    }
}
