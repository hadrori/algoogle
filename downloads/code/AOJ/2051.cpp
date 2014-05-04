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
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

namespace std {
    bool operator < (const P& a, const P& b){
        return abs(real(a) - real(b)) > EPS ? real(a) < real(b) : imag(a) < imag(b);
    }
}

/* 角度 */
double angle( P &a,  P &b){ return arg(conj(a)*b); }

/* 回転 */
P rotate( P& a, double th){ return a*polar(1.0, th); }

int main(){
    int n;
    while(cin >> n, n){
        G g1(n), g2(n);
        rep(i,n) cin >> g1[i].real() >> g1[i].imag();
        rep(i,n) cin >> g2[i].real() >> g2[i].imag();
        P c1 = P(0,0), c2 = P(0,0);
        rep(i,n){
            c1 += g1[i];
            c2 += g2[i];
        }
        c1 /= n;
        c2 /= n;
        rep(i,n){
            g1[i] -= c1;
            g2[i] -= c2;
        }
        sort(all(g1));
        double ans = INF;
        rep(i,n){
            G tg = g2;
            double th = angle(tg[i],g1[0]);
            rep(j,n) tg[j] = rotate(tg[j],th);
            sort(all(tg));
            bool ok = true;
            rep(j,n)if(abs(g1[j]-tg[j]) > EPS){
                ok = false;
                break;
            }
            if(ok){
                th = abs(th);
                if(th > PI) th = 2*PI - th;
                ans = min(ans, th);
            }
        }
        printf("%.11f\n", ans);
    }
    return 0;
}
