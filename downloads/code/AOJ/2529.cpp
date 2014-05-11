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

string s;
int memo[16];

int main(){
    cin >> s;
    int cur = 0, prev = 0;
    cout << '>';
    rep(i,s.size()){
        prev = cur;
        cur = 0;
        rep(j,16)if(abs(memo[cur]-s[i]) > abs(memo[j]-s[i]))
            cur = j;
        rep(j,abs(cur-prev)) cout << (cur-prev<0? "<<": ">>");
        int d = s[i] - memo[cur];
        int sr = sqrt(abs(d));
        memo[cur] = (int)s[i];
        if(abs(d) < 8) rep(j,abs(d)) cout << (d<0? '-': '+');
        else {
            cout << '<';
            rep(j,abs(d)/sr) cout << '+';
            cout << "[>";
            rep(j,sr) cout << (d<0? '-': '+');
            cout << "<-]>";
            rep(j,abs(d)-abs(d)/sr*sr) cout << (d<0? '-': '+');
        }
        cout << '.';
    }

    return 0;
}
