/*
 * FILE: {{untitled}}
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: {{long_date}}
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * {{short_date}}     1.0         {{File Created}}
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

#define FileIn(file)    freopen("input.txt", "r", stdin)
#define FileOut(file)   freopen("output.txt", "w", stdout)
#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define sfll(a)         scanf("%lld", &a)
#define pfll(a)         printf("%lld", a)
#define sflf(a)         scanf("%lf", &a)
#define pflf(a)         printf("%lf", a)
#define sff(a)          scanf("%f", &a)
#define pff(a)          printf("%f", a)
#define sf(a)           scanf("%d", &a)
#define pf(a)           printf("%d", a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define eb              emplace_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

//////////////// BIT SET //////////////

// 2^n
#define bit(n)              (1 << (n))
// Check ith bit of integer n, 0 or 1
#define bitchk(n, i)        ((n & (1 << (i)))? 1 : 0)
//set ith bit ON of the integer n
#define bit_on(n, i)        n = (n | (1 << (i)))
//set ith bit OFF of the intger n
#define bit_off(n, i)       n = (n & ~(1 << (i)))
// Toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i)    n = (n ^ ( 1 << (i)))
// Set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i)   n = (n ^ ((-(x) ^ n) & (1 << (i))))

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAXN            32001
#define MAXS            100000000
#define MAX             10000005

////////////////////////////////////////////////////////////////
////////////////////////// START HERE //////////////////////////
////////////////////////////////////////////////////////////////


////////////////////////// BFS //////////////////////////

class BFS_DIJKSTRA {
    vector<int> adj [100]; // for BFS & bfs_vis
    int cost[100]; // for BFS & bfs_vis
    int visited [100]; //for bfs_vis

    int bfs(int s, int n) {
        int i, cn, v, sz;
        for (i = 0; i < n; i++)
            cost[i] = INT_MAX;

        queue<int> Q;
        Q.push(s);
        cost[s] = 0;
        while (!Q.empty()) {
            cn = Q.front();
            Q.pop();
            sz = (int) adj[cn].size();
            for (i = 0; i < sz; i++) {
                v = adj[cn][i];
                if (cost[cn] + 1 < cost[v]) {
                    Q.push(v);
                    cost[v] = cost[cn] + 1;
                }
            }
        }

        return 0;
    }


    void bfs_visited(int s, int n) {

        int u, v, i, m;
        for (i = 0; i < n; i++) {
            visited[i] = 0;
            cost[i] = -1;
        }

        queue<int> Q;
        Q.push(s);
        visited[s] = 1;
        cost[s] = 0;

        while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            m = (int) adj[u].size();

            for (i = 0; i < m; i++) {
                if (visited[adj[u][i]] == 0) {
                    v = adj[u][i];
                    visited[v] = 1;
                    Q.push(v);
                    cost[v] = cost[u] + 1;
                }
            }
        }
    }
////////////////////////// BFS END //////////////////////////


////////////////////////// DIJKSTRA //////////////////////////

//See /media/jenin/Softwares/Programming/UVa/Accepted/Sending_email-10986.cpp
//
//typedef pair<int, int> pii;
//typedef vector <pii> vpii;
//typedef vector <int> vi;
//graph declaration
//vector<vpii> graph (n, vpii());

    void dijkstra(int s, vi *dist, vector<vpii> *graph) {
        priority_queue< pii, vector<pii>, greater<pii> > pq;
        pq.push(pii(0, s));
        while (!pq.empty()) {
            pii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d == dist->at(u)) {
                for (int j = 0; j < (int) graph->at(u).size(); j++) {
                    pii v = graph->at(u)[j];                       // all outgoing edges from u
                    if (dist->at(u) + v.second < dist->at(v.first)) {
                        dist->at(v.first) = dist->at(u) + v.second;  // relax operation
                        pq.push(pii(dist->at(v.first), v.first));
                    }
                }
            }
        }
    }

////////////////////////// DIJKSTRA END //////////////////////////

};

////////////////////////// MST //////////////////////////
class MST {
    int parent[26];

    void Make_Set(int x) {
        parent[x] = x;
    }

    int Find(int x) {
        if (x != parent[x]) parent[x] = Find(parent[x]);
        return parent[x];
    }

    void Union(int &x, int &y) {
        int PX = Find(x), PY = Find(y);
        parent[PX] = PY;
    }
    // example
    // if (Find(x) != Find(y)){
    //     Union(x, y);
    // }
};
////////////////////////// MST END //////////////////////////


////////////////////////// DFS //////////////////////////

class DFS {
    vector<int> adj [100]; // for BFS & bfs_vis
    int finish[100], discover[100], color[100], time_cnt = 0;
//discovery time and finishing time for DFS

    void dfs(int u) {
        int i, v, sz;
        time_cnt++;
        discover[u] = time_cnt;
        color[u] = 1;   ///Gray = visiting = 1, black = visited = 2;
        sz = (int) adj[u].size();
        for (i = 0; i < sz; i++) {
            v = adj[u][i];
            if (color[v] == 0) {
                dfs(v);
            }
        }

        color[u] = 2;
        time_cnt++;
        finish[u] = time_cnt;
    }
};
////////////////////////// DFS END //////////////////////////



////////////////////////// SIEVE //////////////////////////
class Primes {
    bool isPrime[MAXS]; //for sieve
    int prime[MAXS]; //for sieve

public:
    bool isprime(int num) {
        if (num < 2 or num % 2 == 0) return false;
        if (num == 2) return true;

        int i, root = (int) sqrt(num);

        for (i = 3; i <= root; i += 2)
            if (num % i == 0)    return false;

        return true;
    }

    int sieve(int n) {

        int i, res, j;
        double root = sqrt(n);
        isPrime[0] = isPrime[1] = 1;

        for (i = 4; i < n; i += 2)
            isPrime[i] = 1;

        for (i = 3, j = 0; i <= root; i += 2) {
            if (!isPrime[i]) {
                for (j = i * i; j < n; j += 2 * i)
                    isPrime[j] = 1;
            }
        }

        for (i = 0, res = 0; i < n; i++) {
            if (isPrime[i] == 0) {
                prime[res++] = i;
            }
        }

        return (res - 1);

    }


// bitwise seive
//int isPrime[MAXS/32]; //for sieve
//int prime[MAXS]; //for sieve

    int bit_sieve(int n) {

        int i, res, j;
        double root = sqrt(n);
        bit_on(isPrime[0], 0);
        bit_on(isPrime[0], 1);

        for (i = 4; i < n; i += 2)
            bit_on(isPrime[i >> 5], i & 31);

        for (i = 3, j = 0; i <= root; i += 2) {
            if (bitchk(isPrime[i >> 5], i & 31) == 0) {
                for (j = i * i; j < n; j += 2 * i)
                    bit_on(isPrime[j >> 5], j & 31);
            }
        }

        for (i = 0, res = 0; i < n; i++) {
            if (bitchk(isPrime[i >> 5], i & 31) == 0) {
                prime[res++] = i;
            }
        }

        return (res - 1);
    }

// Segmented Sieve of Eratosthenes

    int segsieve[100000];

///Returns number of primes between segment [a,b]
    int segmentedSieve ( int a, int b, int primesize) {
        if ( a == 1 ) a++;

        int sqrtn = (int) sqrt (b);

        memset ( segsieve, 0, sizeof segsieve ); ///Make all index of segsieve 0.
        // maxprime is used in bit sieve or normal seive code
        for ( int i = 0; i < primesize && prime[i] <= sqrtn; i++ ) {
            int p = prime[i];
            int j = p * p;

            ///If j is smaller than a, then shift it inside of segment [a,b]
            if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

            for ( ; j <= b; j += p ) {
                segsieve[j - a] = 1; ///mark them as not prime
            }
        }

        int res = 0;
        for ( int i = a; i <= b; i++ ) {
            ///If it is not marked, then it is a prime
            if ( segsieve[i - a] == 0 ) res++;
        }
        return res;
    }
};
////////////////////////// SIEVE END //////////////////////////


////////////////////////// PRIME FACTOR //////////////////////////
class Prime_fact {
    int fact[100][2]; //for prime factor
    int isPrime[MAX], prime[MAX];  // Primes class
//100 will be replaced with max number of factors

public:
    int primefactor(long long n, int primesize) {
        // res is return value of seive
        int i, j;

        if (n == 0 || isPrime[n] == 0)
            return 0;

        for (i = 0, j = 0; i < primesize; i++) {
            if (n % prime[i] == 0) {
                fact[j][0] = prime[i];
                fact[j][1] = 0;
                while (n % prime[i] == 0) {
                    n /= prime[i];
                    fact[j][1]++;
                }
                j++;
            }
        }

        return j;
    }
};

////////////////////////// EULER'S TOTIENT FUNCTION ////////////////////////

class Totient {

public:
    // phi[i] stores euler totient function for i
    // gcdsum[j] stores result for value j
    int phi[MAX];
    int gcdsum[MAX];

/// Computes and prints totien of all numbers
/// smaller than or equal to n.
/// http://www.geeksforgeeks.org/
/// eulers-totient-function-for-all-numbers-smaller-than-or-equal-to-n/
    void compute(int n) {
        // Create and initialize an array to store
        // phi or totient values
        //long long phi[n + 1];
        for (int i = 1; i <= n; i++)
            phi[i] = i; // indicates not evaluated yet
        // and initializes for product
        // formula.

        // Compute other Phi values
        for (int p = 2; p <= n; p++) {
            //If phi[p] is not computed already,
            //then number p is prime

            if (phi[p] == p) {
                // Phi of a prime number p is
                // always equal to p-1.
                phi[p] = p - 1;

                // update phi values of all
                // multiples of p
                for (int i = 2 * p; i <= n; i += p) {
                    // Add contribution of p to its
                    // multiple i by multiplying with
                    // (1 - 1/p)
                    phi[i] = (phi[i] / p) * (p - 1);
                }
            }
        }
    }

//Precomputes result for all numbers till MAX
    void sumOfGcdPairs(int n) {
        // Precompute all phi value
        compute(n);

        //gcdsum[0] = 0;
        for (int i = 1; i < n; ++i) {
            // Iterate throght all the divisors
            // of i.
            for (int j = 2; i * j < n; ++j)
                gcdsum[i * j] += i * phi[j];
        }

        // Add summation of previous calculated sum
        for (int i = 2; i < n; i++)
            gcdsum[i] += gcdsum[i - 1];
    }

// http://www.geeksforgeeks.org/eulers-totient-function/
    int phi_single(int n) {
        int res = n;   // Initialize result as n

        // Consider all prime factors of n and subtract their
        // multiples from result
        for (int p = 2; p * p <= n; ++p) {
            // Check if p is a prime factor.
            if (n % p == 0) {
                // If yes, then update n and result
                while (n % p == 0)
                    n /= p;
                res -= res / p;
            }
        }

        // If n has a prime factor greater than sqrt(n)
        // (There can be at-most one such prime factor)
        if (n > 1)
            res -= res / n;
        return res;
    }
};

////////////////////////// EULER'S TOTIENT FUNCTION ////////////////////////


////////////////////////////// MOBIOUS FUNCTION ////////////////////////////

class Mobious {

    int mu[MAX];

    void func(int n) {
        int fact[100][2]; //for prime factor, declared in Prime_fact class
        Primes primes;
        Prime_fact prime_fact;
        int num_of_unique_factors, fl;
        int primesz = primes.sieve(MAXS);
        for (int i = 1; i <= n; i++) {
            num_of_unique_factors = prime_fact.primefactor(i, primesz);
            fl = 2;
            for (int j = 0; j < num_of_unique_factors; j++) {
                if (fact[j][1] > 1) {
                    fl = 0;
                    break;
                }
            }
            if (fl == 0) mu[i] = 0;
            else {
                if (num_of_unique_factors & 1)
                    mu[i] = -1;
                else mu[i] = 1;
            }
        }
    }
};

////////////////////////////// MOBIOUS FUNCTION ////////////////////////////

void swap(int *x, int *y) {
    // Code to swap 'x' and 'y'
    *x = *x * *y; // x now becomes 15
    *y = *x / *y; // y becomes 10
    *x = *x / *y; // x becomes 5
}


long double fibbonacci(long double f) {
    return (pow(((1 + sqrt(5)) / 2), f) - pow(((1 - sqrt(5)) / 2), f)) / sqrt(5);
}


int gcd(int a, int b)  {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


// http://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


int lcm2(int a, int b) {
    int temp = a;
    while (1) {
        if (temp % b == 0 && temp % a == 0) break;
        temp++;
    }
    return temp;
}


char *strrev(char *str) { //Used by big_int_sum & big_int_mul
    char *p1, *p2;
    if (! str || ! *str) return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

////////////////////////// BIG NUMBER //////////////////////////
class Big_num {
    int sum_s(int a, int b, int c) { //Used by big_int_sum & big_int_mul
        if (a + b + c > 9) return (a + b + c) % 10;
        return a + b + c;
    }
    int sum_c(int a, int b, int c) { //Used by big_int_sum & big_int_mul
        if (a + b + c > 9) return (a + b + c) / 10;
        return 0;
    }
    int mul_s(int a, int b, int c) { //Used by big_int_mul
        if (a * b + c > 9) return (a * b + c) % 10;
        return a * b + c;
    }
    int mul_c(int a, int b, int c) { //Used by big_int_mul
        if (a * b + c > 9) return (a * b + c) / 10;
        return 0;
    }

    void big_int_sum(char *a, char *b, char *c) {   // a + b = c

        int len_a, len_b, i, j, k, carry;
        len_a = (int) strlen(a);
        len_b = (int) strlen(b);

        carry = 0;
        k = 0, i = len_a - 1, j = len_b - 1;
        for (; i >= 0 && j >= 0; j--, i--, k++) {
            c[k] = (char) (sum_s(a[i] - 48, b[j] - 48, carry) + 48);
            carry = sum_c(a[i] - 48, b[j] - 48, carry);
        }

        if (i >= 0 && i != j)
            for (; i >= 0; i--, k++) {
                c[k] = (char) (sum_s(a[i] - 48, 0, carry) + 48);
                carry = sum_c(a[i] - 48, 0, carry);
            }

        else if (j >= 0 && i != j)
            for (; j >= 0; j--, k++) {
                c[k] = (char) (sum_s(0, b[j] - 48, carry) + 48);
                carry = sum_c(0, b[j] - 48, carry);
            }


        if (carry != 0) c[k++] = (char) (carry + 48);
        c[k] = '\0';
        strrev(c);

    }



    void big_int_mul(char *x, char *y, char *t) {

        int i, j, k, C, r, xi, yi, Cs, m;
        C = 0, Cs = 0;

        for (i = 0;; i++) if (x[i] == '\0') break;
        xi = i - 1;

        for (i = 0;; i++) if (y[i] == '\0') break;
        yi = i - 1;

        for (i = 0; i < 502; i++) t[i] = '0';

        for (j = 0; yi >= 0; yi--, j++) {
            for (i = 0, k = xi; k >= 0; k--, i++) {
                r = mul_s(x[k] - 48, y[yi] - 48, C);
                C = mul_c(x[k] - 48, y[yi] - 48, C);
                m = t[i + j];
                t[i + j] = (char) (sum_s(r, m - 48, Cs) + 48);
                Cs = sum_c(r, m - 48, Cs);
            }

            t[i + j] = (char) (C + Cs + 48);
            C = 0;
            Cs = 0;
        }

        for (k = i + j; k > 0; k--) {
            if (t[k] != 48) {
                t[k + 1] = 0;
                break;
            }
        }

        t[k + 1] = 0;
        strrev(t);
    }



    unsigned long long big_int_div(char *a, unsigned long long b, char *c) {

        int la;
        int i, k = 0, flag = 0;
        unsigned long long temp = 1, reminder;
        la = (int) strlen(a);

        for (i = 0; i <= la; i++) a[i] = (char) (a[i] - 48);

        temp = a[0];
        reminder = a[0];
        for (i = 1; i <= la; i++) {
            if (b <= temp) {
                c[k++] = (char) (temp / b);
                temp = temp % b;
                reminder = temp;
                temp = temp * 10 + a[i];
                flag = 1;
            } else {
                reminder = temp;
                temp = temp * 10 + a[i];
                if (flag == 1) c[k++] = 0;
            }
        }

        for (i = 0; i < k; i++) {
            c[i] = (char) (c[i] + '0');
        }
        c[i] = '\0';
        if (i == 0) {
            c[i] = '0';
            c[1] = '\0';
        }
        return reminder;
    }
};
////////////////////////// BIG NUMBER END //////////////////////////

bool isleapyear(long int year) {
    /*Is year divided by 4? After every 100 years a leap year is not
    counted and after every 400 years we count leap year*/
    if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))
        return true;
    else return false;
}


