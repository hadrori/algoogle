#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

const int mod = 100000007;
const int MAX = 1024;
int dr[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dc[] = {1, 1, 1, 0, -1, -1, -1, 0};

/* 拡張ユークリッドの互除法 */
// a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g; // 1なら解あり
}

/* 逆元 */
long long mod_inverse(long long a, long long m){
    long long x, y;
    if(extgcd(a, m, x, y) != 1) return 0; // unsolvable
    return (m + x % m) % m;
}

/* n! mod m */
//n! = a p^e としたときの a mod p を求める O(log_p n)
long long fact[MAX];
long long mod_fact(long long n, long long m, long long& e){
    e = 0;
    if(!n) return 1;

    //pの倍数の部分を計算
    long long res = mod_fact(n / m, m, e);
    e += n / m;

    // (p-1)! ≡ -1 (ウィルソンの定理)より (p-1)!^(n/p)はn/pの偶奇だけで計算できる
    if(n / m % 2) return res * (m - fact[n % m]) % m;
    return res * fact[n % m] % m;
}

/* nCk mod m */
long long mod_comb(long long n, long long k, long long m){
    if(n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, m, e1), a2 = mod_fact(k, m, e2), a3 = mod_fact(n - k, m, e3);
    if(e1 > e2 + e3) return 0; // m で割り切れる
    return a1 * mod_inverse(a2 * a3 % m, m) % m;
}

int main(){
    fact[0] = 1;
    repi(i,1,MAX) fact[i] = fact[i-1] * i % mod;
    int r, c;
    complex<int> a, b;
    vector<complex<int> > d;
    cin >> r >> c >> a.real() >> a.imag() >> b.real() >> b.imag();
    d.pb(b);
    rep(i,8){
	complex<int> t;
	t.real() = b.real() + dr[i] * r;
	t.imag() = b.imag() + dc[i] * c;
	if(norm(d[0]-a) > norm(t-a)){
	    d.clear();
	    d.pb(t);
	}
	else if(norm(d[0]-a) == norm(t-a)) d.pb(t);
    }
    ll ans = 0;
    rep(i,d.size()){
	complex<int> t;
	t = d[i] - a;
	t.real() = abs(t.real());
	t.imag() = abs(t.imag());
	ans += mod_comb(t.real()+t.imag(),t.real(),mod);
	ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
