#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sd(x) scanf("%d",&(x))
#define pd(x) printf("%d ",(x))
#define slld(x) scanf("%lld",&(x))
#define plld(x) printf("%lld",(x))
#define br printf("\n")
#define pi pair<int,int>
#define pii pair<long long int, long long int>
#define vi vector<int>
#define pb push_back
#define RESET(val) memset(val, 0, sizeof(val))
#define mp(a,b) make_pair(a, b)
#define fi first
#define se second
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define mod 163577857
#define inf 1000000000
//ll power(ll a,ll b,ll n){ll ans=1;while(b>0){if(b%2==1)ans=(ans*a)%n;a=(a*a)%n;b/=2;}return ans;}

const int N = 300005;
const int sz = 30;

struct fork{
    int zz, oo, r, l;
};

int cur = 2;
int a[N], b[N];
fork t[50*N];

void ins(int nd, int p){
    for(int i = sz; i >= 0; i--){
        int x = (1<<i);
        x = (p&x);
        if(x == 0){
            if(t[nd].zz == 0)
                t[nd].zz = cur++;
            t[nd].l++;
            nd = t[nd].zz;
        }
        else{
            if(t[nd].oo == 0)
                t[nd].oo = cur++;
            t[nd].r++;
            nd = t[nd].oo;
        }
    }
}

int min_xor(int nd, int p){
    int ans = 0;
    for(int i = sz; i >= 0; i--){
        int x = (1<<i);
        int tt = x;
        x = (p&x);
        if(x == 0){
            if(t[nd].zz == 0){
                ans = ans + tt;
                nd = t[nd].oo;
            }
            else
                nd = t[nd].zz;
        }
        else{
            if(t[nd].oo == 0)
                nd = t[nd].zz;
            else{
                ans = ans + tt;
                nd = t[nd].oo;
            }
        }
    }
    return (ans^p);
}

void del(int nd, int p){
    for(int i = sz; i >= 0; i--){
        int x = (1<<i);
        x = (x&p);
        //cout<<nd<<" "<<x<<endl;
        if(x == 0){
            t[nd].l--;
            if(t[nd].l == 0)
            {   t[nd].zz = 0; break;}
            nd = t[nd].zz;
        }
        else{
            t[nd].r--;
            if(t[nd].r == 0)
            {   t[nd].oo = 0; break;}
            nd = t[nd].oo;
        }
    }
}

signed main(){
    freopen("input.txt","r",stdin);
    int n; sd(n);
    for(int i = 0; i < n; i++)
        sd(a[i]);
    for(int i = 0; i < n; i++){
        sd(b[i]);
        ins(1,b[i]);
    }
    for(int i = 0; i < n; i++){
        int ans = min_xor(1,a[i]);
        pd(ans);
        del(1,ans^a[i]);
    }
    return 0;
} 