int big_mod(int base, int power, int mod) {

    if (power == 0)    return 1;
    else if (power % 2 == 1) {
        int p1 = base % mod;
        int p2 = (big_mod(base, power - 1, mod)) % mod;
        return (p1 * p2) % mod;
    } else if (power % 2 == 0) {
        int p1 = (big_mod(base, power / 2, mod)) % mod;
        return (p1 * p1) % mod;
    }
    return 0;
}


int binarysearch (int *array, int end, int key) {
    //array must be sorted, if key is found return 0 based index,
    //else -1;
    int start = 0, mid;
    end--;
    while (start <= end) {
        mid = (start + end) / 2;
        if (key == array[mid]) return mid;
        else if (key < array[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

///////////////////////////// SORTING ////////////////////////////

class Sorting {
    void bubble_sort(int *list, int n) {
        int c, d, t;
        for (c = 0 ; c < ( n - 1 ); c++) {
            for (d = 0 ; d < n - c - 1; d++) {
                if (list[d] > list[d + 1]) {
                    /* Swapping */
                    t         = list[d];
                    list[d]   = list[d + 1];
                    list[d + 1] = t;
                }
            }
        }
    }


    void insertion_sort(int *array, int n) {
        int t, d, c;
        for (c = 1 ; c <= n - 1; c++) {
            d = c;

            while ( d > 0 && array[d] < array[d - 1]) {
                t          = array[d];
                array[d]   = array[d - 1];
                array[d - 1] = t;

                d--;
            }
        }
    }


    // Merge sort
    void merge(int *a, int low, int high, int mid) { //used by merge_sort

        int i, j, k, c[50];
        i = low;
        k = low;
        j = mid + 1;

        while (i <= mid && j <= high) {
            if (a[i] < a[j]) {
                c[k] = a[i];
                k++;
                i++;
            } else {
                c[k] = a[j];
                k++;
                j++;
            }
        }

        while (i <= mid) {
            c[k] = a[i];
            k++;
            i++;
        }
        while (j <= high) {
            c[k] = a[j];
            k++;
            j++;
        }
        for (i = low; i < k; i++) a[i] = c[i];
    }

    void merge_sort(int *a, int low, int high) { //low and high inclusive

        int mid;
        if (low < high) {
            mid = (low + high) / 2;
            merge_sort(a, low, mid);
            merge_sort(a, mid + 1, high);
            merge(a, low, high, mid);
        }
        return;
    }


    void quick_sort(int *array, int start, int end) {
        //start and end inclusive
        int low = start, high = start, i;
        if (start < end) {
            for (i = start; i < end; i++) {
                if (array[i] < array[end]) {
                    swap(array[i], array[low]);
                    low++;
                    high++;
                } else high++;
            }
            swap(array[end], array[low]);
            quick_sort(array, start, low - 1);
            quick_sort(array, low + 1, high);
        } else return;
    }


    // Heap sort start
// How to use
// First call Build_MaxHeap(n), where n in size of array arr
//      Build_MaxHeap(n);
// then call HeapSort(n);
//      HeapSort(n);

    int arr[100];
    void MakeHeap(int i, int n) {

        int j, temp;
        temp = arr[i];
        j = 2 * i;

        while (j <= n) {
            if (j < n && arr[j + 1] > arr[j]) {
                j++;
            }

            if (temp > arr[j])
                break;

            else if (temp <= arr[j]) {
                arr[j / 2] = arr[j];
                j = 2 * j;
            }
        }

        arr[j / 2] = temp;
    }

    void HeapSort(int n) {

        int i, temp;
        for (i = n; i >= 2; i--) {
            temp = arr[i];
            arr[i] = arr[1];
            arr[1] = temp;
            MakeHeap(1, i - 1);
        }
    }

    void Build_MaxHeap(int n) {

        int i;
        for (i = n / 2; i >= 1; i--) {
            MakeHeap(i, n);
        }
    }
    // Heap sort end
};
///////////////////////////// SORTING ////////////////////////////

//////////// MOST SIGNIFICANT DIGIT ////////////

//Return most significant digit
uint32_t powers_of_10[33] = {
    1000000000, 1000000000,
    100000000, 100000000, 100000000,
    10000000, 10000000, 10000000,
    1000000, 1000000, 1000000, 1000000,
    100000, 100000, 100000,
    10000, 10000, 10000,
    1000, 1000, 1000, 1000,
    100, 100, 100,
    10, 10, 10,
    1, 1, 1, 1, 1
};

int CalcFirstDecimalDigit(uint32_t x) {
    int leading_zeros = __builtin_clz(x);
    x /= powers_of_10[leading_zeros];
    if (x >= 10)
        return 1;
    else
        return x;
}

//////////// MOST SIGNIFICANT DIGIT END ////////////


////////////////////////// SPARSE TABLE //////////////////////////

class Sparse_table {
//#define Max 10000005
    int ST[24][MAX];
    int Array[MAX];
public:
    Sparse_table(int N) {
        for (int i = 0; i < N; i++) ST[0][i] = i;

        for (int k = 1; (1 << k) < N; k++) {
            for (int i = 0; i + (1 << k) <= N; i++) {
                int x = ST[k - 1][i];
                int y = ST[k - 1][i + (1 << (k - 1))];
                ST[k][i] = Array[x] <= Array[y] ? x : y;
            }
        }
    }

    int RMQ(int i, int j) {
        // return min value index number of Array from i to j, including
        //if(i == j) return i;
        int k = (int) log2(j - i);
        int x = ST[k][i];
        int y = ST[k][j - (1 << k) + 1];
        return Array[x] <= Array[y] ? x : y;
    }
};
////////////////////////// SPARSE TABLE END //////////////////////////


////////////////////////// INIX TO POSTFIX //////////////////////////

//deque: Every element of the equation is separate string in the deque

vector<string> infix_to_postfix(deque<string> v) {

    vector<string> P;
    stack<string> Stk;
    v.push_front("(");
    v.push_back(")");

    for (int i = 0 ; i < (int)v.size() ; i++) {
        string tmp = v[i];
        /// Case 1 : number
        if (tmp[0] >= '0' && tmp[0] <= '9') {
            P.push_back(tmp);
        }
        /// Operator
        else if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
            if (tmp == "+" || tmp == "-") {
                while (!Stk.empty() && (Stk.top() == "+" || Stk.top() == "-"
                                        || Stk.top() == "*" || Stk.top() == "/" )) {
                    P.push_back(Stk.top());
                    Stk.pop();
                }
            } else if (tmp == "*" || tmp == "/" ) {
                while (!Stk.empty() && \
                        ( Stk.top() == "*" || Stk.top() == "/")) {
                    P.push_back(Stk.top());
                    Stk.pop();
                }
            }
            Stk.push(tmp);
        } else {
            if (tmp == "(") Stk.push(tmp);
            else {
                while (Stk.top() != "(") {
                    P.push_back(Stk.top());
                    Stk.pop();
                }
                if (!Stk.empty()) Stk.pop();
            }
        }
    }

    return P;
}

////////////////////////// INIX TO POSTFIX //////////////////////////



////////////////////////// IS SUBSECUENCE //////////////////////////

class Subsecuence {
// Returns true if str1[] is a subsequence of str2[]. m is
// length of str1 and n is length of str2
    bool isSubSequence(char str1[], char str2[], int m, int n) {
        // Base Cases
        if (m == 0) return true;
        if (n == 0) return false;

        // If last characters of two strings are matching
        if (str1[m - 1] == str2[n - 1])
            return isSubSequence(str1, str2, m - 1, n - 1);

        // If last characters are not matching
        return isSubSequence(str1, str2, m, n - 1);
    }


// Returns true if str1[] is a subsequence of str2[]. m is
// length of str1 and n is length of str2
    bool isSubSequence_it(char str1[], char str2[], int m, int n) {
        int j = 0; // For index of str1 (or subsequence

        // Traverse str2 and str1, and compare current character
        // of str2 with first unmatched char of str1, if matched
        // then move ahead in str1
        for (int i = 0; i < n && j < m; i++)
            if (str1[j] == str2[i])
                j++;

        // If all characters of str1 were found in str2
        return (j == m);
    }

////////////////////////// IS SUBSECUENCE //////////////////////////



////////////////////////// LCS //////////////////////////

    int dp[1010][1010];
    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    int lcs( char *X, char *Y, int m, int n ) {
        if (m == 0 || n == 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1);
        else
            return dp[m][n] = max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
    }


    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    int lcs_it( char *X, char *Y, int m, int n ) {
        int i, j;

        // Following steps build L[m+1][n+1] in bottom up fashion. Note
        // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        /* dp[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
        return dp[m][n];
    }


// LCS PRINT

    void lcs_print( char *X, char *Y, int m, int n ) {
        //int dp[m + 1][n + 1]; // needed, declare before

        // Following steps build L[m+1][n+1] in bottom up fashion. Note
        // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Following code is used to print LCS
        int index = dp[m][n];

        // Create a character array to store the lcs string
        char lcs[index + 1];
        lcs[index] = '\0'; // Set the terminating character

        // Start from the right-most-bottom-most corner and
        // one by one store characters in lcs[]
        int i = m, j = n;
        while (i > 0 && j > 0) {
            // If current character in X[] and Y are same, then
            // current character is part of LCS
            if (X[i - 1] == Y[j - 1]) {
                // Put current character in result
                lcs[index - 1] = X[i - 1];
                // reduce values of i, j and index
                i--; j--; index--;
            }

            // If not same, then find the larger of two and
            // go in the direction of larger value
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }

        // Print the lcs
        cout << "LCS of " << X << " and " << Y << " is " << lcs;
    }

////////////////////////// LCS END //////////////////////////


////////////////////////// LPS //////////////////////////

//int dp[1005][1005];
// Returns the length of the longest palindromic subsequence in seq
    int lps(string seq, int i, int j) {
        // Base Case 1: If there is only 1 character
        if (i == j)
            return 1;

        // Base Case 2: If there are only 2 characters and both are same
        if (seq[i] == seq[j] && i + 1 == j)
            return 2;

        if (dp[i][j] != -1) return dp[i][j];

        // If the first and last characters match
        if (seq[i] == seq[j])
            return dp[i][j] = lps(seq, i + 1, j - 1) + 2;

        // If the first and last characters do not match
        return dp[i][j] = max(lps(seq, i, j - 1), lps(seq, i + 1, j) );
    }


// Returns the length of the longest palindromic subsequence in seq
    int lps_it(string str) {
        short DP[1001][1001];
        memset(DP, 0, sizeof(DP));
        int len = (int) str.length(), i, j;
        for (i = 0; i < len; i++) {
            for (j = 0; j + i < len; j++) {
                if (str[j] == str[i + j]) {
                    DP[j][j + i] = (short) (DP[j + 1][j + i - 1] +  (i == 0 ? 1 : 2));
                } else {
                    DP[j][j + i] = max(DP[j + 1][j + i], DP[j][j + i - 1]);
                }
            }
        }

        return DP[0][len - 1];
    }


// Function return the total palindromic subsequence
    int countPS(string str) {
        int N = (int) str.length();

        // create a 2D array to store the count of palindromic
        // subsequence
        int cps[N + 1][N + 1];
        memset(cps, 0, sizeof(cps));

        // palindromic subsequence of length 1
        for (int i = 0; i < N; i++)
            cps[i][i] = 1;

        // check subsequence of length L is palindrome or not
        for (int L = 2; L <= N; L++) {
            for (int i = 0; i < N; i++) {
                int k = L + i - 1;
                if (str[i] == str[k])
                    cps[i][k] = cps[i][k - 1] + cps[i + 1][k] + 1;
                else
                    cps[i][k] = cps[i][k - 1] + cps[i + 1][k] - cps[i + 1][k - 1];
            }
        }

        // return total palindromic subsequence
        return cps[0][N - 1];
    }

////////////////////////// LPS END //////////////////////////



////////////////////////// LIS //////////////////////////

// Binary search (note boundaries in the caller)
    int CeilIndex(std::vector<int> &v, int l, int r, int key) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (v[m] >= key)
                r = m;
            else
                l = m;
        }

        return r;
    }

    int LongestIncreasingSubsequenceLength(vector<int> &v) {
        if (v.size() == 0)
            return 0;

        std::vector<int> tail(v.size(), 0);
        int length = 1; // always points empty slot in tail

        tail[0] = v[0];
        for (size_t i = 1; i < v.size(); i++) {
            if (v[i] < tail[0])
                // new smallest value
                tail[0] = v[i];
            else if (v[i] > tail[length - 1])
                // v[i] extends largest subsequence
                tail[length++] = v[i];
            else
                // v[i] will become end candidate of an existing subsequence or
                // Throw away larger elements in all LIS, to make room for
                // upcoming grater elements than v[i].
                // (and also, v[i] would have already appeared in one of LIS,
                // identify the location and replace it)
                tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }

        return length;
    }

////////////////////////// LIS END //////////////////////////
};

////////////////////////// KADANE'S ALGO IN 1D //////////////////////////

// Implementation of Kadane's algorithm for 1D array. The function
// returns the maximum sum and stores starting and ending indexes of the
// maximum sum subarray at addresses pointed by start and finish pointers
// respectively.
int kadane(int *arr, int *start, int *finish, int n) {
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

////////////////////////// KADANE'S ALGO IN 1D END //////////////////////////


////////////////////////// KADANE'S ALGO IN 2D //////////////////////////

// The main function that finds maximum sum rectangle in M[][]
// use Kadane's algo in 1D, descripted avobe
int MAT[101][101];
int findMaxSum2D(int *finalTop, int *finalLeft, int *finalBottom,
                 int *finalRight, int ROW, int COL) {
    // Variables to store the final output
    int maxSum = INT_MIN;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < COL; ++left) {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < COL; ++right) {
            // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += MAT[i][right];

            // Find the maximum sum subarray in temp[]. The kadane()
            // function also sets values of start and finish.  So 'sum' is
            // sum of rectangle between (start, left) and (finish, right)
            //  which is the maximum sum with boundary columns strictly as
            //  left and right.
            sum = kadane(temp, &start, &finish, ROW);

            // Compare sum with maximum sum so far. If sum is more, then
            // update maxSum and other output values
            if (sum > maxSum) {
                maxSum = sum;
                *finalLeft = left;
                *finalRight = right;
                *finalTop = start;
                *finalBottom = finish;
            }
        }
    }

    return maxSum;
}

