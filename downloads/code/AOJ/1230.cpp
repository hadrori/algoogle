#include <iostream>
#include <vector>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    int n, s;
    while(cin >> n, n){
        cin >> s;
        vector<int> m(2*n);
        rep(i, 0, 2*n){
            cin >> m[i];
        }
        vector<vector<int> > dp(2*n);
        rep(i, 0, 2*n){
            dp[i] = vector<int>(s+1);
            rep(j, 0, s+1){
                dp[i][j] = -1;
            }
        }

        rep(j, 1, s+1){
            rep(i, 0, 2*n){
                if(j == 1) dp[i][j] = 0;
                else {
                    rep(k, 1, m[i]+1){
                        if(j-k < 1) break;
                        else if(dp[(i+1)%(2*n)][j-k] == 0) dp[i][j] = 1;
                    }
                    if(dp[i][j] == -1)dp[i][j] = 0;
                }
            }
        }

        cout << dp[0][s] << endl;
    }
    
}