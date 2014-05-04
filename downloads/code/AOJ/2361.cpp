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
#define lb lower_bound
#define ub upper_bound
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
    int n;
    cin >> n;
    vector<vi> cost(n,vi(n));
    rep(i,n)rep(j,n) cin >> cost[i][j];
    string str = "";
    rep(i,n) str += i + '0';
    queue<string> que;
    que.push(str);
    map<string,int> d;
    d[str] = 0;
    while(!que.empty()){
	string s = que.top(); que.pop();
	int t = d[s];
	rep(i,n)repi(j,i+1,n){
	    string tmp = s;
	    swap(tmp[i],tmp[j]);
	    map<string,int>::iterator itr = d.find(tmp);
	    if(itr == d.end() || (*itr).second > cost[s[i]-'0'][s[j]-'0'] + t){
		d[tmp] = cost[s[i]-'0'][s[j]-'0'] + t;
		que.push(tmp);
	    }
	}
    }
    int ans = 0;
    repit(itr,d) ans = max(ans,(*itr).second);
    cout << ans << endl;
    return 0;
}
