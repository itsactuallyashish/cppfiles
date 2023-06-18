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

struct customer{
    ll l,r;
    int id;
    bool operator<(const customer &other)const {
            if(l==other.l){
                 return r>other.r;
            }
            return l<other.l;
    }
};
void solve() {
        int n;see(n);
        vector<customer>customers;
        for(int i=0;i<n;i++){
            ll l,r;
            see(l,r);
            customers.push_back({l,r,i});
        }
        sort(all(customers));
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        int roomid=1;
        int roomallocated[n];
        for(int i=0;i<n;i++){
            if(pq.size()==0){
                roomallocated[customers[i].id]=roomid;
                pq.push({customers[i].r,roomid});
                roomid++;
            }else{
                if(pq.top().first < customers[i].l){
                        roomallocated[customers[i].id]=pq.top().second;
                        pq.push({customers[i].r,pq.top().second});
                        pq.pop();
                }else{
                    roomallocated[customers[i].id]=roomid;
                    pq.push({customers[i].r,roomid});
                    roomid++;
                }
            }
        }
        putl(roomid-1);
        for(int i=0;i<n;i++) put(roomallocated[i]);
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
