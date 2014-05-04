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

int M, N;
vector<string> board;
int di[] = {-1,0,1,0};
int dj[] = {0,-1,0,1};

bool inrange(int i, int j){ return i >= 0 && i < M && j >= 0 && j < N;}

int check(){
    int ret = 0;
    rep(i,M)rep(j,N)if(board[i][j] == '.'){
        pii flag[32];
        rep(k,32) flag[k] = pii(-1,-1);
        rep(k,4){
            int ni = i, nj = j;
            while(inrange(ni,nj) && board[ni][nj] == '.'){
                ni += di[k]; nj += dj[k];
            }
            if(inrange(ni,nj)){
                int c = board[ni][nj] - 'A';
                if(flag[c].fst >= 0){
                    board[ni][nj] = '.';
                    board[flag[c].fst][flag[c].snd] = '.';
                    ret += 2;
                }
                else flag[c] = pii(ni,nj);
            }
        }
    }
    return ret;
}

int main(){
    cin >> M >> N;
    board.resize(M);
    rep(i,M) cin >> board[i];
    int ans = 0;
    int tmp;
    while(true){
        tmp = check();
        if(!tmp) break;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
