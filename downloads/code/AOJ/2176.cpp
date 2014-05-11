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

int n, d;

int main(){
    while(cin >> n >> d, n || d){
        vector<vi> missiles(n);
        vi cap(n,0);
        rep(i,n){
            int m, c;
            cin >> m;
            missiles[i].resize(m);
            rep(j,m){
                cin >> missiles[i][j];
                cap[i] += missiles[i][j];
            }
        }
        while(true){
            bool erased = false;
            rep(i,n)if(missiles[i].size()){
                while(missiles[i].size()){
                    cap[i] -= missiles[i].back();
                    if(*max_element(all(cap)) - cap[i] <= d){
                        missiles[i].pop_back();
                        erased = true;
                    }
                    else {
                        cap[i] += missiles[i].back();
                        break;
                    }
                }
            }
            if(!erased) break;
        }
        bool ok = true;
        /*
        rep(i,n){
            rep(j,missiles[i].size()) cerr << missiles[i][j] << ' ';
            cerr << endl;
        }
        */
        rep(i,n) if(missiles[i].size()) ok = false;
        cout << (ok? "Yes": "No") << endl;
    }
    return 0;
}
