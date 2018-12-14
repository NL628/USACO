// COMPETITION: USACO
// NAME: 2017OpenS2 Paired Up
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

ofstream fout ("cownomics.out");
ifstream fin ("cownomics.in");

int N, M;
int g[1005][55];
vector<bool> vis(64, 0);
map<char, int> m;

bool calc(int i, int j, int k)
{
   for (int r = 0; r < N; r++)
      vis[16 * g[r][i] + 4 * g[r][j] + g[r][k]] = true;
   for (int r = N; r < 2 * N; r++)
      if (vis[16 * g[r][i] + 4 * g[r][j] + g[r][k]])
         return false;
   return true;
}

int main()
{
   m['A'] = 0, m['T'] = 1, m['G'] = 2, m['C'] = 3;
   fin >> N >> M;
   fori(i, 2 * N)
      fori(j, M) {
         char c;
         fin >> c;
         g[i][j] = m[c];
      }
   int ans = 0;
   for (int i = 0; i < M; i++)
      for (int j = i + 1; j < M; j++)
         for (int k = j + 1; k < M; k++) {
            if (calc(i, j, k)) ans++;
            fill(vis.begin(), vis.end(), 0);
         }
   fout << ans << endl;
}
