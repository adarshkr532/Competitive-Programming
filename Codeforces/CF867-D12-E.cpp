#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define pi pair<int,int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int N = 2e5 + 5;
const int blk_sz = 3200;

multiset<int> m;

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	int n, ans = 0;	cin >> n;
	for(int i = 1; i <= n; i++){
		int p;	cin >> p;
		m.insert(p);
		if(!m.empty() && (*m.begin()) < p){
			ans += p - (*m.begin());
			m.erase(m.begin());
			m.insert(p);
		}
	}
	cout << ans;
	return 0;
}
