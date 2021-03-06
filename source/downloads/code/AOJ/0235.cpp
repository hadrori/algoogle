#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

static const int INF = 10000000;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n;
    while(cin >> n, n){
        mat br(n,vec(n,INF));
        rep(i,n-1) {
            int a, b, c;
            cin >> a >> b >> c;
            br[a][b] = c;
        }
    }
}
