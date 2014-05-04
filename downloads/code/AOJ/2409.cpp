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

int N, M;
vector<pii> inter;

int main(){
    cin >> N >> M;
    inter.resize(M);
    rep(i,M) cin >> inter[i].first >> inter[i].second;
    sort(all(inter));
    int right = 0, cur = 0;
    int cnt = 0;
    bool used[128] = {false};
    while(true){
        if(right == N) {
            cout << cnt << endl;
            return 0;
        }
        
        int use = -1;
        while(cur < inter.size() && inter[cur].first <= right + 1){
            if(use < inter[cur].second) use = inter[cur].second;
            cur++;
        }
        if(use == -1) break;
        right = use;
        cnt++;
    }
    cout << "Impossible\n";
    return 0;
}
