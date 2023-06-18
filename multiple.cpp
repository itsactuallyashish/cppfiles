#include<bits/stdc++.h>
using namespace std;
long long res=0;
int main(){
    string s;
    cin>>s;
    long long pro=1;
    int i=0,j=0;
    for(;;){
        if(i-j>=13) break;
        int x=s[i]-'0';
        if(x==0){
            i++;
            j=i;
            pro=1;
        }
        else{
            pro=pro*x;
            
            i++;
        }
        
    }
    // cerr<<i<<" "<<j<<"\n";
    long long newpro=0;
    while(true){
        if(i==s.size()) break;
        int x=s[i]-'0';
        int y=s[j]-'0';
        if(x==0){
             i++;
             j=i;
             pro=1;
                while(i<s.size()){
                    if(i-j>=13) break;
                    int xx=s[i]-'0';
                        if(xx==0){
                            i++;
                            j=i;
                            pro=1;
                        }
                        else{
                            pro=pro*xx;
                            i++;
                        }
                }
        }
        else{
            pro=pro/y;
            pro=pro*x;
            i++;
            j++;
            // cout<<pro<<"\n";
            newpro=max(newpro,pro);
        }
    }
    cout<<newpro;
}