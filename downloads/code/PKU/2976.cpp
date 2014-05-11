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

int n, k;
vector<ll> a, b;

bool can(double val){
    vector<double> v;
    rep(i,n) v.pb(100.0 * a[i] - val * b[i]);
    sort(rall(v));
    double sum = 0;
    rep(i,n-k) sum += v[i];
    return sum >= 0;
}

int main(){
    while(cin >> n >> k, n || k){
	a.resize(n); b.resize(n);
	rep(i,n) scanf("%lld", &a[i]);
	rep(i,n) scanf("%lld", &b[i]);
	double lb = 0, ub = 128;
	rep(_,100){
	    double mid = (lb + ub) / 2;
	    if(can(mid)) lb = mid;
	    else ub = mid;
//	    cerr << lb << ' ' << ub << endl;
	}
	int ans = (int)(lb + 0.5);
	cout << ans << endl;
    }
    return 0;
}
