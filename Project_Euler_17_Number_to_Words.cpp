#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, string> mp;
string ans = "";

string helper(char b){
    string res="";
    if (b == '0')
    {
        res = "";
    }
    else if (b == '1')
    {
        res = "One";
    }
    else if (b == '2')
    {
        res = "Two";
    }
    else if (b == '3')
    {
        res = "Three";
    }
    else if (b == '4')
    {
        res = "Four";
    }
    else if (b == '5')
    {
        res = "Five";
    }
    else if (b == '6')
    {
        res = "Six";
    }
    else if (b == '7')
    {
        res = "Seven";
    }
    else if (b == '8')
    {
        res = "Eight";
    }
    else if (b == '9')
    {
        res = "Nine";
    }
    return res;
}
string get2(char a, char b)
{
    string res;
    if (a == '1')
    {
        if (b == '0')
        {
            res = "Ten";
        }
        else if (b == '1')
        {
            res = "Eleven";
        }
        else if (b == '2')
        {
            res = "Twelve";
        }
        else if (b == '3')
        {
            res = "Thirteen";
        }
        else if (b == '4')
        {
            res = "Fourteen";
        }
        else if (b == '5')
        {
            res = "Fifteen";
        }
        else if (b == '6')
        {
            res = "Sixteen";
        }
        else if (b == '7')
        {
            res = "Seventeen";
        }
        else if (b == '8')
        {
            res = "Eighteen";
        }
        else if (b == '9')
        {
            res = "Nineteen";
        }
    }else if(a=='0'){
        return ""+helper(b);
    }
    else if(a=='3'){
        res="Thirty " +helper(b);
    }
    else if(a=='5'){
        res="Fifty " +helper(b);
    }else if(a=='2'){
        res="Twenty "+helper(b);
    }
    else if(a=='8'){
        res="Eighty "+helper(b);
    }
    else
    {
        res = helper(a) + "ty" + " " + helper(b);
    }
    return res;
}
string get(char ch)
{
    string res;
    if(ch=='0') return "";
    res = helper(ch) + " " + "Hundred";
    return res;
}
void solve(string s){
    ans="";
    mp[3]="Thousand";
    mp[6]="Million";
    mp[9]="Billion";
    mp[12]="Trillion";
    int l=s.size();
    int rem=l%3;
    if(rem==2){
        ans+=get2(s[0],s[1])+" ";
        if(mp.find(l-rem)!=mp.end()){
            ans+=mp[l-rem]+" ";
        }
    }
    else if(rem==1){
        ans+=helper(s[0])+" ";
        if(mp.find(l-rem)!=mp.end()){
            ans+=mp[l-rem]+" ";
        }
    }
    for(int i=rem;i<l;i+=3){
        if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0') continue;
        ans+=get(s[i]) +" "+ get2(s[i+1],s[i+2])+ " ";
        if(mp.find(l-i-1-2)!=mp.end()){
            ans+=mp[l-i-1-2]+" ";
        }
        
    }
    cout<<ans<<"\n";
    
}

int main()
{
    string x;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x;
        solve(x);
    }
    // cerr << get2('1', '7') << " " << get('3') << " " << get2('3', '7');
    return 0;
}