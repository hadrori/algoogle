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

typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    while(cin >> n, n){
        vector<P> br;
        rep(i,n){
            int a, b;
            cin >> a >> b;
            br.pb(P(b,a));
        }
        sort(br.begin(),br.end());
        int w = 0;
        rep(i,n){
            if(w + br[i].second <= br[i].first) w += br[i].second;
            else {
                w = -1;
                break;
            }
        }
        if(w==-1) cout << "No\n";
        else cout << "Yes\n";
    }
}
