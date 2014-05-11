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
typedef vector<P> G;
const int MAX = 21;
ll fact[MAX];

ll comb(int n, int k){
    return fact[n]/fact[k]/fact[n-k];
}
int main(){
    string str;
    cin >> str;
    int cnt[26] = {0};
    rep(i,str.size()) cnt[str[i]-'a']++;
    int o = 0;
    rep(i,26){
	if(cnt[i] % 2) o++;
	cnt[i] /= 2;
    }
    if((!(str.size()%2) && o) || (str.size()%2 && o > 1)){
	cout << 0 << endl;
	return 0;
    }
    ll ans = 1, res = str.size()/2;
    fact[0] = 1;
    repi(i,1,MAX) fact[i] = fact[i-1] * i;
    rep(i,26)if(cnt[i]){
	ans *= comb(res,cnt[i]);
	res -= cnt[i];
    }
    cout << ans << endl;
    return 0;
}
