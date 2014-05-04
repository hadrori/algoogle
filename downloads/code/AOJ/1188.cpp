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

int stoi(string num){
    int ret;
    stringstream s;
    s << num;
    s >> ret;
    return ret;
}

string str;
int cur;

int rec(){
    cur++;
    if(str[cur] != '[' && str[cur] != ']'){
	string t;
	while(str[cur] != '[' && str[cur] != ']')
	    t += str[cur++];
	cur++;
	return stoi(t) / 2 + 1;
    }
    vi vote;
    while(str[cur] != ']'){
	vote.pb(rec());
    }
    sort(all(vote));
    int ret = 0;
    rep(i,vote.size()/2+1) ret += vote[i];
    cur++;
    return ret;
}

int main(){
    int n;
    cin >> n;
    while(n--){
	cin >> str;
	cur = 0;
	cout << rec() << endl;
    }
    return 0;
}
