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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool p[10010];
vi prm;

void pcalc(){
    rep(i,10010) p[i] = (i < 2)? false: true;
    rep(i,10010)if(p[i]){
        prm.pb(i);
        for(int j = i*2; j < 10010; j += i) p[j] = false;
    }
}

int main(){
    pcalc();
    int n;
    while(cin >> n, n){
        int left = 0, right = 0, sum = 2;
        int ans = 0;
        do{
            if(sum > n) sum -= prm[left++];
            if(sum < n) sum += prm[++right];
            if(sum == n) {
                ans++;
                sum -= prm[left++];
            }
        }while(prm[right] <= n && left != right);

        cout << ans << endl;
    }
}
