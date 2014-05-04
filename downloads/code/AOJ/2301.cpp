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

int K;
double R, L, P, E, T;

double dfs(double r, double l, int k){
    if(r > T + E || l < T - E) return 0;
    if(k == K){
        if(abs((r + l) / 2 - T) <= E) return 1;
        return 0;
    }
    if(r >= T - E && l <= T + E) return 1;
    double ret = 0;
    double h = (r + l) / 2;
    if(h >= T) {
        ret += (1 - P) * dfs(r,h,k+1);
        ret += P * dfs(h,l,k+1);
    }
    else {
        ret += P * dfs(r,h,k+1);
        ret += (1 - P) * dfs(h,l,k+1);
    }
    return ret;
}

int main(){
    cin >> K >> R >> L >> P >> E >> T;
    printf("%.6f\n", dfs(R,L,0));
    return 0;
}
