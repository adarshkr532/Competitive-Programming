/*
Code inspired from 
https://codejam.withgoogle.com/2018/challenges/0000000000007706/analysis/00000000000459f4
&
tourist's code: https://codejam.withgoogle.com/2018/challenges/0000000000007706/attempts/for/Gennady.Korotkevich
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

int a[25][25], vis[25][25];
bool cnt[16];
int mov[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("out1.txt","w",stdout);
	#endif
	int t;	cin >> t;
	for(int z = 1; z <= t; z++){
		int r, c;
		cin >> r >> c;
		memset(cnt, 0, sizeof cnt);
		memset(a, 0, sizeof a);
		for(int i = 1; i <= r; i++){
			string s; 	cin >> s;
			for(int j = 0; j < c; j++){
				a[i][j+1] = (s[j] == 'B');
				if(a[i][j+1])	cnt[15] = 1;
				else	cnt[0] = 1;	
			}
		}
		int ans = 0;
		auto check = [&](int x, int y){
			if(x >= 1 && x <= r && y >= 1 && y <= c)
				return true;
			else
				return false; 
		};
		for(int i = 1; i <= r; i++){
			for(int j = 1; j < c; j++){
				if(a[i][j] && !a[i][j+1])	cnt[10] = 1;
				if(!a[i][j] && a[i][j+1])	cnt[5] = 1;
			}
		}
		for(int i = 1; i <= c; i++){
			for(int j = 1; j < r; j++){
				if(a[j][i] && !a[j+1][i])	cnt[12] = 1;
				if(!a[j][i] && a[j+1][i])	cnt[3] = 1;
			}
		}
		for(int i = 1; i < r; i++){
			for(int j = 1; j < c; j++){
				int x = a[i][j]*8 + a[i][j+1]*4 + a[i+1][j]*2 + a[i+1][j+1];
				cnt[x] = 1;
			}
		}
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				auto blk = [&](int x, int y){
					if(x <= i && y <= j)
						return 0;
					else if(x <= i && y > j)
						return 1;
					else if(x > i && y <= j)
						return 2;
					else 
						return 3;
				};
				for(int p = 0; p < 16; p++){
					if(!cnt[p])	continue;	
					queue<pi> q;
					memset(vis, 0, sizeof vis);
					bool f[4] = {(p&8), (p&4), (p&2), (p&1)};
					//cout << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << endl;
					for(int x = 1; x <= r; x++){
						for(int y = 1; y <= c; y++){
							if(vis[x][y] || f[blk(x,y)] != a[x][y])	continue;
							int mx = 0;
							q.push({x,y});
							while(!q.empty()){
								pi cur = q.front();
								q.pop();  
								if(vis[cur.fi][cur.se])	continue;
								//cout << cur.fi << " " << cur.se << endl;
								mx++;	vis[cur.fi][cur.se] = 1;
								for(int l = 0; l < 4; l++){
									pi now = {cur.fi+mov[l][0], cur.se+mov[l][1]};
									if(check(now.fi, now.se) && f[blk(now.fi, now.se)] == a[now.fi][now.se])
										q.push({now.fi, now.se});
								}
							}
							if(mx > ans){
								//cout << i << " " << j << " " << p << " " << mx << endl;
								ans = mx;
							}
						}
					}
				}
			}
		}
		cout << "Case #" << z << ": ";
		cout << ans << endl;
	}
	return 0;
}
