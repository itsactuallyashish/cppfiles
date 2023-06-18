#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int mx=1e6+10;
vector<vector<int>>divisorof(mx);

void sieve(){
    for(int i=2;i<mx;i++){
        if(divisorof[i].size()==0){
            divisorof[i].push_back(i);
            for(int j=2*i ;j<mx;j+=i){
                divisorof[j].push_back(i);
            }
        }
    }
}
int main(){
    sieve();
    int n; cin>>n;
    vector<int> values(n);
    for(auto & in :values) cin>>in;
    vector<int> primesof(mx,0);
    vector<int>countofcombinations(mx,0);
    for(int i=0;i<n;i++){
        for(int mask=1;mask<(1<<(divisorof[values[i]].size()));mask++){
            int combination=1;
            int cnt=0;
            for(int x=0;x<(int)divisorof[values[i]].size();x++){
                    if(mask & (1<<x)){
                        combination *= divisorof[values[i]][x];
                        cnt++;
                    }
            }
            countofcombinations[combination]++;
            primesof[combination]=cnt;


        }
    }
    ll validcnt=0;
    for(int i=0;i<mx;i++){
        if(primesof[i]==0) continue;
        if(primesof[i]%2) validcnt+=(countofcombinations[i] * 1LL * (countofcombinations[i]-1))/2;
        else validcnt-=(countofcombinations[i] * 1LL * (countofcombinations[i]-1))/2;
    }
    ll totalcnt = (n * 1ll* (n-1) )/2;
    totalcnt-=validcnt;
    cout<<totalcnt;
}