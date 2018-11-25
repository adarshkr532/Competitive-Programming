/*
Square - root decomposition
---------------------------
The given range is divided into sqrt(N) blocks.
For each square root block, mappings from current to new value is stored.
On processing a query, if a particular block lies completely in the queried range, only mappings is changed O(1)
otherwise, the whole block is traversed in O(blk_sz) and the complete range is updated by the new value.

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int N = 2e5 + 5;
const int blk_sz = 3200;

int a[N];
int f[blk_sz][105];

int main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	int n, q;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < blk_sz; i++)
		for(int j = 0; j <= 100; j++)
			f[i][j] = j;
	cin >> q;
	while(q--){
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		l--;
		while(l < r){
			if(l % blk_sz == 0 && l+blk_sz <= r){
				int blk = l/blk_sz;
				for(int i = 0; i <= 100; i++)
					if(f[blk][i] == x)	f[blk][i] = y;
				l += blk_sz;
			}
			else{
				int blk = l/blk_sz;
				int cur = blk*blk_sz;
				for(int i = cur; i < cur+blk_sz && i < n; i++)
					a[i] = f[blk][a[i]];
				for(int i = 0; i <= 100; i++)
					f[blk][i] = i;
				while(l < cur + blk_sz && l < r){
					if(a[l] == x)	a[l] = y;
					l++;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
		cout << f[i/blk_sz][a[i]] << " ";
	return 0;
}
