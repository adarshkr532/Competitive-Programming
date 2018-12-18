/* 
n*n*t dp
*/

#pragma GCC optimize "03"
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
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

const int N = 2005;
const int inf = 1e9;

bool per[N][N];
int c[N];

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	//	freopen("out1.txt","w",stdout);
	#endif
	IOS;
   	int t;	cin >> t;
   	while(t--){
   		string s;	cin >> s;
   		int len = s.length();
   		c[len] = 0;
   		memset(per, 0, sizeof per);
   		for(int i = len-1; i >= 0; i--){
   			c[i] = inf;	
   			for(int j = i; j < len; j++){
   				if(i+1 >= j-1)	per[i+1][j-1] = 1;
   				if(s[i] == s[j] && per[i+1][j-1]){
   					per[i][j] = 1;
   					c[i] = min(c[i], 1+c[j+1]);
   				}
   			}
   		}
   		cout << c[0] << endl;
   	}
   	return 0;
}
