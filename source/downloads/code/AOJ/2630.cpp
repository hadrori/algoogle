#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const char base = 'a'-1;

inline int add(int &x, int y) { return x=(x+y)%mod;}
inline int mul(int x, int y) { return 1LL*x*y%mod;}

int n, dp[64][64][32][32]; // dp[l][r][a][b] := count the case of s[ [l,r) ][ a ] >= b
char s[64][32];

int solve(int l, int r, int a, int b)
{
        int &ret = dp[l][r][a][b];
        if(~ret) return ret;
        if(l >= r) return ret = 1; // this will happen in next for statement

        ret = 0;
        if(b == 27) return ret;
        // if r-l > 1 then s[ [l,r) ] == s[ [l,r) ], but we assume s[0] < s[1] < ...
        if(a == 20) return ret = r-l==1;

        add(ret, solve(l,r,a,b+1)); // calc the case of s[ [l,r) ][a] > b

        // calc the case of s[ [l,i) ][a] == b
        for (int i = l+1; i <= r; i++) {
                if((s[i-1][a] != base+b and s[i-1][a] != '?') or
                   (s[i-1][a] == '?' and b == 0)) break;
                add(ret, mul(solve(l,i,a+1,0), solve(i,r,a,b+1)));
        }
        return ret;
}

void input()
{
        memset(dp,-1,sizeof(dp));
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%s", s[i]);
                for (int j = strlen(s[i]); j < 20; j++) s[i][j] = base;
        }
}

int main()
{
        input();
        printf("%d\n", solve(0,n,0,0));
        return 0;
}
