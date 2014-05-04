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

ll N, M;
ll p[100010], oncnt[100010], offcnt[100010];
ll s[100010], t[100010];

int main(){
    cin >> N >> M;
    M += 2;
    rep(i,N) cin >> s[i] >> t[i];
    rep(i,M-2) cin >> p[i];
    p[M-1] = INF;
    p[M-2] = 0;
    sort(p, p+M);
    ll ans = 0;
    rep(i,N){
        ll tmp = 0;
        if(s[i] > t[i]){
            ll *lb = lower_bound(p,p+M,s[i]), *lb2 = lower_bound(p,p+M,t[i]);
            lb--; lb2--;
            tmp = lb - lb2;
            ans -= *(lb+1) - s[i];
            offcnt[lb + 1 - p]--;
            if(tmp % 2){
                oncnt[lb2 + 1 - p]++;
            }
            else {
                ans -= t[i] - *lb2;
                oncnt[lb2 - p]++;
            }
            /*
            cerr << i << "\n -> lb: " << lb - p << "\n   lb2: " << lb2 - p << endl;
            cerr << *lb << ' ' << *lb2 << endl;
            */
        }
        else{
            ll *lb = lower_bound(p,p+M,t[i]), *lb2 = lower_bound(p,p+M,s[i]);
            lb--; lb2--;
            tmp = lb - lb2;
            ans -= s[i] - *lb2;
            oncnt[lb2 - p]++;
            if(tmp % 2){
                offcnt[lb - p]--;
            }
            else{
                ans -= *(lb+1) - t[i];
                offcnt[lb + 1 - p]--;
            }
            /*
            cerr << i << "\n -> lb: " << lb - p << "\n   lb2: " << lb2 - p << endl;
            cerr << *lb << ' ' << *lb2 << endl;
            */
        }
    }
//    rep(i,M) cerr << cnt[i] << endl;
//    sort(s,s+N);
//    sort(t,t+N);
    ll on = 0, off = 0;
    on += oncnt[0];
//    cerr << cnt[0] << endl;
//    cerr << on << endl;
    repi(i,1,M){
//        cerr << cnt[i] << endl;
        ans += on * (p[i] - p[i-1]);
        on += offcnt[i];
        swap(on, off);
        on += oncnt[i];
//        cerr << on << endl;
    }
    cout << ans << endl;
    return 0;
}
