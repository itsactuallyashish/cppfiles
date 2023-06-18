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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using indexed_set= tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
    ll n,k;see(n,k);
    vector<pair<ll,ll>>val,st;
    for(int i=0;i<n;i++){
        ll x;see(x);
        st.push_back({x,i});
    }
    for(int i=0;i<k;i++){
        val.push_back(st[i]);
    }
    sort(all(val));
    if(k==1){
        for(int i=0;i<n;i++)
            put(0);
            return ;
    }
    if(k==2){
        for(int i=1;i<n;i++)
            put(abs(st[i].first - st[i-1].first));
        return;
    }
    set<pair<ll,ll>>left,right;
    ll leftsum=0,rightsum=0;
    for(int i=0;i<k/2 +(k%2);i++){
            left.insert(val[i]);
            leftsum+=val[i].first;
    }
    
    for(int i=k/2 + (k%2);i<k;i++){
            right.insert(val[i]);
            rightsum+=val[i].first;
    }
    put(left.rbegin()->first * left.size() - leftsum + rightsum - left.rbegin()->first*right.size());
    for(int i=1;i<n-k+1;i++){
        if(left.count(st[i-1])){
                left.erase(st[i-1]);
                leftsum-=st[i-1].first;
        }else{
                right.erase(st[i-1]);
                rightsum-=st[i-1].first;
        } 
        if(left.rbegin()->first < st[i+k-1].first){
                right.insert(st[i+k-1]);
                rightsum+=st[i+k-1].first;
        }else {
              left.insert(st[i+k-1]);
              leftsum+=st[i+k-1].first;
        }
        while(left.size() < k/2 + (k%2)){
               pair<ll,ll> z = *(right.begin());
               left.insert(z);
               leftsum+=z.first;
               right.erase(z);
               rightsum-=z.first;
        }
        while(left.size() > k/2 + (k%2)){
               auto it = left.rbegin();
               pair<ll,ll> tmp = *it;
               leftsum-=tmp.first;
               rightsum+=tmp.first;
               left.erase(tmp);
               right.insert(tmp);
        }
        put(left.rbegin()->first * left.size() - leftsum + rightsum - left.rbegin()->first*right.size());
    }


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
