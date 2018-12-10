/*
Using digit dp maintain dp[i][sum] which is the number of i digit oe numbers with sum of digits as dp
and then dp[i+1][sum] is calculated
*/

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mod 1000000009
#define inf 1e18
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N = 200;

int dp[10][200], dd[10][200];

int oe(int n){
	string s = to_string(n);
	memset(dp, 0, sizeof dp);
	memset(dd, 0, sizeof dd);
	int l = s.length(), g = 100;
	if(l == 1)
		return (s[0]-'0')/2;
	int ans = 0;
	for(int i = 0; i <= 9; i++){
		if(i&1)	dp[1][-i+g] = 1;
		else	dp[1][i+g] = 1;
	}
	dd[1][N-1] = dp[1][N-1];
	for(int j = N-2; j >= 0; j--){
		dd[1][j] = dd[1][j+1] + dp[1][j];
		if(j <= 100) dd[0][j] = 1;
	}
	for(int i = 2; i < l; i++){
		for(int j = 0; j < N; j++){
			if(dp[i-1][j] == 0)	continue;
			for(int dig = 0; dig <= 9; dig++){
				if(dig&1)	dp[i][j-dig] += dp[i-1][j];
				else dp[i][j+dig] += dp[i-1][j];
			}
		}
		dd[i][N-1] = dp[i][N-1];
		for(int j = N-2; j >= 0; j--)
			dd[i][j] = dd[i][j+1] + dp[i][j];
	}
	for(int i = 101; i < N; i++)
		ans += dp[l-1][i];
	int c = 0;
	//cout << ans << endl;
	for(int i = 0; i < l; i++){
		if(i == 0){
			for(int j = 1; j < s[i]-'0'; j++)
				ans += dd[l-1][101 - c + (int)pow(-1, j+1)*j];
		}
		else{
			for(int j = 0; j < s[i]-'0'; j++)
				ans += dd[l-i-1][101 - c + (int)pow(-1, j+1)*j];
		}
		int x = (s[i]-'0');
		c += (int)pow(-1, x)*x;
		//cout << i << " " <<  ans << endl;
	}
	//cout << ans << endl;
	if(c > 0)	ans++;
	return ans;
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
    IOS;
    int t;	cin >> t;
	  while(t--){
    	int l, r;
    	cin >> l >> r;
    	cout << oe(r) - oe(l-1) << endl;
    }
    return 0;
}