////////////////////////// KADANE'S ALGO IN 2D END //////////////////////////


////////////////////////// INTEGER TO ROMAN NUMERAL //////////////////////////

/*
 * http://rosettacode.org/wiki/Roman_numerals/Encode#C.2B.2B
 *
 * Create a function taking a positive integer as its parameter and returning a
 * string containing the Roman numeral representation of that integer. Modern
 * Roman numerals are written by expressing each digit separately, starting
 * with the left most digit and skipping any digit with a value of zero.
 */

string to_roman(int value) {
    struct romandata_t {
        int value;
        char const *numeral;
    };
    static romandata_t const romandata[] = {
        1000, "M",
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
        90, "XC",
        50, "L",
        40, "XL",
        10, "X",
        9, "IX",
        5, "V",
        4, "IV",
        1, "I",
        0, NULL
    }; // end marker

    string result;
    for (romandata_t const *current = romandata; current->value > 0; ++current) {
        while (value >= current->value) {
            result += current->numeral;
            value  -= current->value;
        }
    }
    return result;
}

//////////////////////// INTEGER TO ROMAN NUMERAL END /////////////////////////


////////////////////////// SLIDING WINDOW //////////////////////////
// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k) {
    // k must be greater
    if (n < k)
        return -1;

    // Compute sum of first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}
