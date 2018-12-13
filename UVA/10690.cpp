// DP-Knapsack

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mod 1000000009
#define inf 1e18
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif

const int N = 100005;

string s;
stack<int> st;
int a[N], b[N];

bool o(char c){
	if(c == '(' || c == '{' || c == '[' || c == '<')
		return true;
	return false;
}

bool popo(char c){
	if(st.empty())	return false;
	if(c-s[st.top()] == 1)
		return true;
	return false;
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
    IOS;
    int t;	cin >> t;
    for(int z = 1; z <= t; z++){
    	cin >> s;
    	int l = s.length();
    	for(int i = 0; i <= l; i++)
    		a[i] = 0, b[i] = 0;
    	while(!st.empty())
    		st.pop();
    	if(o(s[0]))	st.push(0);
    	for(int i = 1; i < l; i++){
    		if(o(s[i]))
    			st.push(i);
    		else{
    			if(popo(s[i])){
    				a[st.top()] = i;
    				b[i] = st.top();
    				st.pop();
    			}
    			else
    				st.push(i);
    		}
    	}
    	for(int i = l-1; i >= 1; i--){
    		if(a[i] > 0 && b[i-1] > 0)
    			a[b[i-1]] = a[i];
    	}
    	cout << "Case " << z << ": " << endl;
    	for(int i = 0; i < l; i++){
    		if(a[i] == 0)
    			cout << a[i] << endl;
    		else
    			cout << a[i] - i + 1 << endl;
    	}
    }
    return 0;
}
