/* Fastest Solution here
Code implemented after seeing this https://www.udebug.com/LA/7616/hints
But it was not fast enough to pass time limit.
Later rewritten by @Robbinb1993
*/

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
typedef long long LL;

const int N = 101;

int n, m, s, ans;
LL g[2][N];

void rec(LL bm1, LL bm2, int dep){
   if(dep == s-1){
      ans += __builtin_popcountll(bm1) + __builtin_popcountll(bm2);
      return;
   }
   LL bm = bm1, v;
   int pos;
   while (bm) {
      v = bm & -bm;
      pos = __builtin_ffsll(bm) - 1;
      bm -= v;
      rec(bm & g[0][pos], bm2 & g[1][pos], dep + 1);
   }//while
   bm = bm2;
   while (bm) {
      v = bm & -bm;
      pos = __builtin_ffsll(bm) + 63;
      bm -= v;
      rec(0, bm & g[1][pos], dep + 1);
   }//while
}//rec

signed main() {
   int t;	cin >> t;
   while(t--){
      ans = 0;
      cin >> n >> m >> s;
      memset(g, 0, sizeof(g));
      for(int i = 1; i <= m; i++){
         int u, v;
         cin >> u >> v;
         if(u > v)	
            swap(u, v);
         if (v <= 63)
            g[0][u] |= (1llu << v);
         else
            g[1][u] |= (1llu << (v - 64));
      }//for
      for(int i = 1; i <= n; i++)
         rec(g[0][i], g[1][i], 1);
      cout << ans << endl;
   }
   return 0;
}
