/*
Reference: https://codeforces.com/blog/entry/57319
Warning: Strict TL, use fast I/O
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

const int MAXS = 40*1024*1024;
char buf[MAXS],bufout[MAXS],*ch,*chout;

void read(int &x){
    for(++ch;*ch<=32;++ch);
    for(x=0;*ch>='0';++ch) x=x*10+*ch-'0';
}

void out(int x){
    if(!x) *(++chout)='0';
    else{
        char *ch0=chout,*ch1=chout+1;
        while(x){
            *(++ch0)=x%10+'0';
            x/=10;
        }
        chout=ch0;
        while(ch1<=ch0) swap(*(ch1++),*(ch0--));
    }
    *(++chout)='\n';
}

void out(long long x){
    if(!x) *(++chout)='0';
    else{
        char *ch0=chout,*ch1=chout+1;
        while(x){
            *(++ch0)=x%10+'0';
            x/=10;
        }
        chout=ch0;
        while(ch1<=ch0) swap(*(ch1++),*(ch0--));
    }
    *(++chout)='\n';
}

void std_init(){
    ch=buf-1;
    chout=bufout-1;
    fread(buf,1,MAXS,stdin);
}

void std_out(){
    fwrite(bufout,1,chout-bufout+1,stdout);
}

const int N = 1000005;
const int inf = 2e9;

struct fork{
	int mx, smx, f;
	ll sum;
}t[4*N];

int a[N];

void merge(int nd){
	int le = (nd << 1);
	int ri = le + 1;
	t[nd].mx = max(t[le].mx, t[ri].mx);
	t[nd].f = 0;
	if(t[le].mx == t[nd].mx)	t[nd].f += t[le].f;
	if(t[ri].mx == t[nd].mx)	t[nd].f += t[ri].f;
	t[nd].sum = t[le].sum + t[ri].sum;
	t[nd].smx = max(t[le].smx, t[ri].smx);
	if(t[le].mx > t[nd].smx && t[le].mx != t[nd].mx)	t[nd].smx = t[le].mx;
	if(t[ri].mx > t[nd].smx && t[ri].mx != t[nd].mx)	t[nd].smx = t[ri].mx;
}

void build(int nd, int s, int e){
	if(s == e){
		t[nd].mx = a[s];	t[nd].smx = -1;
		t[nd].f = 1;	t[nd].sum = a[s]*1LL;
		return;
	}
	int md = (s + e) >> 1;
	int le = (nd << 1);
	int ri = le+1;
	build(le, s, md);
	build(ri, md+1, e);
	merge(nd);
}

void dec(int nd, int v){
	if(v >= t[nd].mx)	return;
	t[nd].sum -= 1LL*(t[nd].mx - v)*t[nd].f;
	t[nd].mx = v;
}

void pushdown(int nd, int s, int e){
	if(s == e)	return;
	dec(nd<<1, t[nd].mx);
	dec(nd<<1|1, t[nd].mx);
}

void upd(int nd, int s, int e, int l, int r, int x){
	pushdown(nd, s, e);
	if(s > r || e < l || t[nd].mx <= x)
		return;
	if(s >= l && e <= r && t[nd].smx < x){
		dec(nd, x);
		return;
	}
	int md = (s + e) >> 1;
	int le = (nd << 1);
	int ri = le+1;
	upd(le, s, md, l, r, x);
	upd(ri, md+1, e, l, r, x);
	merge(nd);
}

int q1(int nd, int s, int e, int l, int r){
	if(s > e || s > r || e < l)
		return 0;
	if(s >= l && e <= r)
		return t[nd].mx;
	pushdown(nd, s, e);
	int md = (s + e) >> 1;
	int le = (nd << 1);
	int ri = le + 1;
	return max(q1(le, s, md, l, r), q1(ri, md+1, e, l, r));
}

ll q2(int nd, int s, int e, int l, int r){
	if(s > e || s > r || e < l)
		return 0LL;
	if(s >= l && e <= r)
		return t[nd].sum;
	pushdown(nd, s, e);
	int md = (s + e) >> 1;
	int le = (nd << 1);
	int ri = le + 1;
	return q2(le, s, md, l, r) + q2(ri, md+1, e, l, r);
}

signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("out1.txt","w",stdout);
	#endif
    std_init();
   	int test;	
   	read(test);
   	while(test--){
   		int n, m;
   		read(n); read(m);
   		for(int i = 1; i <= n; i++)
   			read(a[i]);
   		build(1, 1, n);
   		while(m--){
   			int t, x, y;
   			read(t); read(x); read(y);
   			if(t == 0){
   				int p;	
   				read(p);
   				upd(1, 1, n, x, y, p);
   			}
   			else if(t == 1)
   				out(q1(1, 1, n, x, y));
   			else
   				out(q2(1, 1, n, x, y));
   		}
   	}
   	std_out();
   	return 0;
}
