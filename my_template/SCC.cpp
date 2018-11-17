vector<int> g[N], rg[N];
stack<int> st;
bool vis[N];
int n, comp[N];

void dfs1(int u){
	vis[u] = 1;
	for(auto i: g[u]){
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
}
