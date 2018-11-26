//Used OEIS to find the series and then standard matrix exponentiation problem

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
 
int sz;
ll mod = 1e9+9;
const int NN = 6;
 
class matrix{
public:
    ll mat[NN][NN];
    matrix(){
        for(int i = 0; i < NN; i++)
            for(int j = 0; j < NN; j++)
                mat[i][j] = 0;
        sz = NN;
    }
    inline matrix operator * (const matrix &a){
        matrix temp;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++)
                for(int k = 0; k < sz; k++)
                	temp.mat[i][j] = (temp.mat[i][j] + mat[i][k] * a.mat[k][j] + mod*mod) % mod;
        return temp;
    }
    inline matrix operator + (const matrix &a){
        matrix temp;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++)
                temp.mat[i][j] = (mat[i][j] + a.mat[i][j] + mod*mod)%mod ;
        return temp;
    }
    inline matrix operator - (const matrix &a){
        matrix temp;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++)
                temp.mat[i][j] = (mat[i][j] - a.mat[i][j] + mod) % mod ;
        return temp;
    }
    inline void operator = (const matrix &b){
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++)
                mat[i][j] = b.mat[i][j];
    }
    inline void print(){
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
 
matrix pow(matrix a, ll k){
    matrix ans;
    for(int i = 0; i < sz; i++)
        ans.mat[i][i] = 1;
    while(k){
        if(k & 1)
            ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}
 
signed main() {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
		IOS;
	matrix t;
	t.mat[0][0] = 2; t.mat[0][2] = -1; t.mat[0][4] = -1; t.mat[0][5] = 1;
	t.mat[1][0] = t.mat[2][1] = t.mat[3][2] = t.mat[4][3] = t.mat[5][4] = 1;
	int tt;	cin >> tt;
	ll a[8] = {2,2,8,9,12,16,23,29};
	while(tt--){
		ll x, ans;	cin >> x;
		if(x <= 8)
			cout << a[x-1] << endl;
		else{
			matrix p = pow(t, x-8);
			ll ans = 0;
			for(int i = 0; i < 6; i++)
				ans = (ans + p.mat[0][i]*a[7-i] + mod*mod) % mod;
			cout << ans << endl;
		}
	}
	return 0;
} 
