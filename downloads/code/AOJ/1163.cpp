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

const int MAX_V = 1024;

struct edge{ int to, cap, rev; };

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb((edge){to, cap, G[to].size()});
    G[to].pb((edge){from, 0, G[from].size() - 1});
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    rep(i,G[v].size()){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    while(true){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}

int main(){
    int m, n;

    while(cin >> m >> n, m || n){
        rep(i,MAX_V) G[i].clear();
        int V = m + n + 2;
        int blue[512];
        bool path[512][512] = {false};
        rep(i,m){
            cin >> blue[i];
            add_edge(V - 2, i, 1);
        }
        rep(i,n){
            int red;
            cin >> red;
            add_edge(m + i, V - 1, 1);
            rep(j,m){
                if(__gcd(red,blue[j]) != 1){
                    add_edge(j, m + i, 1);
                }
            }
        }
        cout << max_flow(V - 2, V - 1) << endl;
    }
}
