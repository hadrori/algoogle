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

int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct S{
    int x, y, id, head;
    S(int x, int y, int id, int head):x(x),y(y),id(id),head(head){}
};

int main(){
    while(cin>>n,n){
        map<pii, int> id;
        map<pii, int> futon;
        set<pii> notused;
        int x, y;
        char dir;
        rep(i,n){
            cin >> x >> y >> dir;
            notused.insert(pii(x,y));
            id[pii(x,y)] = i;
            futon[pii(x,y)] = -1;
            int d = 3;
            if(dir == 'x') d = 2;
            x += dx[d];
            y += dy[d];
            notused.insert(pii(x,y));
            id[pii(x,y)] = i;
            futon[pii(x,y)] = -1;
        }
        bool ok = true;
        while(!notused.empty()){
            queue<S> que;
            pii p = *notused.begin();
            que.push(S(p.fst,p.snd,id[p],0));
            while(!que.empty()){
                S s = que.front();
                que.pop();
                rep(i,4){
                    int nx = s.x + dx[i], ny = s.y + dy[i];
                    pii np = pii(nx,ny);
                    if(futon.find(np) != futon.end()){
                        if(futon[np] != -1){
                            if(s.id == id[np]){
                                if(futon[np] == s.head){
                                    ok = false;
                                    break;
                                }
                                continue;
                            }
                            if(futon[np] != s.head){
                                ok = false;
                                break;
                            }
                            continue;
                        }
                        else{
                            if(s.id == id[np]) {
                                futon[np] = (s.head + 1) % 2;
                                que.push(S(nx, ny, s.id, futon[np]));
                                notused.erase(notused.find(np));
                                continue;
                            }
                            futon[np] = s.head;
                            que.push(S(nx, ny, id[np], s.head));
                            notused.erase(notused.find(np));
                            continue;
                        }                            
                    }
                }
                if(!ok) break;
            }
            if(!ok) break;
        }
        cout << (ok? "Yes": "No") << endl;
    }
    return 0;
}
