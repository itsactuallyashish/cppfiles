#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = int(1e9) + 7;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	int lim = 1;
	while (lim * (lim + 1) < k * 2) ++lim;
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(2 * lim + 1, vector<int>(k + 1)));
	dp[0][lim][0] = 1;
	forn(ii, n){
		int i = ii & 1;
		int ni = i ^ 1;
		dp[ni] = vector<vector<int>>(2 * lim + 1, vector<int>(k + 1));
		forn(j, 2 * lim + 1) forn(t, k + 1) if (dp[i][j][t]){
			forn(z, 2){
				int nj = j + z - a[ii];
				int nt = t + abs(nj - lim);
				if (nt <= k) dp[ni][nj][nt] = add(dp[ni][nj][nt], dp[i][j][t]);
			}
		}
	}
	int ans = 0;
	for (int t = k & 1; t <= k; t += 2)
		ans = add(ans, dp[n & 1][lim][t]);
	printf("%d\n", ans);
	return 0;
}