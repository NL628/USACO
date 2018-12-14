// COMPETITION: USACO
// NAME: 2018JanS2, Rental Service
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
#define vsort(v) sort(v.begin(), v.end())
#define asort(a, n) sort(a, a + n)
#define FOR(i, N) for (int i = 0; i < N; i++)
#define coutpair(cout, p) cout << p.f << " " << p.s << endl;
#define coutarr(cout, a, N) FOR(i, N) cout << a[i] << " "; cout << endl;
#define cinarr(cin, a, N) FOR(i, N) cin >> a[i];

const double PI = 4 * atan(1);
const int MOD = 1000000007;
const ll LINF = 1ll << 60;
const int INF = 1 << 30;

ofstream fout ("rental.out");
ifstream fin ("rental.in");

const int MX = 1e5 + 5;
ll N, M, R, c[MX], rent[MX];
pll store[MX];

bool cmp(pll a, pll b)
{
   if (a.s > b.s) return true;
   else if (a.s < b.s) return false;
   else return a.f > b.f;
}

void init()
{
   fin >> N >> M >> R;
   cinarr(fin, c, N);
   FOR(i, M)
      fin >> store[i].f >> store[i].s;
   cinarr(fin, rent, R);
   sort(c, c + N, greater<ll>());
   sort(store, store + M, cmp);
   sort(rent, rent + R, greater<ll>());
}

int main()
{
   init();
   vll sell(N, 0ll), milk(N, 0ll);
   for (int i = 0, j = 0; i < N && j < M; ) {
      if (c[i] < store[j].f) {
         sell[i] += c[i] * store[j].s;
         store[j].f -= c[i];
         i++;
      }
      else {
         sell[i] += store[j].f * store[j].s;
         c[i] -= store[j].f;
         j++;
      }
   }
   for (int i = 1; i < N; i++) {
      sell[i] += sell[i - 1];
   }
   for (int i = N - 1; i >= 0; i--) {
      if (N - 1 - i < R) {
         milk[i] = rent[N - 1 - i];
      }
   }
   for (int i = N - 2; i >= 0; i--) {
      milk[i] += milk[i + 1];
   }
   sell.insert(sell.begin(), 0ll);
   milk.pb(0ll);
   for (int i = 0; i < N; i++) {
      sell[i] += milk[i];
   }
   fout << *max_element(sell.begin(), sell.end()) << endl;
}
