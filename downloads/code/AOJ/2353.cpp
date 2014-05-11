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

//const ll m = 1000003, n = 1000033;
const ll m = 999979, n = 999983;

void calc(ll &mx, ll &nx, int o, int y){
    switch(o){
    case 1:
	mx = (mx + y) % m;
	nx = (nx + y) % n;
	break;
    case 2:
	mx = (mx - y + m) % m;
	nx = (nx - y + n) % n;
	break;
    case 3:
	mx = mx * y % m;
	nx = nx * y % n;
	break;
    case 4:
	mx = mx * mod_inverse(y,m) % m;
	nx = nx * mod_inverse(y,n) % n;
	break;
    }
}

int main(){
    int N;
    ll mx = 0, nx = 0;
    cin >> N;
    while(N--){
	ll o, y;
	cin >> o >> y;
	calc(mx,nx,o,y);
    }
    ll s, t;
    extgcd(m,n,s,t);
    ll x = (m * s * nx + n * t * mx) % (m * n);
    if(x >= (ll)1<<31) x -= m * n; 
    cout << x << endl;
    return 0;
}
