#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int mx = 89e6;
bool ar[mx];
vector<int> primes;
void sieve(){
    //if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    int x;
    sieve();

    for (int i = 0; i < q; i++)
    {
        cin >> x;
        cout << primes[x - 1] << "\n";
    }
}