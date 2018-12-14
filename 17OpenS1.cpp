// COMPETITION: USACO
// NAME: 2017OpenS1 Paired Up
// DATE: November 30, 2018
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

const double PI = 4 * atan(1);
const int MOD = 1000000007;
const ll LINF = 1ll << 60;
const int INF = 1 << 30;

ofstream fout ("pairup.out");
ifstream fin ("pairup.in");

int N;
pi c[100005];
deque<pi> dq;

int main()
{
   fin >> N;
   fori(i, N) fin >> c[i].s >> c[i].f;
   sort(c, c + N);
   fori(i, N) dq.push_back(c[i]);
   int ans = 0;
   while (!dq.empty()) {
      ans = max(ans, dq.front().f + dq.back().f);
      if (dq.front().s > dq.back().s) {
         dq.front().s -= dq.back().s;
         dq.pop_back();
      }
      else if (dq.front().s < dq.back().s) {
         dq.back().s -= dq.front().s;
         dq.pop_front();
      }
      else {
         dq.pop_front();
         if (!dq.empty()) dq.pop_back();
      }

   }
   fout << ans << endl;
}
