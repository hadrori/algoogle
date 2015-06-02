#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const string dir = "NESW";
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

struct query{
        int f1, f2, I, id;
        query(){}
        query(int f1, int f2, int I, int id):f1(f1),f2(f2),I(I),id(id){}
        bool operator<(const query &q) const{ return I < q.I;}
};

pii E[40010][4], info[40010], pos[40010];
int ans[10010];
query Q[10010];

int N, M, K;
int par[40010], rnk[40010];

void init(){
        for(int i = 0; i < N; i++){
                par[i] = i;
                rnk[i] = 1;
        }
}

int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
}

void unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        if(rnk[x] < rnk[y]) par[y] = x;
        else {
                par[x] = y;
                if(rnk[x] == rnk[y]) rnk[y]++;
        }
}

bool same(int x, int y){ return find(x) == find(y);}

bool visited[40010];
void dfs(int farm, int x, int y){
        if(visited[farm]) return;
        visited[farm] = 1;
        pos[farm] = pii(x, y);
        for(int d = 0; d < 4; d++)
                if(E[farm][d].first != -1){
                        int l = E[farm][d].second;
                        int nx = x + l * dx[d], ny = y + l * dy[d];
                        dfs(E[farm][d].first, nx, ny);
                }
}

int main(){
        scanf("%d%d", &N, &M);
        for(int i = 0; i < N; i++)
                for(int j = 0; j < 4; j++)
                        E[i][j] = pii(-1,-1);
        for(int i = 0; i < M; i++){
                int f1, f2, l; char d, nl;
                scanf("%d %d %d %c%c", &f1, &f2, &l, &d, &nl);
                f1--; f2--;
                int f = dir.find(d);
                E[f1][f] = pii(f2, l);
                E[f2][(f+2)%4] = pii(f1, l);
                info[i] = pii(f1,f2);
        }
        dfs(0,0,0);
        scanf("%d", &K);
        for(int i = 0; i < K; i++){
                int f1, f2, I;
                scanf("%d%d%d", &f1, &f2, &I);
                f1--; f2--;
                Q[i] = query(f1, f2, I, i);
        }
        sort(Q, Q+K);

        int cur = 0;
        init();
        for(int i = 0; i < K; i++){
                int f1 = Q[i].f1, f2 = Q[i].f2, I = Q[i].I;
                while(cur < I && cur < M){
                        unite(info[cur].first, info[cur].second);
                        cur++;
                }
                ans[Q[i].id] = -1;
                if(same(f1, f2))
                        ans[Q[i].id] = abs(pos[f1].first-pos[f2].first)+abs(pos[f1].second-pos[f2].second);
        }
        for(int i = 0; i < K; i++)
                printf("%d\n", ans[i]);
        return 0;
}
