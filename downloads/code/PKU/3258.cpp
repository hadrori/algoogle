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

int L, N, M;
vi dist;

bool can(int len){
    int prev = 0;
    int cnt = 0;
    rep(i,N){
	if(dist[i] - prev < len) cnt++;
	else prev = dist[i];
    }
    return cnt <= M;
}

int main(){
    cin >> L >> N >> M;
    rep(i,N){
	int t; cin >> t;
	dist.pb(t);
    }
    sort(all(dist));
    int lb = 0, ub = L;
    while(lb < ub){
	int mid = (lb + ub + 1) / 2;
	if(can(mid)) lb = mid;
	else ub = mid - 1;
    }
    cout << lb << endl;
    return 0;
}
