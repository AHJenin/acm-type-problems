/*
 * FILE: E.Sanvi_and_Brightest_Bulb.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04-11-17 23:40:00 (+06)
 * LAST MODIFIED: 04-11-17 23:48:48 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 04-11-17     1.0         {{File Created}}
 *
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
#include <queue>
#include <deque>
#include <vector>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

////////////////////////// START HERE //////////////////////////

//#define Max 10000005
int ST[100][MAX];
int Array[MAX];
void sparse_table(int N) {
    for (int i = 0; i < N; i++) ST[0][i] = i;

    for (int k = 1; (1 << k) < N; k++) {
        for (int i = 0; i + (1 << k) <= N; i++) {
            int x = ST[k - 1][i];
            int y = ST[k - 1][i + (1 << (k - 1))];
            ST[k][i] = Array[x] >= Array[y] ? x : y;
        }
    }
}

int RMQ(int i, int j) {
    int k = (int) log2(j - i);
    int x = ST[k][i];
    int y = ST[k][j - (1 << k) + 1];
    return Array[x] >= Array[y] ? x : y;
}

int main() {
    __FastIO;
    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        rep(i, n) cin >> Array[i];
        sparse_table(n);
        rep(i, n - 1) {
            cout << RMQ(i, n - 1) - i  << ' ';
        }
        cout << "0\n";
    }
    return 0;
}

