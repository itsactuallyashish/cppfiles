#include <iostream>
#include <vector>
using namespace std;
long long  sgt[1000009];
int n;
int query(int l, int r)
{
   
   int res=0;
     for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += sgt[l++];
    if (r&1) res += sgt[--r];
  }
   return res;
}
void update(int in, int val)
{
   in += n;
   sgt[in] = (val%2==0);
   while (in > 1)
   {
      in >>= 1;
      sgt[in] = sgt[2 * in] + sgt[2 * in + 1];
   }
   return;
   
}

int main()
{
   int q, l, r;
   cin >> n;
   vector<long long> ar(n);
   for (auto &e : ar)
      cin >> e;
   cin >> q;
   for (int i = 0; i < n; i++)
   {
      sgt[i + n] = (ar[i]%2==0);
   }
   for (int i = n - 1; i >= 1; i--)
      sgt[i] = sgt[2 * i] + sgt[2 * i + 1];

   while (q--)
   {
      int code;
      cin >> code;
      if (code == 0)
      {
         int in, val;
         cin >> in >> val;
         in--;
         update(in, val);
      }
      else if (code == 1)
      {
         int l, r;
         cin >> l >> r;
         l--;
           cout<< query(l,r)<<"\n";
        
      }
      else if (code == 2)
      {
         int l, r;
         cin >> l >> r;
         l-- ;
         int ans;
         ans = r - l ;
         ans -= query(l, r);
          cout<<ans<<"\n";
        
      }
   }
}
