#include<bits/stdc++.h>
using namespace std;
int N;
#define ll long long
vector<ll>A;
 int tree[1000006],n;
        void build(){
            for(int i=n-1;i>0;i--)
              tree[i]=tree[2*i]+tree[2*i];
        }

        void update(int in,int val){
            in+=n;
            tree[in]+=val;
            while(in>1){
                in>>=1;
                tree[in]=tree[2*in]+tree[2*in+1];
            }

        }
        int sum(int l,int r){
           int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
        }
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N;
        A.resize(N);
        int sz=A.size();
        for(auto &x:A) cin>>x;
        vector<ll>rank(A);
         ll ans=0;
        sort(rank.begin(),rank.end());
        rank.erase(unique(rank.begin(),rank.end()),rank.end());
        unordered_map<int,int> mp;
        for(int i=0;i<rank.size();i++){
            mp[rank[i]]=i;
        }
        n=200005;
        memset(tree,0,sizeof(tree));
        build();
        
        for(int i=sz-1;i>=0;i--){
            update(mp[A[i]],1);
            ans+=sum(0,mp[A[i]]);
           
        }
        cout<<ans<<"\n";
    }

}