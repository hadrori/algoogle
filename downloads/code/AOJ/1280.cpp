#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct edge{
    int from, to, w;
    edge(int from, int to, int w):from(from),to(to),w(w){}
    bool operator < (const edge &e)const{
        return w < e.w;
    }
};

int n, m;
int parent[128];

int root(int x){
    if(parent[x] == x) return x;
    else return root(parent[x]);
}

int main(){
    while(cin >> n >> m, n || m){
        vector<edge> E;
        rep(i,m){
            int a, b, w; cin >> a >> b >> w;
            a--; b--;
            E.pb(edge(a,b,w));
        }
        int ans = INF;
        sort(all(E));
        rep(i,m){
            int k = 0;
            rep(j,n) parent[j] = j;
            repi(j,i,m){
                int p = root(E[j].from), q = root(E[j].to);
                if(p != q){
                    parent[q] = p;
                    k++;
                    if(k == n-1){
//                        if(ans > E[j].w - E[i].w) cerr << E[i].w << ' ' << E[j].w << endl;
                        ans = min(ans, E[j].w - E[i].w);
                        break;
                    }
                }
            }
        }
        cout << (ans==INF? -1: ans) << endl;
    }
    return 0;
}
