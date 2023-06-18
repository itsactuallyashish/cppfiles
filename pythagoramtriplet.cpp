#include<iostream>
using namespace std;
int main(){
    long long ans=-1;
    int s=1000;
    int a,b;
        for(int c=1;c<s;c++){
            b=s/2;
            b=b*(s-2*c)/(s-c);
            a=s-b-c;
            if(a*a ==b*b + c*c){
                ans=a*b*c;
                break;
            }
        }   
        cout<<ans;
        
}