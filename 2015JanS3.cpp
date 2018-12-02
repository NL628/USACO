// COMPETITION: USACO
// NAME: 2015JanS3, Meeting Time
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
typedef vector<vi> vvi;
typedef vector<pll> vpll;
typedef map<int, int> mii;
typedef map<int, vi> mivi;
typedef queue<int> qi;
typedef priority_queue<int, vi, greater<int>> pqi;
typedef priority_queue<pi, vpi, greater<pi>> pqpi;
typedef priority_queue<pll, vpll, greater<pll>> pqpll;

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
#define fill2d(a, N, M, v) fori(i, N) fori(j, M) a[i][j] = v;
#define coutpair(cout, p) cout << p.f << " " << p.s << endl;
#define coutarr(cout, a, N) FOR(i, N) cout << a[i] << " "; cout << endl;
#define cinarr(cin, a, N) FOR(i, N) cin >> a[i];

const double PI = 4 * atan(1);
const int MOD = 1000000007;
const ll LINF = 1ll << 60;
const int INF = 1 << 30;

ofstream fout("meeting.out");
ifstream fin("meeting.in");

int N, M;
vector<pair<int, pi>> adj[105];
bool dp[2][105][10105];

int main()
{
   fin >> N >> M;
   fori(i, M) {
      int A, B, C, D;
      fin >> A >> B >> C >> D;
      adj[A].pb(mp(B, mp(C, D)));
   }
   dp[0][1][0] = dp[1][1][0] = true;
   for (int i = 1; i <= N; i++) {
      for (pair<int, pi> p : adj[i]) {
         int j = p.first;
         pi wt = p.second;
         for (int t = 0; t <= 10000; t++) {
            if (dp[0][i][t]) dp[0][j][t + wt.f] = true;
            if (dp[1][i][t]) dp[1][j][t + wt.s] = true;
         }
      }
   }
   for (int i = 0; i <= 10000; i++)
      if (dp[0][N][i] && dp[1][N][i]) {
         fout << i << endl;
         return 0;
      }
   fout << "IMPOSSIBLE" << endl;
}
