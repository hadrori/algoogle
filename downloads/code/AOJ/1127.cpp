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

struct Sphere{
    double x, y, z, r;
};

double pow2(double a){
    return a*a;
}

double center_distance(Sphere a, Sphere b){
    return sqrt(pow2(a.x-b.x)+pow2(a.y-b.y)+pow2(a.z-b.z));
}

bool overrap(Sphere a, Sphere b){
    return center_distance(a,b) <= (a.r + b.r);
}

double distanceSS(Sphere a, Sphere b){
    if(overrap(a,b)) return 0.0;
    return center_distance(a,b)-(a.r+b.r);
}

int main(){
    int n;
    while(cin>>n,n){
        vector<Sphere> cell;
        rep(i,n){
            Sphere s;
            cin >> s.x >> s.y >> s.z >> s.r;
            cell.pb(s);
        }
        vector<vector<double> > cost(n,vector<double>(n,0));
        rep(i,n)rep(j,i){
            cost[i][j] = distanceSS(cell[i],cell[j]);
            cost[j][i] = cost[i][j];
        }
        vector<bool> used(n,false);
        vector<double> d(n,INF);
        double ans = 0;
        d[0] = 0;

        while(1){
            int v = -1;
            rep(u,n) if(!used[u] && (v == -1 || d[u] < d[v])) v = u;

            if(v==-1) break;
            used[v] = true;
            ans += d[v];
            rep(u,n) d[u] = min(d[u], cost[v][u]);
        }
        printf("%.3f\n", ans);
    }
}


