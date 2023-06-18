#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    bool collinear( P &a, P&b){
        P xx=a-*this;
        P yy=b-*this;
        return xx*yy==0;
    }
};
int main(){
    int n;cin>>n;
    vector<P>pnts(n);
    for(auto &pnt:pnts){
        pnt.read();
    }
    long double area=0;
    for(int i=0;i<n;i++){
        area+=pnts[i]*pnts[i+1==n?0:i+1];
    }
    area=abs(area)/2.0;
    ll pnt_bound=0;
    for(int i=0;i<n;i++){
        int j=i+1==n?0:i+1;
        pnt_bound+=__gcd(abs(pnts[i].x-pnts[j].x),abs(pnts[i].y-pnts[j].y));
    }
    ll ans=area - (pnt_bound/2)+1;
    cout<<ans<<" " <<pnt_bound;

}