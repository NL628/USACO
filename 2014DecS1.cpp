// COMPETITION: USACO
// NAME: 2014DecS1, Piggyback
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
typedef priority_queue<pi, vpi, greater<pi>> pqpi;

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

ofstream fout("piggyback.out");
ifstream fin("piggyback.in");

const int MX = 40005;
int B, E, P, N, M;
vi adj[MX], toB, toE, toBarn;

vi dijk(int src, int wt)
{
   pqpi pq;
   vi dist(N + 1, INF);
   pq.push(mp(0, src));
   dist[src] = 0;
   while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for (int v : adj[u])
         if (dist[v] > dist[u] + wt)
            pq.push(mp(dist[v] = dist[u] + wt, v));
   }
   return dist;
}

int main()
{
   fin >> B >> E >> P >> N >> M;
   fori(i, M) {
      int x, y;
      fin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   toB = dijk(1, B);
   toE = dijk(2, E);
   toBarn = dijk(N, P);
   int ans = INF;
   for (int i = 1; i <= N; i++)
      ans = min(ans, toB[i] + toE[i] + toBarn[i]);
   fout << ans << endl;
}
