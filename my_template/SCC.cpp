int comp[N];
stack<int> st;
bool vis[N];
vector<int> g[N], rg[N];
 
void add(int u, int v){
	g[u].push_back(v);
	rg[v].push_back(u);
}
 
void dfs(int u){
	vis[u] = 1;
	for(auto i: g[u]){
		if(!vis[i])
			dfs(i);
	}
	st.push(u);
}
 
void dfs1(int u, int cur){
	comp[u] = cur;
	for(auto i: rg[u]){
		if(!comp[i])
			dfs1(i, cur);
	}
}
 
void scc(int n){
	for(int i = 1; i <= n; i++){
		if(!vis[i])	dfs(i);
	}
	int grp = 0;
	while(!st.empty()){
		int x = st.top();
		st.pop();
		if(comp[x] == 0){
			grp++;
			dfs1(x, grp);
		}
	}
}
