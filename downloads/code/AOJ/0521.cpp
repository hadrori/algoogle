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

typedef long long ll;

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        n = 1000 - n;
        int ans = 0;
        int c[6] = {500,100,50,10,5,1};
        rep(i,6){
            while(n/c[i]){
                ans++;
                n -= c[i];
            }
        }
        cout << ans << endl;
    }
}
