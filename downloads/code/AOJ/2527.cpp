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
#include <climits>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int main(){
    int n, k, x0;
    cin >> n >> k >> x0;
    if(!x0){
        cout << 0 << endl;
        return 0;
    }
    int cnt[1024];
    memset(cnt, 0, sizeof(cnt));
    ull x = x0;
    ull d = ULLONG_MAX / 1024;
    rep(i,n){
        ull y = (x + LLONG_MAX) / d;
        cnt[y]++;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
    }
    int sum = 0, exist = 0;
    rep(i,1024) {
        sum += cnt[i];
        if(sum >= k){
            exist = i;
            k -= sum - cnt[i] + 1;
            break;
        }
    }
    vector<ll> a;
    x = x0;
    rep(i,n){
        ull y = (x + LLONG_MAX) / d;
        if(y == exist) a.pb(x);
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
    }
    sort(all(a));
    cout << a[k] << endl;
    return 0;
}
