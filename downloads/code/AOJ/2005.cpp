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

int main(){
    int n, m, s, g1, g2;
    while(cin >> n >> m >> s >> g1 >> g2, n||m||s||g1||g2){
        s--; g1--; g2--;
        vector<vi> c(n,vi(n,INF));
        rep(i,m){
            int b1, b2, c1;
            cin >> b1 >> b2 >> c1;
            c[--b1][--b2] = c1;
        }
        rep(i,n) c[i][i] = 0;
        rep(k,n) rep(i,n) rep(j,n){
            c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
        }
        int ans = INF;
        rep(i,n){
            ans = min(ans, c[s][i] + c[i][g1] + c[i][g2]);
        }
        cout << ans << endl;
    }
}
