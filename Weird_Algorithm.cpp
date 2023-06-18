#include<iostream>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2){
            n=n*3+1;
        }
        else n/=2;
    }
    cout<<1;
}