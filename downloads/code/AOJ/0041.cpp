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
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

string op = "+-*";
int n[4];
bool used[8];
string ans;
string seq;

pair<int,string> calc(string rpol){
    stack<int> st;
    stack<string> exp;
    rep(i,rpol.size()) {
        int t = op.find(rpol[i]);
        if(t < 0){
            st.push(rpol[i]-'0');
            string tmp = "";
            tmp += rpol[i];
            exp.push(tmp);
        }
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            string r = exp.top(); exp.pop();
            string s = exp.top(); exp.pop();
            exp.push("("+r+rpol[i]+s+")");
            switch (t){
            case 0: a += b; break;
            case 1: a -= b; break;
            case 2: a *= b; break;
            }
            st.push(a);
        }
    }
    return mp(st.top(), exp.top());
}

bool dfs(string rpol, int cnt){
    if(rpol.size() == 7){
        pair<int, string> res = calc(rpol);
        if(res.fst == 10){
            ans = res.snd;
            return true;
        }
        else return false;
    }

    rep(i,7)if(!used[i]){
        if(i > 3 && cnt < 2) continue;
        used[i] = true;
        if(dfs(rpol+seq[i],i>3? cnt-1: cnt+1)) return true;
        used[i] = false;
    }
    return false;
}

int main(){
    while(scanf("%d%d%d%d",n,n+1,n+2,n+3),n[0]){
        seq = "";
        ans = "0";
        memset(used,0,sizeof(used));
        rep(i,4) seq.pb(char(n[i]+'0'));
        rep(i,3){
            repi(j,i,3){
                repi(k,j,3){
                    seq.pb(op[i]); seq.pb(op[j]); seq.pb(op[k]);
                    if(dfs("", 0)) break;
                    seq.erase(seq.begin()+4,seq.end());
                }
                if(ans != "0") break;
            }
            if(ans != "0") break;
        }
        cout << ans << endl;
    }
    return 0;
}
