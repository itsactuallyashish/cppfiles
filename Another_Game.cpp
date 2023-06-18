#include <iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            cnt+=a%2;
        }
        if(cnt) cout<<"first\n";
        else cout<<"second\n";
    }
}