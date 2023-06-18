#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mx = 35e6 + 1;
ll mxpro=1;
bool valid(int i,int j){
    if(i>=0 && i<20 && j>=0 && j<20){
        return true;
    }
    return false;
    
}
    int grid[20][20];
int x[]={0,1,1,1};
int y[]={1,0,1,-1};
ll product(int i,int j,int dx,int dy){
    ll pro=1;
    for(int k=0;k<4;k++,i+=dx,j+=dy){
        if(valid(i,j))
            pro=pro*grid[i][j];
        else{
            pro=1;
            break;
        }
    }
    return pro;
}
int main()
{
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++)
        {
            string s;
            cin >> s;
            grid[i][j] = stoi(s);
        }
    }   

    for(int i=3;i<20;i++){
        for(int j=3;j<20;j++){
             mxpro=max(mxpro,product(i,j,0,1));
             mxpro=max(mxpro,product(i,j,1,1));
             mxpro=max(mxpro,product(i,j,1,-1));
             mxpro=max(mxpro,product(i,j,1,0));
                
                
                
        }
    }
    
    cout<<mxpro;
}