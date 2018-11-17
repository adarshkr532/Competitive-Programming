#include<bits/stdc++.h>
using namespace std;

#define ld double
#define int long long int
#define pi pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define mod 1e18
#define inf 1e9
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#ifndef LOCAL
#define endl'\n'
#endif

const int N = 200005;

int cnt[1030];

signed main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	int n;	cin >> n;
	for(int i = 1; i <= n; i++){
		int p, s = 0;	cin >> p;
		while(p > 0){
			int c = p%10;
			s |= (1 << c);
			p /= 10;
		}
		cnt[s]++;
	}
	int ans = 0;
	for(int i = 0; i < 1024; i++){
		for(int j = i+1; j < 1024; j++){
			if((i&j))
				ans += cnt[i]*cnt[j];
		}
	}
	for(int i = 0; i < 1024; i++)
		ans += cnt[i]*(cnt[i]-1)/2;
	cout << ans;
 	return 0;
}
