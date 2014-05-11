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
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-5
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;
typedef double number;
typedef vector<number> array;
typedef vector<array> matrix;

vector<double> v;
//Gauss消去法
//pivot選択なしなので精度悪いっぽい(未確認)
array gauss(matrix &A, array &b){
    int n = b.size();
    matrix B(n,array(n+1));
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) B[i][j] = A[i][j];
    for(int i = 0; i < n; i++) B[i][n] = b[i];

    for(int k = 0; k < n-1; ++k){
	for(int i = k + 1; i < n; ++i){
	    double a = B[i][k] / B[k][k];
	    for(int j = k + 1; j < n+1; ++j){
		B[i][j] = B[i][j]-a*B[k][j];
	    }
	}
    }
    B[n-1][n] = B[n-1][n]/B[n-1][n-1];
    for(int i = n-2; i >= 0; --i){
	double ax = 0.0;
	for(int j = i + 1; j < n; ++j){
	    ax += B[i][j]*B[j][n];
	}
	B[i][n] = (B[i][n]-ax)/B[i][i];
    }
    array x(n);
    for(int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}

//Gauss-Jordan消去法(pivot選択あり)
//遅い Gauss消去法の1.5倍ぐらいになることも
array gauss_jordan(matrix &A, array &b){
    int n = b.size();
    matrix B(n,array(n+1));
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) B[i][j] = A[i][j];
    for(int i = 0; i < n; i++) B[i][n] = b[i];
    for(int i = 0; i < n; i++){
	int pivot = i;
	for(int j = i; j < n; j++){
	    if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
	}
	swap(B[i],B[pivot]);
	//解がないか一意でない
	if(abs(B[i][i]) < EPS){
	    array x;
	    return x;
	}

	for(int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
	for(int j = 0; j < n; j++){
	    if(i!=j){
		for(int k = i + 1; k <= n; k++) B[j][k] -= B[j][i]*B[i][k];
	    }
	}
    }
    array x(n);
    for(int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}

int d;

array solve_eq(int m, int n){
    matrix A(d+1,array(d+1));
    array b(d+1);
    int cnt = 0;
    rep(i,d+3)if(i != m && i != n){
	b[cnt] = v[i];
	rep(j,d+1) A[cnt][j] = pow(1.0*i,1.0*j);
	cnt++;
    }
    return gauss(A,b);
}

int main(){
    while(cin >> d, d){
	v.resize(d+3);
	int ans = -1;
	rep(i,d+3) cin >> v[i];
	rep(i,d+3){
	    repi(j,i+1,d+3){
		array b = solve_eq(i,j);
		double e = 0, f = 0;
		rep(k,d+1) e += pow(1.0*i,1.0*k) * b[k];
		rep(k,d+1) f += pow(1.0*j,1.0*k) * b[k];
		if(abs(e-v[i]) > EPS && abs(f-v[j]) < EPS){
		    ans = i;
		    break;
		}
		if(abs(e-v[i]) < EPS && abs(f-v[j]) > EPS){
		    ans = j;
		    break;
		}
	    }
	    if(ans >= 0) break;
	}
	cout << ans << endl;
    }
    return 0;
}
