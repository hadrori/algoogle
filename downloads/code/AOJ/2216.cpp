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

int c[3] = {1000,500,100};

int main(){
    int a, b;
    while(cin >> a >> b, a || b){
        int n = b - a;
        int ans[3] = {0};
        rep(i,3){
            while(n/c[i]){
                n -= c[i];
                ans[i]++;
            }
        }
        cout << ans[2] << ' ' << ans[1] << ' ' << ans[0] << endl;
    }
}
