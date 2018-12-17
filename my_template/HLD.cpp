int cur, par[N], size[N], tour[N], chainhead[N], ind[N], node[N], tt[4*N] ;
vector<pi> adj[N];
 
void dfs1(int u, int p){
    par[u] = p;
    size[u] = 1;
    for(pi i: adj[u]){
        if(i.fi == p)  continue;
        dfs1(i.fi,u);
        size[u] += size[i.fi];
    }
}
 
void dfs2(int u){
    int mx = 0, nd = 0, w = 0;
    if(chainhead[u] == 0)   chainhead[u] = u;
    for(pi i: adj[u]){
        if(i.fi == par[u])  continue;
        if(mx < size[i.fi]){
            mx = size[i.fi];
            nd = i.fi;   w = i.se;
        }
    }
    if(nd != 0){
        chainhead[nd] = chainhead[u];
        tour[++cur] = w;
        ind[nd] = cur; 
        node[cur] = nd;
        dfs2(nd);
    }
    for(pi i: adj[u]){
        if(i.fi == par[u] || i.fi == nd) continue;
        tour[++cur] = i.se;
        ind[i.fi] = cur;
        node[cur] = i.fi;
        dfs2(i.fi);
    }
}
 
int lca(int u, int v){
    while(chainhead[u] != chainhead[v]){
        if(ind[u] > ind[v])
            u = par[chainhead[u]];
        else
            v = par[chainhead[v]];
        if(u == 0)  u = 1;
        if(v == 0)  v = 1;
    }
    return ((ind[u] >= ind[v])?v:u);
}
