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
typedef vector<int> vec;
typedef vector<vec> mat;

#define INF 100000000

int main(){
    int n;
    while(cin>>n,n){
        mat w(15,vec(15,INF));
        int m = 0; //街の総数
        rep(i,n){
            int a, b, c;
            cin >> a >> b >> c;
            w[a][b] = c;
            w[b][a] = c;
            m = max(m,a);
            m = max(m,b);
        }
        m++;
        rep(i,m) w[i][i] = 0;
        rep(k,m)rep(i,m)rep(j,m){
            w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
        }
        int ansm, answ = INF;
        rep(i,m){
            int sum = 0;
            rep(j,m) sum += w[i][j];
            if(answ > sum){
                answ = sum;
                ansm = i;
            }
        }
        cout << ansm << ' ' << answ << endl;
    }
}
