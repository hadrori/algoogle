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
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

vi primes;
bool p[60000];

const int MAX_N = 60000;
int main(){
    memset(p,-1,sizeof(p));
    p[0] = p[1] = false;
    rep(i,MAX_N)if(p[i]){
        primes.pb(i);
        for(int j = 2 * i; j < MAX_N; j += i)
            p[j] = false;
    }
    int n;
    while(cin >> n){
        vi::iterator itr = lower_bound(all(primes),n);
        if(p[n]) cout << *(itr-1) << ' ' << *(itr+1) << endl;
        else cout << *(itr-1)<< ' ' << *itr<< endl;
    }
    return 0;
}
