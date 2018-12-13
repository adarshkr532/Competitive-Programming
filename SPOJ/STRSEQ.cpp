/*
Reference : https://stackoverflow.com/questions/19658762/find-the-smallest-number-that-does-not-occur-as-a-subsequence-of-the-string
*/

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
mt19937
rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){	// l, r inclusive
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

bitset<10> b[100005];
string t = "";

int lszb(bitset<10> b){
	for(int i = 0; i < 10; i++)
		if(b[i] == 0)
			return i;
	return 10;
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
		string s;
    while(cin >> s){
    	t = "";
    	b[s.length()].reset();
    	int cnt = 0;
    	for(int i = s.length()-1; i >= 0; i--){
    		b[i] = b[i+1];
    		b[i].set(s[i]-'0');
    		if(b[i].count() == 10)
    			b[i].reset(), cnt++;
    		//cout << b[i] << endl;
    	}
    	if(cnt == 0){
    		if(lszb(b[0]) == 0)
    			puts("0");
    		else
    			cout << lszb(b[0]) << endl;
    		continue;
    	}	
    	int cur = 0, l = -1;
    	for(int i = 1; i < 10; i++)
    		if(b[0][i] == 0){
    			l = i;	break;
    		}
    	if(l == -1)	t += "10", l = 0;
    	else t.pb('0'+l);	cnt--;
    	while(cnt >= 0 && cur < s.length()){
    		int i;
    		for(i = cur; i < s.length(); i++)
    			if(s[i]-'0' == l)	break;
    		if(i == s.length())	break;
    		cur = i+1;	//cout << cur << endl;
    		int x = lszb(b[cur]);
    		t.pb('0' + x);	cnt--;
    		l = x;
    	}
    	cout << t << endl;
    }
    return 0;
}
