#include<vector>
#include<iostream>
#define ll long long
using namespace std;
const int sunday =1;

int getweekday(int m,ll y,int q){
    if(m<=2){
        y--;
        m+=12;
    }
    return (q+ 13*(m+1)/5 + y + y/4 -y/100 + y/400)%7;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll y1,y2;
        int m1,m2,d1,d2;
        cin>>y1>>m1>>d1;
        cin>>y2>>m2>>d2;
        if(y1>y2 || (y1==y2 && m2 < m1)){
            swap(y1,y2);
            swap(m1,m2);
        }
        if(d1>1){
            m1++;
            if(m1>12){
                y1++;
                m1-=12;
            }
        }
        ll sum=0;
        while(y1<y2 || m2>m1){
                if(getweekday(m1,y1,1)==sunday) sum++;
                m1++;
                if(m1>12){
                    y1++;
                    m1-=12;
                }
        }
        if(getweekday(m1,y1,1)==sunday) sum++;
        cout<<sum<<"\n";
    }
}