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

int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        vector<string> str;
        string tmp;
        getline(cin,tmp);
        stringstream ss;
        ss << tmp;
        while(ss >> tmp) str.pb(tmp);
        int a = 0, b = 0;
        rep(i,str.size())if(str[i].size() == 4){
            repi(j,3,26*26)if(__gcd(j,26) == 1){
                rep(k,26){
                    string s = "this", t = "that";
                    rep(u,4){
                        s[u] = (j * (s[u]-'a') + k) % 26 + 'a';
                        t[u] = (j * (t[u]-'a') + k) % 26 + 'a';
                    }
                    if(s == str[i] || t == str[i]){
                        a = j; b = k;
                        break;
                    }
                }
                if(a) break;
            }
            if(a) break;
        }
        string abc = "abcdefghijklmnopqrstuvwxyz";
        rep(i,26) abc[i] = (a * i + b) % 26 + 'a';
        rep(i,str.size()){
            rep(j,str[i].size()) cout << (char)(abc.find(str[i][j]) + 'a');
            cout << (i==str.size()-1? '\n': ' ');
        }
    }
    return 0;
}
