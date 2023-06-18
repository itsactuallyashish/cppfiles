#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    string s_new;
    s_new.push_back('@');
    for(auto &ch:s){
        s_new.push_back('#');
        s_new.push_back(ch);
    }
   s_new.push_back('#');
   s_new.push_back('$');
    vector<int>lps(s_new.size(),0);
    int c=0,r=0;
    int idx=-1,mx=0;
    int sz=s_new.size();
    for(int i=1;i<sz-1;i++){
        int mrr=c - ( i - c);
        if(i<r){
            lps[i]= min(lps[mrr],r-i);
        }
        while(0<=i-1-lps[i] && i+1+lps[i]<sz && s_new[i+1+lps[i]]==s_new[i-1-lps[i]])
            lps[i]++;
        if(i+lps[i]>r){
            c=i;
            r=i+lps[i];
        }
        if(lps[i]>mx){
            mx=lps[i];
            idx=i;
        }
    }
    int start = idx - mx+1;
    start= (start-2)/2;
    cout<<s.substr(start,mx);
}