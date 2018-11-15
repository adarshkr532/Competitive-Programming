#include<bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long int
#define pi pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define mod 1e18
#define inf 1e9
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int N = 10005;

struct circle{
	ld r, x, y;
}c[1005];

pi pp[1005];
ld z1;
bitset<1005> bb[1005];

ld dis(int i, int xx){
	ld z = (c[i].x - pp[xx].fi)*(c[i].x - pp[xx].fi) +
			(c[i].y - pp[xx].se)*(c[i].y - pp[xx].se);
	z = sqrt(z);
	return z; 
}

signed main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> pp[i].fi >> pp[i].se;
	for(int i = 1; i <= m; i++){
		cin >> c[i].r >> c[i].x >> c[i].y;
		for(int j = 1; j <= n; j++)
			if(dis(i, j) < c[i].r)	bb[j][i] = 1;
	}
	while(k--){
		int a, b, ans = 0;
		cin >> a >> b;
		ans = (bb[a] ^ bb[b]).count();
		cout << ans << endl;
	}	
 	return 0;
}
