#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}

vector<int> build_lps(string &s){
    int m= s.size();
    vector<int>lps(m);
    int i=1,j=0;
    while(i < m){
            if(s[i]==s[j]){
                lps[i]=j+1;
                j++;i++;
            }else{
                if(j!=0){
                    j= lps[j-1];
                }
                else{
                    lps[j]=0;
                    i++;
                }
            }
    }
    return lps;
}

int main(){
    string s; see(s);
    vector<int>lps= build_lps(s);
    int j=s.size()-1;
    set<int>st;
     while( j >0){
        if(lps[j]!=0)
        st.insert(lps[j]);
        j=lps[j]-1;
     }
    for(auto x:st)
     put(x);

}