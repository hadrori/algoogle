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

ll Q, N, M;

ll calc(ll i, ll j){
    return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

bool lower(ll n){
    ll cnt = 0;
    repi(j,1,N+1){
	int lb = 0, ub = N + 1;
	while(lb + 1 < ub){
	    int i = (lb + ub) / 2;
	    if(calc(i,j) < n) lb = i;
	    else ub = i;
	}
	cnt += lb;
    }
    return cnt >= M;
}

int main(){
    scanf("%lld", &Q);
    while(Q--){
	scanf("%lld %lld", &N, &M);
	ll lb = -1000000000000, ub = 1000000000000;
	while(lb + 1 < ub){
	    ll mid = (lb + ub) / 2;
	    if(lower(mid)) ub = mid;
	    else lb = mid;
	}
	printf("%lld\n", lb);
    }
    return 0;
}
