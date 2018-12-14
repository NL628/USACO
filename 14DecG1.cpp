// COMPETITION: USACO
// NAME: 2014DecG1, Guard Mark
// DATE: December 1, 2018
// STATUS: Finished

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> pd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef map<int, int> mii;
typedef map<int, vi> mivi;
typedef priority_queue<int, vi, greater<int>> pqi;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define vall(v) v.begin(), v.end()
#define vsort(v) sort(vall(v))
#define asort(a, n) sort(a, a + n)
#define fori(i, N) for (int i = 0; i < N; i++)
#define coutpair(cout, p) cout << p.f << " " << p.s << endl;
#define coutarr(cout, a, N) FOR(i, N) cout << a[i] << " "; cout << endl;
#define cinarr(cin, a, N) FOR(i, N) cin >> a[i];

const double PI = 4 * atan (1);
const int MOD = 1000000007;
const ll LINF = 1ll << 60;
const int INF = 1 << 30;

ofstream fout ("guard.out");
ifstream fin ("guard.in");

struct Cow {
   // three values height, weight, strength
   int h, w, s;
   Cow (int a = 0, int b = 0, int c = 0)
   {
      h = a;
      w = b;
      s = c;
   }
};

// max values
const int MAXN = 20, MAXBIT = 1 << 20;

// input data
int N, H;

// values for each subset of cows
int height[MAXBIT];
int safety[MAXBIT];

// input data
Cow cows[MAXN];

int main()
{
   // read in data
   fin >> N >> H;
   for (int i = 0; i < N; i++) {
      fin >> cows[i].h >> cows[i].w >> cows[i].s;
   }

   // initialize arrays
   for (int i = 0; i < (1 << N); i++) {
      safety[i] = -INF;
   }
   safety[0] = INF;

   // answer to problem
   int max_safety = -1;

   // loop through every possible combination of cows
   // the binary representation of i: 10100 means cows 2 and 4
   for (int i = 0; i < (1 << N); i++) {

      // update answer is cow stack is tall enough
      if (height[i] >= H) {
         max_safety = max (max_safety, safety[i]);
      }

      // loop through every possible cow to add on TOP of stack
      for (int c = 0; c < N; c++) {

         // make sure cow is not in current subset a.k.a cth bit is off
         if (! (i & (1 << c))) {

            int nc = i + (1 << c); // new subset with cow c included
            height[nc] = height[i] + cows[c].h; // new height

            // safety: max of previous safety values and (new value = min of two cases)
            // 1: cow c is weak and its strength decreases overall safety
            // 2: cow c is strong and we need to decrease the safety of the stack due to cow c's weight
            safety[nc] = max (safety[nc], min (safety[i] - cows[c].w, cows[c].s));
         }
      }
   }

   // output answer
   if (max_safety < 0) {
      fout << "Mark is too tall" << endl;
   } else {
      fout << max_safety << endl;
   }
}
