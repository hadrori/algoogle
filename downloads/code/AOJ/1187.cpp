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

struct S{
    int id, solved, pena;
    S(int id, int solved, int pena):id(id),solved(solved),pena(pena){}
    bool operator < (const S &s) const{
	if(solved != s.solved) return solved > s.solved;
	if(pena != s.pena) return pena < s.pena;
	return id > s.id;
    }
    bool operator == (const S &s) const{
	return (solved == s.solved && pena == s.pena);
    }
};

int main(){
    int M, T, P, R;
    while(cin>>M>>T>>P>>R, M||T||P||R){
	vector<S> team;
	int failed[400][16] = {0};
	rep(i,T) team.pb(S(i+1,0,0));
	rep(i,R){
	    int m, t, p, j;
	    cin >> m >> t >> p >> j;
	    t--;
	    if(!j){
		team[t].solved++;
		team[t].pena += m + failed[t][p];
	    }
	    else failed[t][p] += 20;
	}
	sort(all(team));
	rep(i,T) cout << team[i].id << (i==T-1? "": team[i]==team[i+1]? "=": ",");
	cout << endl;
    }
    return 0;
}
