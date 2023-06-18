#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
struct P{
    ll x,y;
     void read(){
        cin>>x>>y;
    }
   bool operator<(const P & a)const{
        return make_pair(x,y)<make_pair(a.x,a.y);
    }

};
bool compare(const P&a,const P &b){
    return make_pair(a.y,a.x) < make_pair(b.y,b.x); 
}
void solve(vector<P>&pnts){
    if(pnts.size()==2){
        ll f1= abs(pnts[0].x-pnts[1].x);
        ll f2= abs(pnts[0].y-pnts[1].y);
        ll ans=f1*f1 + f2*f2;
        cout<<ans;


        return;
    }
    sort(pnts.begin(),pnts.end());
    int left=0;
    set<P,decltype(&compare)>box(&compare);
    box.insert(pnts[0]);
   double best=(ll)1<<60;
    for(int i=1;i<(int)pnts.size();i++){
        while(left<i && pnts[i].x- pnts[left].x>best){
            box.erase(pnts[left++]);
        }
        for(auto it=box.lower_bound({pnts[i].x-(ll)best,pnts[i].y-(ll)best});it!=box.end()&& pnts[i].y+(ll)best>=it->y;it++){
          double dis=sqrt(pow(it->x-pnts[i].x,2.0)+pow(it->y-pnts[i].y,2.0));
            best = min(best,dis);
        }
        box.insert(pnts[i]);
    }
    long long sq=llround(pow(best,2.0));
    cout<<sq;
   

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    vector<P>pnts(n);
    for(auto &in:pnts) in.read();
    solve(pnts);
}