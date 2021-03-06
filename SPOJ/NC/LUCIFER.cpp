/*
 * FILE: LUCIFER.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 14-02-19 12:38:07 (+06)
 * LAST MODIFIED:
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 14-02-19     1.0         Deleted code is debugged code.
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
 */

///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <vector>
#include <tuple>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>
#include <unistd.h> // unsigned int sleep(unsigned int seconds);

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef long double         llf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vl;

#define _USE_MATH_DEFINES

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(a, val)    memset((a), (val), sizeof((a)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n'
    #define sp              cerr << ' '
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << '\n'
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << '\n'
#else
    #define nl
    #define sp
    #define ckk
    #define debug1(x)
    #define debug2(x, y)
    #define debug3(x, y, z)
#endif

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

vector<int> num;
int dp;
bool isPrime[100];

void sieve (int n) {
    int root = (int) ceil (sqrt (n));
    isPrime[0] = isPrime[1] = true;

    for (int i = 4; i < n; i += 2) {
        isPrime[i] = true;
    }

    for (int i = 3; i <= root; i += 2) {
        if (!isPrime[i]) {
            for (int j = i * i; j < n; j += 2 * i) {
                isPrime[j] = true;
            }
        }
    }
}


int digitDP (int pos, int oddSum, int evenSum, bool smallBefore,
             bool anyNonZero) {
    if (pos == (int) num.size()) {
        int tmp = (evenSum - oddSum);
        //debug1(tmp);
        return !isPrime[tmp];
    }

    int res = 0, limit = smallBefore ? 9 : num[pos];

    for (int dgt = 0; dgt <= limit; dgt++) {
        if (anyNonZero | (dgt > 0)) {
            if ((((int) num.size() - pos) & 1)) {
                res += digitDP (pos + 1, oddSum + dgt, evenSum, \
                                (limit < num[pos]) | smallBefore, true);

            } else {
                res += digitDP (pos + 1, oddSum, evenSum + dgt, \
                                (limit < num[pos]) | smallBefore, true);
            }

        } else {
            res += digitDP (pos + 1, oddSum, evenSum, \
                            (limit < num[pos]) | smallBefore, false);
        }
    }

    return res;
}

int solve (int n) {
    num.clear();

    while (n > 0) {
        num.push_back (n % 10);
        n /= 10;
    }

    reverse (num.begin(), num.end());
    return digitDP (0, 0, 0, 0, 0);
}

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    int t, l, r;
    sieve (100);
    //debug1(solve(151));
    //for (int i = 0; i < 100; i++) {
    //    debug2(i, isPrime[i]);
    //}
    cin >> t;

    while (t--) {
        cin >> l >> r; l--;
        debug2 (r, l);
        debug2 (solve (r), solve (l));
        //debug2 (solve (r), solve (l));
        cout << solve (r) - solve (l) << endl;
    }

    return 0;
}
