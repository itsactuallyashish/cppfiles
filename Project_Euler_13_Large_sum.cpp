#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main(){
    int t; cin>>t;
    vector<string>mat;
    for(int i=0;i<t;i++){
        string s;
        for(int j=0;j<50;j++){
            char ch; cin>>ch;
            // cout<<ch;
            s.push_back(ch);
            
        }
        mat.push_back(s);
        // cerr<<s<<endl;
    }
    // cout<<mat[0][0];
    int ans[50];
    ll num=0;
    for(int j=49;j>=0;j--){
        
        for(int i=0;i<t;i++){
            num+=mat[i][j]-'0';
        }
        ans[j]=num%10;
        num=num/10;
    }
    ans[0]+=num*10;
    string xx= to_string(ans[0]);
    // cout<<xx.size();
    cout<<ans[0];
    for(int i=1;i<=10-xx.size();i++){
        cout<<ans[i];
    }


}