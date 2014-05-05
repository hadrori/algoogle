// Paste me into the FileEdit configuration dialog
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//#define int long long
#define repi(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (int)a; i >= (int)b; i--)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define my_unique(u) (u).erase(unique(all(u)),(u).end())
#define dump(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fst first
#define snd second
const double pi = acos(-1.0);
const int inf = 1e9;
const double eps = 1e-9;
template<class T> inline T sq(T x) { return x * x;}
template<class T> inline T mypow(T x, int e) { return e == 0? 1: e%2? x * pow(x,e-1): pow(x*x,e/2);}
template<class T> inline void chmax(T &x, T y) { if(x < y - eps) x = y;}
template<class T> inline void chmin(T &x, T y) { if(x > y + eps) x = y;}
inline bool eq(double x, double y) { return abs(x - y) < eps;}
inline int pow2(int e) { return 1LL << e;}
inline int lcm(int x, int y) { return x * y / __gcd(x,y);}
inline signed to_int(string s) { return atoi(s.c_str());}
inline int to_long(string s){
    stringstream ss;
    ss << s;
    int ret;
    ss >> ret;
    return ret;
}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef complex<double> point;
typedef vector<point> graph;
typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
// 4 directions
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
// 8 directions
const int ddi[] = {-1,-1,-1,0,1,1,1,0};
const int ddj[] = {-1,0,1,1,1,0,-1,-1};
int w, h;
inline bool inrange(int i, int j) { return j >= 0 && j < w && i >= 0 && i < h;}
class SplitStoneGame {
public:
    string win = "WIN", lose = "LOSE";
    int n;
    string winOrLose( vector <int> number ) {
        n = number.size();
        int cnt = 0;
        rep(i,n) if(number[i] > 1) cnt++;
        if(cnt == 0 or n < 3) return lose;
        if(n%2) return win;
        return lose;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int number[]              = {1, 1, 1};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int number[]              = {2, 2};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int number[]              = {1, 1, 2};
			string expected__         = "WIN";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int number[]              = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
			string expected__         = "WIN";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int number[]              = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          int number[]              = {2};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int number[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int number[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
