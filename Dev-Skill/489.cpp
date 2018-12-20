/*
Make a prime factor sieve
Make a dynamic segment tree for every prime upto n
Minimum steps to reach a node will be minimum of range query on segment tree of all its prime factors for every value less than index of that node
For every node, i, update the segment tree of all its prime factor by the steps reach to reach that node at index A[i]
*/

#pragma GCC optimize "03"
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
 
const int N = 100005;
const int inf = 1e9;

int a[N], p[N], cur;
vector<int> fac[N];

struct fork{
	int le, ri, v;
}t[100*N];

void sieve(){
	for(int i = 2; i < N; i++){
		if(!fac[i].empty())	continue;
		for(int j = i; j < N; j += i)
			fac[j].pb(i);
	}
}

void pushdown(int nd, int s, int e){
	if(s == e)
		return;
	if(t[nd].le == 0){
		t[nd].le = ++cur;
		t[cur].v = inf;
	}
	if(t[nd].ri == 0){
		t[nd].ri = ++cur;
		t[cur].v = inf;
	}
}

void upd(int nd, int s, int e, int id, int val){
	pushdown(nd, s, e);
	if(s == e){
		t[nd].v = min(t[nd].v, val);
		return;
	}
	int md = (s + e) >> 1;
	if(id <= md)
		upd(t[nd].le, s, md, id, val);
	else
		upd(t[nd].ri, md+1, e, id, val);
	t[nd].v = min(t[t[nd].le].v, t[t[nd].ri].v);
}

int query(int nd, int s, int e, int r){
	if(s > r || e < 1)
		return inf;
	if(s >= 1 && e <= r)
		return t[nd].v;
	pushdown(nd, s, e);
	int md = (s + e) >> 1;
	return min(query(t[nd].le, s, md, r), query(t[nd].ri, md+1, e, r));
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	sieve();
	int tt, n;	cin >> tt;
	while(tt--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= cur; i++){
			t[i].le = t[i].ri = 0;
			t[i].v = inf;
		}
		p[n+1] = 0;	cur = n;
		for(int i = n; i >= 1; i--){
			p[i] = 1 + p[i+1];
			for(int j: fac[i])
				p[i] = min(p[i], 1 + query(j, 1, N, i));
			for(int j: fac[i])
				upd(j, 1, N, a[i], p[i]);
		}
		cout << p[1] << endl;
	}
	return 0;
} 
