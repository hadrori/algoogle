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

int N;
vi X;
ll m;

bool ok(int n){
    ll cnt = 0;
    repit(itr,X)
	cnt += (ll)(X.end() - lower_bound(itr+1, X.end(), n + *itr));
    return cnt <= m / 2;
}

int main(){
    while(~scanf("%d", &N)){
	X.resize(N);
	m = N * (N - 1) / 2;
	repit(itr,X) scanf("%d", &*itr);
	sort(all(X));
	int lb = 0, ub = 1000000001;
	while(lb + 1 < ub){
	    int mid = (lb + ub) / 2;
	    if(ok(mid)) ub = mid;
	    else lb = mid;
	}
	cout << ub - 1 << endl;
    }
    return 0;
}
