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

vector<pii> inter;
map<string,int> id;
int n, m;
string op = "+-/*";
bool memo[128][256];

int main(){
    cin >> m;
    inter.resize(m);
    rep(i,m){
        string str;
        cin >> str;
        id[str] = i;
        cin >> inter[i].fst >> inter[i].snd;
    }
    cin >> n;
    stack<int> st;
    rep(i,n){
        string s; cin >> s;
        if(op.find(s) == string::npos){
            map<string,int>::iterator itr = id.find(s);
            if(itr == id.end()) memo[i][atoi(s.c_str())] = true;
            else {
                int pos = (*itr).snd;
                repi(j,inter[pos].fst,inter[pos].snd+1) memo[i][j] = true;
            }
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(s == "+")
                rep(j,256)rep(k,256)
                    memo[i][(j+k)%256] |= memo[a][j] & memo[b][k];
            else if(s == "-")
                rep(j,256)rep(k,256)
                    memo[i][(j-k+256)%256] |= memo[a][j] & memo[b][k];
            else if(s == "*")
                rep(j,256)rep(k,256)
                    memo[i][j*k%256] |= memo[a][j] & memo[b][k];
            else if(s == "/"){
                if(memo[b][0]) {
                    cout << "error\n";
                    return 0;
                }
                rep(j,256)repi(k,1,256)
                    memo[i][j/k%256] |= memo[a][j] & memo[b][k];
            }

        }
        st.push(i);
    }
    cout << "correct\n";
    return 0;
}
