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

const int N = 100005;

vector<int> g[N], rg[N];
stack<int> st;
bool vis[N];
int n, comp[N];
map<pi,bool> m;

void dfs1(int u){
	vis[u] = 1;
	for(auto i: g[u]){
		int x = min(u, i);
		int y = max(u, i);
		if(m.find({x,y}) == m.end()){
			m[{x,y}] == 1;
			rg[i].pb(u);
		}
		if(vis[i])	continue;
		dfs1(i);
	}
	st.push(u);
}

void dfs2(int u, int k){
	comp[u] = k; 
	for(auto i: rg[u]){
		if(comp[i])	continue;
		dfs2(i, k);
	}
}

void scc(){
	for(int i = 1; i <= n; i++){
		if(!vis[i])	dfs1(i);
	}
	int grp = 0;
	while(!st.empty()){
		int x = st.top();
		st.pop();
		if(comp[x])	continue;
		dfs2(x, ++grp);	
	}
	if(grp > 1){
		cout << 0;
		exit(0);
	}
	for(int i = 1; i <= n; i++){
		for(auto j: rg[i])
			cout << j << " " << i << endl;
	}
}

signed main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	int m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;	
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	scc();
 	return 0;
}
