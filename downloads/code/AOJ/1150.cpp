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

int w, h;
char cliff[64][32];
int dx[] = {1,1,2,1,2,3,1,2,1};
int dy[] = {2,1,1,0,0,0,-1,-1,-2};

struct S{
    int x, y, cst, prev;
    S(int x, int y, int cst, int prev):x(x),y(y),cst(cst),prev(prev){}
    bool operator > (const S &s) const{
	return cst > s.cst;
    }
};

bool can(int x, int y){
    return (x >= 0 && x < w && y >= 0 && y < h && cliff[y][x] != 'X');
}

int solve(){

    int ans = INF;
    rep(i,2){ // first foot
	int nfoot = i? 1: -1; //next foot
	int table[64][32][2];
	rep(j,64)rep(k,32)rep(l,2) table[j][k][l] = INF;
	
	priority_queue<S, vector<S>, greater<S> > que;
	rep(x,w)if(cliff[h-1][x] == 'S'){
	    que.push(S(x,h-1,0,nfoot));
	    table[h-1][x][i] = 0;
	}

	while(!que.empty()){
	    S st = que.top(); que.pop();
	    int x = st.x, y = st.y, f = st.prev;
	    if(st.cst > table[y][x][(2+f)%3]) continue;
	    /*
	    cerr << "cur: (" << x << "," << y << ")\n";
	    cerr << "cost: " << st.cst << endl;
	    cerr << "Foot: " << f << endl;
	    */
	    f *= -1;
	    rep(i,9){
		int nx = x+f*dx[i], ny = y+dy[i];
//		cerr << "hoge: (" << nx << "," << ny << ")\n";
		if(can(nx,ny)){
		    if(cliff[ny][nx] == 'T'){
			ans = min(ans, st.cst);
			break;
		    }
		    if(table[ny][nx][(2+f)%3] >
		       st.cst + cliff[ny][nx] - '0'){
			table[ny][nx][(2+f)%3] = st.cst+cliff[ny][nx]-'0';
			que.push(S(nx,ny,table[ny][nx][(2+f)%3],f));
		    }
		}
	    }
	}
	/*
	rep(y,h)rep(x,w){
	    printf("%.9d", table[y][x][i]);
	    cerr << (x==w-1? '\n': ' ');
	}
	cerr << endl;
	*/
    }
    cout << (ans==INF? -1: ans) << endl;
}

int main(){
    while(cin>>w>>h,w||h){
	rep(i,h)rep(j,w) cin >> cliff[i][j];
	solve();
    }
}
