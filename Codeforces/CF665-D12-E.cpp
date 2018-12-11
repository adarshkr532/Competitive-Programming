/*
Reference: https://threads-iiith.quora.com/Tutorial-on-Trie-and-example-problems
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
#define inf 1000000008
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N = 1000005;
const int B = 30;

struct fork{
	int le, ri, val;
}t[40*N];

int f[33], cur = 1, a[N];

void pushdown(int nd){
	if(t[nd].le == 0)
		t[nd].le = ++cur;
	if(t[nd].ri == 0)
		t[nd].ri = ++cur;
}

void insert(int nd, int val, int dep){
	if(dep == -1){
		t[nd].val++;
		return;
	}
	pushdown(nd);
	if(val&f[dep])
		insert(t[nd].ri, val-f[dep], dep-1);
	else
		insert(t[nd].le, val, dep-1);
	t[nd].val = t[t[nd].le].val + t[t[nd].ri].val;
}

ll query(int nd, int knd, int cur, int k, int dep){
	if(dep == -1)
		return t[knd].val*1LL;
	pushdown(nd);	pushdown(knd);
	bool x = (cur&f[dep]);
	bool y = (k&f[dep]);
	cur -= x*f[dep]; k -= y*f[dep];
	if(!x && !y)
		return t[t[knd].ri].val*1LL + query(t[nd].le, t[knd].le, cur, k, dep-1);
	else if(!x && y)
		return query(t[nd].le, t[knd].ri, cur, k, dep-1);
	else if(x && !y)
		return t[t[knd].le].val*1LL + query(t[nd].ri, t[knd].ri, cur, k, dep-1);
	else
		return query(t[nd].ri, t[knd].le, cur, k, dep-1);
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
    IOS;
    int n, k;
    ll ans = 0;
    f[0] = 1;
    for(int i = 1; i <= B; i++)
    	f[i] = (f[i-1] << 1);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = (a[i] ^ a[i-1]);
    }
    insert(1, 0, B);
    for(int i = 1; i <= n; i++){
    	ans += query(1, 1, a[i], k, B);
    	insert(1, a[i], B);
    }
    cout << ans;
    return 0;
}
