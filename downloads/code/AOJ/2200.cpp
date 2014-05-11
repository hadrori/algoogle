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

int n, m, r;
int dl[256][256], ds[256][256];
int dp[1024][256];
vi z;

void init(){
    z.clear();
    rep(i,256)rep(j,256){
	dl[i][j] = INF;
	ds[i][j] = INF;
    }
    rep(i,1024)rep(j,256) dp[i][j] = INF;
    return;
}

void input(){
    int x, y, t;
    char sl;
    rep(i,m){
	cin >> x >> y >> t >> sl;
	x--; y--;
	if(sl == 'L'){
	    dl[x][y] = min(dl[x][y], t);
	    dl[y][x] = min(dl[y][x], t);
	}else {
	    ds[x][y] = min(ds[x][y], t);
	    ds[y][x] = min(ds[y][x], t);
	}
    }
    cin >> r;
    rep(i,r){
	cin >> t;
	t--;
	z.pb(t);
    }
    return;
}

void solve(){
    rep(k,n)rep(i,n)rep(j,n){
	if(i==j){
	    dl[i][j] = 0;
	    ds[i][j] = 0;
	}
	dl[i][j] = min(dl[i][j], dl[i][k] + dl[k][j]);
	ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
    }
    rep(i,n) dp[0][i] = ds[z[0]][i] + dl[i][z[0]];
    repi(i,1,r){
	rep(j,n)rep(k,n){
	    if(j!=k)dp[i][k] = min(dp[i][k],
			   dp[i-1][j]+dl[z[i-1]][j]+ds[j][k]+dl[k][z[i]]);
	    else dp[i][j] = min(dp[i][j],
			   dp[i-1][j]+dl[z[i-1]][z[i]]);
	}
    }
    int ans = INF;
    rep(i,n) ans = min(ans, dp[r-1][i]);
    cout << ans << endl;
    return;
}

int main(){
    while(cin >> n >> m, n||m){
	init();
	input();
	solve();
    }
}
