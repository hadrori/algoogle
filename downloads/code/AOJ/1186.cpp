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

struct S{
    int w, h, diag;
    S(int w, int h):w(w),h(h){
	diag = h*h + w*w;
    }

    bool operator < (const S &s) const{
	if(diag < s.diag) return true;
	if(diag > s.diag) return false;
	return h < s.h; 
    }
};

int main(){
    vector<S> rect;
    repi(i,1,200)repi(j,i+1,200){
	rect.pb(S(j, i));
    }
    sort(all(rect));
    int h, w;
    while(cin >> h >> w, h || w){
	S s = S(w, h);
	S t = *(++lb(all(rect), s));
	cout << t.h << ' ' << t.w << endl;
    }
    return 0;
}
