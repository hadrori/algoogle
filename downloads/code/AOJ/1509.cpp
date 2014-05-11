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

int main(){
    int a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e, a || b || c || d || e){
	int na, nb, nc, ans = 0;
	cin >> na >> nb >> nc;
	if(nc >= d)
	    ans = e * nc + b * nb + a * na;
	else{
	    int dcnt = d;
	    ans = c * nc + b * nb + a * na;
	    dcnt -= nc;
	    if(dcnt > nb){
		dcnt -= nb;
		nb = 0;
	    }else{
		nb -= dcnt;
		dcnt = 0;
	    }
	    if(dcnt > na){
		dcnt -= na;
		na = 0;
	    }else{
		na -= dcnt;
		dcnt = 0;
	    }
	    ans = min(ans, e * d + b * nb + a * na);
	}
	cout << ans << endl;
    }
    return 0;
}