////////////////////////// SLIDING WINDOW END //////////////////////////

/////////////////// Maximum of all subarrays of size k ///////////////////
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
vector<int> maxofallKsubarray(int arr[], int n, int k) {
    // Create a Double Ended Queue, Qi that will store indexes of array
    // elements.. The queue will store indexes of useful elements in every
    // window and it will maintain decreasing order of values from front to
    // rear in Qi, i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in
    // decreasing order
    vector<int> v;
    std::deque<int>  Qi(k);

    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i) {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();  // Remove from rear

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i) {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        v.push_back(arr[Qi.front()]);

        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue

        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        // Add current element at the rear of Qi
        Qi.push_back(i);
    }

    // Print the maximum element of last window
    v.push_back(arr[Qi.front()]);
    return v;
}

/////////////////// Maximum of all subarrays of size k ///////////////////

/////////////////// Minimum of all subarrays of size k ///////////////////
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
vector<int> minofallKsubarray(int arr[], int n, int k) {
    // Create a Double Ended Queue, Qi that will store indexes of array
    // elements The queue will store indexes of useful elements in every window
    // and it will maintain decreasing order of values from front to rear in
    // Qi, i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing
    // order
    vector<int> v;
    std::deque<int>  Qi(k);

    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i) {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && arr[i] <= arr[Qi.back()])
            Qi.pop_back();  // Remove from rear

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i) {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        v.push_back(arr[Qi.front()]);

        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue

        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] <= arr[Qi.back()])
            Qi.pop_back();

        // Add current element at the rear of Qi
        Qi.push_back(i);
    }

    // Print the maximum element of last window
    v.push_back(arr[Qi.front()]);
    return v;
}
/////////////////// Minimum of all subarrays of size k ///////////////////

