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

int n;
string str[16];
string tail[16][16];

string shorter(string a, string b){
    if(a.size() == b.size()) return a < b? a: b;
    else return a.size() < b.size()? a: b;
}

string connect(string a, string b){
    rep(i,a.size()){
        if(a[i] == b[0]){
            bool ok = true;
            rep(j,a.size()-i){
                if(j == b.size() || a[i+j] != b[j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                b.erase(b.begin(),b.begin()+a.size()-i);
                return a + b;
            }
        }
    }
    return a + b;
}

void solve(){

    string dp[1<<11][11];
    rep(i,n) dp[1<<i][i] = str[i];

    rep(S,1<<n)rep(v,n){
        if((S>>v) & 1){
            rep(u,n) if(!((S>>u) & 1)){
                string tmp = dp[S][v] + tail[v][u];
                if(dp[S|(1<<u)][u] != "")
                    dp[S|(1<<u)][u] = shorter(dp[S|(1<<u)][u],tmp);
                else dp[S|(1<<u)][u] = tmp;
            }
        }
    }
    string ans = dp[(1<<n)-1][0];
    rep(i,n) ans = shorter(ans, dp[(1<<n)-1][i]);
    cout << ans << endl;
    return;
}

int main(){
    while(cin>>n,n){

        vector<string> in(n);
        rep(i, n) cin >> in[i];
        bool del[16] = {0};
        sort(all(in));
        UNIQUE(in);
        n = in.size();
        rep(i,n)rep(j,n)
            if(i != j && in[i].find(in[j]) != string::npos)
                del[j] = 1;
        int cnt = 0;
        rep(i,n) if(!del[i]) str[cnt++] = in[i];
        n = cnt;
        rep(i,n) rep(j,n) if(i != j)
            tail[i][j] = connect(str[i], str[j]).substr(str[i].size());
        solve();
    }
}
