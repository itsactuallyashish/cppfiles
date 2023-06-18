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
bool  solve(P p1,P p2,P p3 ,P p4){
    if((p3-p4)*(p2-p1)==0){
        if(p1.collinear(p2,p3) ){
            for(int r=0;r<2;r++){
             if( max(p1.x,p2.x) < min(p3.x,p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
                return false;
             }
             swap(p1,p3);
             swap(p2,p4);
            }
           return true;
        }
        return false;
    }else{

    
        for(int rep=0;rep<2;rep++){
            ll sign1=(p1-p2)*(p1-p3);
            ll sign2=(p1-p2)*(p1-p4); 
            if((sign1>0 && sign2>0) || (sign1<0 && sign2<0)){
                return false;
            }
            swap(p1,p3);
            swap(p2,p4);
        }
             return true;
    }
 
}
int main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<P>pnts(n);
    for(auto &a:pnts) {
        a.read();
    }
    for(int x=0;x<m;x++){
        P l;
        l.read();
        P p0={l.x+1,3000000000};
        int cnt=0;
        for(int i=0;i<n;i++){
            int j=i+1==n?0:i+1;
            if(pnts[i].collinear(pnts[j],l)){
                if(min(pnts[i].x,pnts[j].x)<=l.x && max(pnts[i].x,pnts[j].x)>=l.x && min(pnts[i].y,pnts[j].y)<=l.y && max(pnts[i].y,pnts[j].y)>=l.y)
                {
                    cout<<"BOUNDARY\n";
                    cnt=-1;break;
                }
            }
            else {
               cnt+=solve(l,p0,pnts[i],pnts[j]);
            }
        }
        if(cnt==-1) continue;
        if(cnt%2==0) cout<<"OUTSIDE\n"; 
        else  cout<<"INSIDE\n"; 
        
    }
}