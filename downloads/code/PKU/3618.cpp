#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int T, N, ans;
int t, xn[50010], xp[50010], nr, pr;
int pos, nl, pl;

int main(){
    scanf("%d%d", &T, &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &t);
        if(t < 0) xn[nr++] = -t;
        else xp[pr++] = t;
    }
    sort(xn, xn+nr);
    sort(xp, xp+pr);
    while(N--){
        if(nl < nr && pl < pr){
            if(xn[nl] < xp[pl]){
                T -= abs(-xn[nl] - pos);
                pos = -xn[nl++];
            }
            else {
                T -= abs(xp[pl] - pos);
                pos = xp[pl++];
            }
        }
        else if(nl < nr){
            T -= abs(-xn[nl] - pos);
            pos = -xn[nl++];
        }
        else {
            T -= abs(xp[pl] - pos);
            pos = xp[pl++];
        }
        if(T < 0) break;
        ans++;
    }
    printf("%d\n", ans);
}
