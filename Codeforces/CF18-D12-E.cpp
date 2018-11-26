/*
DYNAMIC PROGRAMMING
-------------------
For every row, the number of changes required to color the flag according to the problem is precomputed.
Then dp is used to find the minimal changes in the whole flag.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define fi first
#define se second
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 505;
const int inf = 1e9;

int f[N][27][27];
pi par[N][27][27];
char s[N][N];
multiset<pair<int, pi> > mm;
 
signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	IOS;
	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int a = 0; a < 26; a++){
			for(int b = 0; b < 26; b++){
				if(a == b)	continue;
				int c = 0;
				for(int j = 0; j < m; j++){
					if(j&1 && s[i][j] != char('a'+a))
						c++;	
					if(!(j&1) && s[i][j] != char('a'+b))
						c++;
				}
				f[i][b][a] = c;
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(i == j)	continue;
			mm.insert({f[0][i][j], {i, j}});
		}
	}
	for(int i = 1; i < n; i++){
		for(int ci = 0; ci < 26; ci++){
			for(int cj = 0; cj < 26; cj++){
				if(ci == cj)	continue; 
				for(auto x: mm){
					if(x.se.fi != ci && x.se.se != cj){
						f[i][ci][cj] += x.fi;
						par[i][ci][cj] = x.se;
						break;
					}
				}
			}
		}
		mm.clear();
		for(int ci = 0; ci < 26; ci++)
			for(int cj = 0; cj < 26; cj++){
				if(ci == cj)	continue;
				mm.insert({f[i][ci][cj], {ci, cj}});
			}
	}
	auto z = *mm.begin();
	cout << z.fi << endl;
	int cx = z.se.fi, cy = z.se.se;
	for(int i = n-1; i >= 0; i--){ 
		for(int j = 0; j < m; j++){
			if(j%2 == 0)
				s[i][j] = 'a' + cx;
			else
				s[i][j] = 'a' + cy;
		}
		int tx = par[i][cx][cy].fi, ty = par[i][cx][cy].se;
		cx = tx; cy = ty;
	}
	for(int i = 0; i < n; i++){
		cout << s[i] << endl;
	}
	return 0;
} 
