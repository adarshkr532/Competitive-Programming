/*
Run Djisktra from every node to find the minimum cost and min length of seg
O(n*m*logm)
*/
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define pi pair<ll,int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N = 305;
const ll inf = 1e18;

int ans, n;
vector<pi> g[N];
priority_queue<pair<pi,int>, vector<pair<pi,int> >, greater<pair<pi,int> > > q;
ll dis[N], seg[N];

void getsegment(int s){
	for(int i = 1; i <= n; i++)
		dis[i] = seg[i] = inf;
	q.push({{0LL, 0}, s});
	seg[s] = 0; dis[s] = 0;
	while(!q.empty()){
		auto u = q.top();
		q.pop();
		if(dis[u.se] != u.fi.fi)	continue;
		//cout << u.se << " " << u.fi.fi << " " << u.fi.se << endl;
		//dis[u.se] = u.fi.fi; seg[u.se] = u.fi.se;
		for(auto j: g[u.se]){
			if(dis[j.fi] > dis[u.se] + j.se){
				dis[j.fi] = dis[u.se] + j.se;
				seg[j.fi] = seg[u.se] + 1;
				q.push({{dis[j.fi], seg[j.fi]}, j.fi});
			}
			else if(dis[j.fi] == dis[u.se] + j.se && seg[j.fi] > seg[u.se]+1){
				seg[j.fi] = seg[u.se]+1;
				q.push({{dis[j.fi], seg[j.fi]}, j.fi});
			}
		}
	}
	for(int i = 1; i <= n; i++)
		ans += seg[i];

}

signed main() {
//	freopen("input.txt","r",stdin);
		freopen("trip.in","r",stdin);
		freopen("trip.out","w",stdout);
    IOS;
    int m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
    	int u, v, w;	
    	cin >> u >> v >> w;
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    }
    for(int i = 1; i <= n; i++)
    	getsegment(i);
    cout << setprecision(10) << fixed << (ld)ans/(n*(n-1));
    return 0;
}
