// COMPETITION: USACO
// NAME: 2015JanS2, Cow Routing
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

ofstream fout("cowroute.out");
ifstream fin("cowroute.in");

int A, B, N;
ll adj[1005][1005];

int main()
{
   fin >> A >> B >> N;
   fill2d(adj, 1005, 1005, LINF);
   for (int i = 0; i < N; i++) {
      int c, x, y;
      fin >> c >> x;
      vi v;
      for (int j = 0; j < x; j++) {
         fin >> y;
         for (int k = 0; k < sz(v); k++)
            adj[v[k]][y] = min(adj[v[k]][y], c * 1000000ll + sz(v) - k);
         v.pb(y);
      }
   }
   queue<pair<ll, int>> pq;
   vll dist(1005, LINF);
   pq.push(mp(0ll, A));
   dist[A] = 0ll;
   while (!pq.empty()) {
      int u = pq.front().second;
      pq.pop();
      for (int v = 1; v <= 1000; v++)
         if (dist[v] > dist[u] + adj[u][v])
            pq.push(mp(dist[v] = dist[u] + adj[u][v], v));
   }
   if (dist[B] == LINF) fout << -1 << " " << -1 << endl;
   else fout << dist[B] / 1000000ll << " " << dist[B] % 1000000ll << endl;
}
