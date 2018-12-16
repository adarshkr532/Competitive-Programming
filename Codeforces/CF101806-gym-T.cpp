/*
sort the values on the basis of l[i]+d[i] and then greedy
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
#define mod 1000000009
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N = 250005;
const int inf = 1e16;

pi a[N];
multiset<int> s;

bool cmp(pi a, pi b){
	return a.fi + a.se < b.fi + b.se;
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
    IOS;
   	int n;	cin >> n;
   	for(int i = 1; i <= n; i++)
   		cin >> a[i].fi >> a[i].se;
   	sort(a+1, a+n+1, cmp);
   	int cur = 0, ans = 0;
   	for(int i = 1; i <= n; i++){
   		if(cur <= a[i].fi){
   			ans++;
   			cur += a[i].se;
   			s.insert(a[i].se);
   		}
   		else{
   			auto it = s.end();	it--;
   			if(a[i].se < *it && cur - *it <= a[i].fi){
   				cur -= *it;
   				s.erase(it);
   				s.insert(a[i].se);
   				cur += a[i].se;
   			}
   		}
   	}
   	cout << s.size();
    return 0;
}
