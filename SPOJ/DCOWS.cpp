// Straightforward dp

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937
rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){	// l, r inclusive
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
const int N = 5005;
 
ll dp[N][N], a[N], b[N];
 
signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	int n, m;	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int j = 1; j <= m; j++)
		cin >> b[j];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = min({dp[i-1][j-1] + abs(a[i]-b[j]), dp[i][j-1]});
		}
	}
	cout << dp[n][m] << endl;
    return 0;
} 
