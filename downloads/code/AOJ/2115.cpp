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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef ll number;
typedef number* array;
typedef array* matrix;

int mod;

matrix new_matrix(int n, int m){
    matrix A = new array[n];
    for(int i = 0; i < n; i++){
        A[i] = new number[m];
        for(int j = 0; j < m; j++) A[i][j] = 0;
    }
    return A;
}

//n*nの単位行列
matrix identity(int n){
    matrix A = new_matrix(n,n);
    for(int i = 0; i < n; i++) A[i][i] = 1;
    return A;
}
//p*n行列とn*q行列の積
matrix mul_matrix(matrix A, matrix B, int p, int n, int q){
    matrix C = new_matrix(p,q);
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k]*B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

//n*n行列の累乗
matrix pow_matrix(matrix A, int n, int e){
    return e==0? identity(n):
        e%2==0? pow_matrix(mul_matrix(A,A,n,n,n),n,e/2):
        mul_matrix(A,pow_matrix(A,n,e-1),n,n,n);
}

int n, l;
int dx[] = {-1,0,-1,0,1,0,1};
int dy[] = {-1,-1,0,0,0,1,1};
//int ldx[] = {0,1,-1,0,1,-1,0};
//int ldy[] = {-1,-1,0,0,0,1,1};

bool inrange(int x, int y){
    if(y<n) return (y>=0 && y<2*n-1 && x>=0 && x<n+y);
    return (y>=0 && y<2*n-1 && x>=y-n+1 && x<2*n-1);
}

int main(){
    int cas = 1;
    while(cin >> n >> mod >> l, n || mod || l){
//        cerr << n << mod << l << endl;
        int N = 2*n - 1;
        matrix col = new_matrix(N*N,1);
        rep(y,N){
            if(y<n) rep(x,n+y) cin >> col[y*N+x][0];
            else repi(x,y-n+1,N) cin >> col[y*N+x][0];
        }
        matrix seq = new_matrix(N*N,N*N);
        rep(y,N){
            if(y<n){
                rep(x,n+y) rep(k,7){
                    if(inrange(x+dx[k],y+dy[k])) seq[y*N+x][(y+dy[k])*N+x+dx[k]] = 1;
                }
            }else{
                repi(x,y-n+1,N) rep(k,7){
                    if(inrange(x+dx[k],y+dy[k])) seq[y*N+x][(y+dy[k])*N+x+dx[k]] = 1;
                }
            }
        }
/*
        rep(y,N*N){
            rep(x,N*N) cerr << seq[y][x];
            cerr << endl;
        }

//        rep(i,N*N) cerr << col[i][0] << endl;
        matrix tmp = pow_matrix(seq,N*N,l);
        /*
        rep(y,N*N){
            rep(x,N*N) cerr << tmp[y][x];
            cerr << endl;
        }
        */
        matrix ans = mul_matrix(pow_matrix(seq,N*N,l),col,N*N,N*N,1);
//        rep(i,N*N) cerr << ans[i][0] << endl;
        ll cnt = 0;
        rep(i,N*N) cnt += ans[i][0];
        cout << "Case " << cas++ << ": " << cnt << endl;

    }
}
