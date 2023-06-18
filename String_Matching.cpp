#include<iostream>
#include<vector>
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
int kmp(string &s,string &p){
    int cnt=0;
    int i=0,j=0;
     vector<int> lps=build_lps(p);
    while(i<s.size()){
        if(s[i]==p[j]){
            i++;j++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
        if(j==p.size()){
            cnt++;
            j=lps[j-1];
        }
    }
    return cnt;
}
int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s,p;
    see(s,p);
    int ans=kmp(s,p);
    put(ans);


}