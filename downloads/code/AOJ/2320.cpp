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

int H, W;
ll L;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool inrange(int x, int y){ return x >= 0 && x < W && y >= 0 && y < H;}

int main(){
    while(cin >> H >> W >> L, H || W || L){
        vector<string> maze(H);
        rep(i,H) cin >> maze[i];
        int x, y, dir;
        rep(i,H)rep(j,W){
            if(maze[i][j] == 'W'){ dir = 0; x = j; y = i; break;}
            else if(maze[i][j] == 'N'){ dir = 1; x = j; y = i; break;}
            else if(maze[i][j] == 'E'){ dir = 2; x = j; y = i; break;}
            else if(maze[i][j] == 'S'){ dir = 3; x = j; y = i; break;}
        }
        int field[128][128][4];
        memset(field,-1,sizeof(field));
        field[y][x][dir] = 0;
        ll turn = 1;
        bool rooped = false;
        while(turn <= L){
            int nx, ny, ndir;
            rep(i,4){
                ndir = (dir+i)%4;
                nx = x + dx[ndir];
                ny = y + dy[ndir];
                if(inrange(nx, ny) && maze[ny][nx] != '#'){
                    x = nx; y = ny; dir = ndir;
                    break;
                }
            }
            if(!rooped && field[y][x][dir] >= 0){
                rooped = true;
                ll roop = turn - field[y][x][dir];
                turn += (L - turn) / roop * roop;
                turn++;
            }
            else{
                field[y][x][dir] = turn;
                turn++;
            }
        }
        cout << y+1 << ' ' << x+1 << ' ';
        cout << (dir==0? 'W': dir==1? 'N': dir==2? 'E': 'S') << endl;
    }
    return 0;
}
