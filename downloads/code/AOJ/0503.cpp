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

int n, m;

struct S{
    int a, b, c;
    int from, to;
    S(int a, int b, int c, int from, int to):a(a),b(b),c(c),from(from),to(to){}
};

int main(){
    while(cin>>n>>m,n||m){
        int cup[3] = {0};
        rep(i,3){
            int t;
            cin >> t;
            rep(j,t){
                int c;
                cin >> c;
                cup[i] |= 1<<c;
            }
        }
    }
}
