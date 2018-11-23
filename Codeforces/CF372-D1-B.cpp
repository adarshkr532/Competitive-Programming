#include<bits/stdc++.h>
using namespace std;

#define ld double
#define int long long int
#define pi pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define inf 1e9
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#ifndef LOCAL
#define endl'\n'
#endif

const int N = 45;

int a[N][N], s[N][N], p[N][N][N][N];

signed main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	int n,m,q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char p; cin >> p;
			a[i][j] = p-'0';
		}
		s[i][m+1] = m+1;
		for(int j = m; j >= 1; j--){
			if(a[i][j])	
				s[i][j] = j;
			else
				s[i][j] = s[i][j+1];
		}
	}
	for(int l = 1; l <= n; l++){
		for(int b = 1; b <= m; b++){
			for(int i = 1; i <= n-l+1; i++){
				for(int j = 1; j <= m-b+1; j++){
					int c = 0, x = b;
					for(int k = i; k <= i+l-1; k++){
						x = min(x, s[k][j]-j);
						c += x;
					}
					p[i][j][i+l-1][j+b-1] = c + p[i+1][j][i+l-1][j+b-1] + p[i][j+1][i+l-1][j+b-1] - p[i+1][j+1][i+l-1][j+b-1];
				}
			}
		}
	}
	while(q--){
		int x,y,z,w;
		cin >> x >> y >> z >> w;
		cout << p[x][y][z][w] << endl;
	}
 	return 0;
}
