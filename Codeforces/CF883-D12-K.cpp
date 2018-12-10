/*
Determine range for every block of road by the previous range of block
Once the current range is found, backtrack and update the range of all previous block
Maximum value of every range is the answer
*/

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N = 200005;
const int inf = 1e18;

int s[N], g[N];
pi p[N];

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
    IOS;
    int n;	cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> s[i] >> g[i];
    p[1] = {s[1], s[1] + g[1]};
    for(int i = 2; i <= n; i++){
    	p[i] = {s[i], s[i] + g[i]};
    	if(p[i].se < p[i-1].fi-1 || p[i].fi > p[i-1].se+1)
    		return cout << -1, 0;
    	p[i].fi = max(p[i].fi, p[i-1].fi - 1);
    	p[i].se = min(p[i].se, p[i-1].se + 1);
    }
    for(int i = n-1; i >= 1; i--){
    	p[i].fi = max(p[i].fi, p[i+1].fi - 1);
    	p[i].se = min(p[i].se, p[i+1].se + 1);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    	ans += p[i].se-s[i];
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
    	cout << p[i].se << " ";
    return 0;
}
