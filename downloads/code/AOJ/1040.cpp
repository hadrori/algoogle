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

typedef int Weight;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

Weight minimum_steiner_tree(const vector<int>& T, const Matrix &g){
    const int n = g.size();
    const int t = T.size();
    if(t <= 1) return 0;
    
    Matrix d(g);    // all-pair shortest
    //Warshall Floyd
    rep(k,n)rep(i,n)rep(j,n)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    Weight OPT[1 << t][n];
    rep(S,1<<t) rep(x,n)
        OPT[S][x] = INF;

    rep(p,t) rep(q,n)   // trivial case
        OPT[1 << p][q] = d[T[p]][q];

    repi(S,1,1<<t){   // DP step
        if(!(S & (S-1))) continue;
        rep(p,n) rep(E,S)
            if((E | S) == S)
                OPT[S][p] = min(OPT[S][p], OPT[E][p] + OPT[S-E][p]);
        rep(p,n) rep(q,n)
            OPT[S][p] = min(OPT[S][p], OPT[S][q] + d[p][q]);
    }
    
    Weight ans = INF;
    rep(S,1<<t) rep(q,n)
        ans = min(ans, OPT[S][q] + OPT[((1 << t) - 1) - S][q]);
    
    return ans;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int h, w;

bool inrange(int x, int y){
    return x >= 0 && x < w && y >= 0 && y < h;
}
int main(){
    while(cin >> h >> w, h || w){
	Matrix G(h*w, Array(h*w,INF));
	rep(i,h)rep(j,w){
	    rep(k,4)if(inrange(j+dx[k], i+dy[k])){
		G[i*w+j][(i+dy[k])*w+j+dx[k]] = 1;
		G[(i+dy[k])*w+j+dx[k]][i*w+j] = 1;
	    }
	    G[i*w+j][i*w+j] = 0;
	}
	vi T;
	rep(i,h)rep(j,w){
	    int t;
	    cin >> t;
	    if(t) T.pb(i*w+j);
	}
	cout << h*w - minimum_steiner_tree(T, G) - 1 << endl;
    }
    return 0;
}
