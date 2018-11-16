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

const int N = 5005;

char s[N][N];
int n, vis[N];

void dfs(int u, int p){
	if(vis[u])	return;
	vis[u] = 1;
	for(int i = 1; i <= n; i++){
		if(s[u][i] == '0')	continue;
		if(s[i][p] == '1'){
			cout << p << " " << u << " " << i;
			exit(0);
		}
		dfs(i, u);
	}
}

signed main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cin >> s[i][j];
	}
	for(int i = 1; i <= n; i++)
		dfs(i, 0);
	cout << -1;
 	return 0;
}
