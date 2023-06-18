#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
int main(){
    int n=3;
    for(int i=0;i<(1<<n);i++){
        int u=i/2;
        put(1<<n,1<<n-1,(1<<n-1)-1);
        int v=i&((1<<n-1)-1);
        // int v=(1<<(n-1))-1;// debruijn sequence is 0101 if from 010 -> 101 generate all possible sequence and add edge like this;
        put(u,v,"\n");
    }
}