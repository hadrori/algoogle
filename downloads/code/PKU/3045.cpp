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
struct S{
    int w, s;
    S(int w, int s):w(w),s(s){}
    bool operator < (const S &t) const{ return w + s < t.w + t.s;}
};

int main(){
    cin >> N;
    vector<S> cows;
    rep(i,N){
	int w, s; scanf("%d %d", &w, &s);
	cows.pb(S(w,s));
    }
    sort(rall(cows));
    int sum = 0, ans = -INF;
    repd(i,N-1,0){
	ans = max(ans, sum - cows[i].s);
	sum += cows[i].w;
    }
    cout << ans << endl;
    return 0;
}
