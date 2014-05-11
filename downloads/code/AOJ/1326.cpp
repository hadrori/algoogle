#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
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

int main(){
    int p, q;
    while(cin >> p >> q, p || q){
        vector<string> P, Q;
        vector<int> Pind;
        cin.ignore();
        rep(i,p){
            string str; cin >> str;
            P.pb(str);
            int indent = 0;
            rep(j,str.size()){
                if(str[j] != '.') break;
                indent++;
            }
            Pind.pb(indent);
        }
        rep(i,q){
            string str; cin >> str;
            Q.pb(str);
        }
        vector<int> ans(q,-2);
        repi(R,1,21) repi(C,1,21) repi(S,1,21){
            int r = 0, c = 0, s = 0;
            bool ok = true;
            rep(i,p){
                if(R*r+C*c+S*s != Pind[i]){
                    ok = false;
                    break;
                }
                rep(j,P[i].size()){
                    switch (P[i][j]){
                    case '(': r++; break;
                    case ')': r--; break;
                    case '{': c++; break;
                    case '}': c--; break;
                    case '[': s++; break;
                    case ']': s--; break;
                    }
                }
            }
            if(!ok) continue;
            r = 0; c = 0; s = 0;
            rep(i,q){
                int tmp = R*r+C*c+S*s;
                if(ans[i] == -2) ans[i] = tmp;
                else if(ans[i] != tmp) ans[i] = -1;
                rep(j,Q[i].size()){
                    switch (Q[i][j]){
                    case '(': r++; break;
                    case ')': r--; break;
                    case '{': c++; break;
                    case '}': c--; break;
                    case '[': s++; break;
                    case ']': s--; break;
                    }
                }
            }
//            cerr << "R=" << R << " C=" << C << " S=" << S << endl;
//            rep(i,q) cerr << ans[i] << (i==q-1? '\n': ' ');
        }
        rep(i,q) cout << ans[i] << (i==q-1? '\n': ' ');
    }
    return 0;
}
