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
void solve(){
     P p1,p2,p3,p4;
    p1.read();p2.read();p3.read();p4.read();
    if((p3-p4)*(p2-p1)==0){
        if(p1.collinear(p2,p3) ){
            for(int r=0;r<2;r++){
             if( max(p1.x,p2.x) < min(p3.x,p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
                cout<<"NO\n";
                 return;
             }
             swap(p1,p3);
             swap(p2,p4);
            }
            cout<<"YES\n";
            return;
        }
        cout<<"NO\n";
    }
    else{
        for(int rep=0;rep<2;rep++){
            ll sign1=(p1-p2)*(p1-p3);
            ll sign2=(p1-p2)*(p1-p4); 
            if((sign1>0 && sign2>0) || (sign1<0 && sign2<0)){
                cout<<"NO\n";return;
            }
            swap(p1,p3);
            swap(p2,p4);
        }
        cout<<"YES\n";
        return;
    }
}
int main(){
  int t;cin>>t;
  while(t--){
    solve();
  }
}