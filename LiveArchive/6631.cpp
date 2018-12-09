/*

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

const int N = 1e4+5;
const int inf = 1e9;

int cur = 1, i, rig[N];

struct fork{
	int le, ri;
}t[N];

string s;
int dp[N][1005], cnt;

void build(int nd, int l, int r){
	t[nd].le = t[nd].ri = 0;
	if(r == l+1){
		dp[nd][1] = 1;
		return;
	}
	if(r == l+2){
		cnt++;
		dp[nd][1] = 0;
		return;
	}
	int md = rig[l+1];
	t[nd].le = ++cur;
	build(t[nd].le, l+1, md);
	t[nd].ri = ++cur;
	build(t[nd].ri, md+1, r-1);
	for(int i = 1; i <= 1000; i++){
		if(i%2 == 0)
			dp[nd][i] = dp[t[nd].le][i/2] + dp[t[nd].ri][i/2];
		else{
			int x = dp[t[nd].le][i/2] + dp[t[nd].ri][i - i/2];
			int y = dp[t[nd].le][i - i/2] + dp[t[nd].ri][i/2];
			dp[nd][i] = min(x, y);
		}
	}
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		//freopen("out1.txt","w",stdout);
	#endif
    IOS;
	while(cin >> s){
		cur = 1;	cnt = 0;
		stack<int> st;
		st.push(0);
		int n = s.length();
		for(int i = 1; i < n; i++){
			if(s[st.top()] == '(' && s[i] == ')'){
				rig[st.top()] = i;
				st.pop();
			}
			else if(s[i] == '(')
				st.push(i);
		}
		for(int i = 1; i < N; i++){
			for(int j = 1; j <= 1000; j++)
				dp[i][j] = inf;
		}
		build(1, 0, s.length()-1);
		if(dp[1][cnt] >= inf)
			cout << "impossible\n";
		else
			cout << dp[1][cnt] << endl;
	}
    return 0;
}