//////////////////////////////// FACTORIAL ///////////////////////////////
long long factorial(int n) {
    if (n == 0) return 1;
    else return (n * factorial(n - 1));
}

// // C++ program to find last non-zero digit in n!
// http://www.geeksforgeeks.org/last-non-zero-digit-factorial/
// Initialize values of last non-zero digit of
// numbers from 0 to 9
int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit(int n) {
    if (n < 10)
        return dig[n];

    // Check whether tens (or second last) digit
    // is odd or even
    // If n = 375, So n/10 = 37 and (n/10)%10 = 7
    // Applying formula for even and odd cases.
    if (((n / 10) % 10) % 2 == 0)
        return (6 * lastNon0Digit(n / 5) * dig[n % 10]) % 10;
    else
        return (4 * lastNon0Digit(n / 5) * dig[n % 10]) % 10;
}

// Function to return trailing 0s in factorial of n
// http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
int findTrailingZeros(int  n) {
    // Initialize result
    int count = 0;

    // Keep dividing n by powers of 5 and update count
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}

//////////////////////////////// FACTORIAL ///////////////////////////////


//////////////////////////////// PARSING //////////////////////////////

// for single character delimiter
vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

// for string delimiter
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

//////////////////////////////// PARSING //////////////////////////////

/////////////////////////// STRING MATHCING ///////////////////////////
// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else { // (pat[i] != pat[len])
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            } else { // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt) {
    int M = (int) strlen(pat);
    int N = (int) strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d \n", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

/////////////////////////// STRING MATHCING ///////////////////////////


int main() {
    __FastIO;
    cout << "Hello World!\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////


/*********************************************************************
__________________________BUILT_IN FUNCTIONS__________________________


----------------------------------------------------------------------
int sprintf(char *restrict buffer, const char *restrictformat, ...);
This function convert number to string with specified format.
Example:
int aInt = 368;
char str[15];
sprintf(str, "%d", aInt);
cout << str << endl;

int sscanf(const char *str, const char *format, ...)
sscanf (sentence,"%s %*s %d",str,&i);
On success, the function returns the number of items in the argument
list successfully filled. This count can match the expected number of
items or be less (even zero) in the case of a matching failure.
In the case of an input failure before any data could be successfully
interpreted, EOF is returned.
Defined in header <stdio.h>


----------------------------------------------------------------------
std::cin.getline();
getline can be provided a third argument--a "stop" character. This
character ends getline's input. The character is eaten and the
string is terminated. Example: std::cin.getline(str, 100, '|')
If std::cin.getline() is not provided a "stop" character as a third
argument, it will stop when it reaches a newline.
Example: std::cin.getline(str, 100)


----------------------------------------------------------------------
std::cin.ignore()
can be called three different ways:
1. No arguments: A single character is taken from the input buffer
and discarded:
std::cin.ignore(); //discard 1 character
2. One argument: The number of characters specified are taken from
the input buffer and discarded:
std::cin.ignore(33); //discard 33 characters
3. Two arguments: discard the number of characters specified, or
discard characters up to and including the specified delimiter
(whichever comes first):
std::cin.ignore(26, '\n');
//ignore 26 characters or to a newline, whichever comes first



----------------------------------------------------------------------
Formated I/O
Example: std::cout << std::right << setw(5) << 123 << endl;
//output:"  123"
std::cout.fill('X');
std::cout << setw(2) << one << std::endl.;
//output: "X4"
#include <iomanip>

----------------------------------------------------------------------
Input and output in C++ is type safe and easy for common formats
using cin and cout. The following program listing shows some common
uses:

#include <iostream.h>
#include <iomanip.h>

int main()
{
    int n;
    float f;
    double d;
    char s[100];

    // input an integer
    cin >> n;
    // print an integer, no formatting
    cout << n << endl;
    // print an integer, padded on left with spaces to total 6 chars
    cout << setw(6) << n << endl;
    // print an integer, padded on right with spaces to total 6 chars
    cout << setw(-6) << n << endl;

    // input a string (whitespace delineated)
    cin >> s;
    // print a string, no formatting
    cout << s << endl;
    // print a string, padded with spaces on left to 20 chars
    cout << setw(20) << s << endl;
    // print a string, padded with spaces on right to 20 chars
    cout << setiosflags(ios::left) << setw(20) << s << endl;

    // input a single precision floating point number
    cin >> f;
    // print a float, default precision is 6 places
    cout << setiosflags(ios::fixed) << f << endl;
    // input a double precision floating point number
    cin >> d;
    // print a double, default precision is 6 places
    cout << d << endl;
    // print a double, 2 places of precision
    cout << setprecision(2) << d << endl;
    // print a double, 2 places of precision, padded with space to 10
    cout << setw(10) << setprecision(2) << d << endl;
}

Rember that you can combine C routine sprintf and C++ cout. For
example, if sprintf can give the desired formatting, use it to create
the desired string, then output using C++ I/O. It is probably not a
good idea to mix C and C++ input and output routines since they are
buffered routines and may produce undesirable re-ordering of
input/output.


----------------------------------------------------------------------
strcpy(char* des, char* src) //Copies src into des.


----------------------------------------------------------------------
double a = 18.12385;
cout << fixed << setprecision(3);
cout << a << endl;
//output: 18.124
#include <iomanip>
std::fixed, std::setprecision()


----------------------------------------------------------------------
next_permutation(str, str+strlen(str));
return non-zero if next permutation found, otherwise 0
    char str[] = "arafat";
    if(next_permutation(str, str+strlen(str)))
        cout << str << endl;
//output: arafta
#include <algorithm>



 ********************************************************************/
