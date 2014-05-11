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
typedef complex<double> P;
typedef vector<P> G;

int N, K, T, U, V, L;
int D[10010];

int main(){
    cin >> N >> K >> T >> U >> V >> L;
    rep(i,N){
        int t; cin >> t;
        D[t]++;
    }
    int have = 0;
    double ans = 0;
    int res = 0;
    int prev = 0;
    int pos = 0;
    repi(i,1,L+1){
//        cerr << ans << endl;
        if(res){
            res--;
            ans += 1.0 / V;
        }
        else ans += 1.0 / U;
        if(have && !res) {
            have--;
            res = V * T;
        }
        if(D[i]) {
            if(!res) {
                D[i]--;
                res = V * T;
            }
            if(have + D[i] > K){
                D[i]--;
                res = V * T;
                have = K;
            }
            else have += D[i];
        }
    }
    printf("%.8f\n", ans);
    return 0;
}
