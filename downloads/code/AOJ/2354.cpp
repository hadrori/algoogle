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

struct S{
    int w, v;
    S(int w, int v):w(w),v(v){}
    bool operator<(const S &s) const{
	return s.w * v < w * s.v;
    }
};

int main(){
    double N, W, ans = 0;
    cin >> N >> W;
    vector<S> p;
    rep(i,N){
	int w, v;
	cin >> w >> v;
	if(w <= 0 && v >= 0){
	    ans += v;
	    W -= w;
	}
	else if(w >= 0 && v <= 0) continue;
	else if(w < 0 && v < 0){
	    ans += v; W -= w;
	    p.pb(S(-w,-v));
	}
	else p.pb(S(w,v));
    }
    sort(rall(p));

    rep(i,p.size()){
	int tw = p[i].w, tv = p[i].v;
	double x = min(1.0, W/tw);
	ans += x * tv;
	W -= x * tw;
	if(W < EPS) break;
    }
    printf("%.8f\n",ans);
    return 0;
}
