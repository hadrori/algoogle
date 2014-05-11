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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

ll fact[300000];

/* 拡張ユークリッドの互除法 */
// a x + b y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

/* 逆元 */
ll mod_inverse(ll a, ll m){
    ll x, y;
    if(extgcd(a, m, x, y) == 1) return (x + m) % m;
    return 0;  // unsolvable
}

/* nCk mod m */
ll mod_comb(ll n, ll k, ll m){
    if(n < 0 || k < 0 || n < k) return 0;
    return fact[n] * mod_inverse(fact[k] * fact[n - k] % m, m) % m;
}

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    fact[0] = 1;
    rep(i,300000-1) fact[i + 1] = (i + 1) * fact[i] % MOD;
    ll ans = 0;
    rep(i,k+1){
        ll j = k - i;
        ll r = (mod_comb(n + 2 * i, i, MOD) - mod_comb(n + 2 * i, i - 1 ,MOD) + MOD) % MOD;
        ll d = (mod_comb(m + 2 * j, j, MOD) - mod_comb(m + 2 * j, j - 1, MOD) + MOD) % MOD;
        ans = (ans + r * d % MOD * mod_comb(n + m + 2 * k, n + 2 * i, MOD)) % MOD;
    }
    cout << ans << endl;
}
