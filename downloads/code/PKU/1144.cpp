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
//typedef vector<P> G;
typedef vector<vi> G;

vector<int> articulation;
int ord[1000000], low[1000000];
bool vis[1000000];

const int MAX = 1000;
G g;

void dfs(int v, int p, int &k)
{
    vis[v] = true;

    ord[v] = k++;
    low[v] = ord[v];

    bool isArticulation = false;
    int ct = 0;

    for (int i = 0; i < g[v].size(); i++){
        if (!vis[g[v][i]]){
            ct++;
            dfs(g[v][i], v, k);
            low[v] = min(low[v], low[g[v][i]]);
            if (~p && ord[v] <= low[g[v][i]]) isArticulation = true;
        }
        else if (g[v][i] != p){
            low[v] = min(low[v], ord[g[v][i]]);
        }
    }

    if (p == -1 && ct > 1) isArticulation = true;
    if (isArticulation) articulation.push_back(v);
}

int main(){
    int n;
    while(scanf("%d", &n), n){
        g.clear();
        g.resize(n);
        int t;
        while(scanf("%d", &t), t){
            t--;
            string str;
            getline(cin, str);
            stringstream ss;
            ss << str;
            int v;
            while(ss >> v) {
                v--;
                g[t].pb(v);
                g[v].pb(t);
            }
        }
        memset(vis,0,sizeof(vis));
        memset(ord,0,sizeof(ord));
        memset(low,0,sizeof(low));
        articulation.clear();
        int k = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs(i, -1, k);

        sort(articulation.begin(), articulation.end());
        printf("%d\n", (int)articulation.size());
    }    
    return 0;
}
