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

int N;
double A, B;
double H[1024];

bool ok(double h){
    H[1] = h;
    repi(i,2,N){
	H[i] = 2*H[i-1] + 2 - H[i-2];
	if(H[i] < 0) return false;
    }
    B = H[N-1];
    return true;
}

int main(){
    cin >> N >> A;
    H[0] = A;
    double lb = -1, ub = 1000000;
    rep(_,100){
	double mid = (lb + ub) / 2;
	if(ok(mid)) ub = mid;
	else lb = mid;
    }
    printf("%.2f\n", B);
    return 0;
}
