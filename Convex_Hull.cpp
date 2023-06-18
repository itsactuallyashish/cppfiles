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
    P operator-(const P & b){
        return {x-b.x,y-b.y};
    }
    void operator -=(const P &b){
        x-=b.x;y-=b.y;
    }
    ll operator *(const P &b)const{
        return x*b.y-y*b.x;
    }
    ll collinear( P &a, P&b){
        P xx=a-*this;
        P yy=b-*this;
        return xx*yy;
    }
    bool operator<(const P & a)const{
        return make_pair(x,y)<make_pair(a.x,a.y);
    }
};
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
int n;cin>>n;
    vector<P>pnts(n);
    for(auto &pnt:pnts){
        pnt.read();
    }
    sort(pnts.begin(),pnts.end());
    vector<P>hull;
    for(int rep=0;rep<2;rep++){
        int s=hull.size();
        for(auto p:pnts){
            while((int)hull.size()>=s+2){
                P a=hull.end()[-2],b=hull.end()[-1];
                if(a.collinear(b,p)<=0) break;
                hull.pop_back();
            }
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(pnts.begin(),pnts.end());
    }
    put(hull.size());
    cout<<"\n";
    for(auto p:hull){
        put(p.x,p.y);
        cout<<"\n";
    }
}