#include <bits/stdc++.h>
using namespace std;
namespace solver
{
int n, m, lv[5010], id[5010], par[5010], left[5010], right[5010], idx;
string ans;
void dfs(int v)
{
        ans.push_back('(');
        int l = left[v], r = right[v];
        if(~l) {
                id[l] = ++idx;
                par[id[l]] = id[v];
                dfs(l);
        }
        if(~r) {
                id[r] = ++idx;
                par[id[r]] = id[v];
                dfs(r);
        }
        ans.push_back(')');
}

void solve()
{
        memset(left,-1,sizeof(left));
        memset(right,-1,sizeof(right));
        n = m;
        stack<pair<int,int> > st;
        st.push(make_pair(0,lv[0]));
        for (int i = 1; i < m; i++) {
                int v = i, l = lv[i];
                while(!st.empty() and st.top().second == l) {
                        left[n] = st.top().first;
                        right[n] = v;
                        st.pop();
                        v = n++;
                        l--;
                }
                st.push(make_pair(v,l));
        }
        if(st.size() != 1 or st.top().second != 0) {
                puts("NIE");
                return;
        }
        ans = "";
        id[st.top().first] = ++idx;
        dfs(st.top().first);
        for (int i = 1; i <= n; i++) printf("%d%c", par[i], i==n? '\n': ' ');
        puts(ans.c_str());
}

void input()
{
        scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", lv+i);
}
};
int main()
{
        solver::input();
        solver::solve();
        return 0;
}
