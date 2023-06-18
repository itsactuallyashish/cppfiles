#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mx=35e6+1;
vector<int>primes;
bool ar[mx];
void sieve(){
    primes.pb(2);
    ar[0] = ar[1] = 1;
    for(int i = 3; i <= mx; i+=2){
        if(ar[i] == 0){
            primes.pb(i);
            if(i*(ll)1*i <= mx){
                for(int j = i*i; j <= mx; j += (2*i)){
                    ar[j] = 1;
                }
            }
        }
    }
}

int main(){
    long long res=0;
    sieve();
    // cout<<primes.size();
    for(auto in:primes){
        if(in>2000000) break;
        else res+=in;
    }
    cout<<res;
}