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
    double val;
    int id;
    S(){}
    S(double val, int id):val(val),id(id){}
    bool operator < (const S s) const{ return val < s.val;}
};

int n, k;
int v[100010], w[100010];
S u[100010];


bool can(double s){
    rep(i,n) u[i] = S(v[i] - s * w[i],i+1);
    sort(u,u + n);
    double sum = 0;
    rep(i,k) sum += u[n - i - 1].val;
    return sum >= 0;
}

int main(){
    cin >> n >> k;
    rep(i,n) scanf("%d %d", &v[i], &w[i]);
    double lb = 0, ub = 10000000;
    rep(i,50){
	double mid = (lb + ub) / 2;
	if(can(mid)) lb = mid;
	else ub = mid;
    }
    rep(i,k) cout << u[n - i - 1].id << (i==k-1? '\n': ' ');
    return 0;
}
