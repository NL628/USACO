// COMPETITION: USACO
// NAME: 2015JanG1. Cow Rectangles
// DATE: December 2, 2018

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> pd;
typedef pair<int, int> pi;
typedef pair<int, ll> pill;
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

ofstream fout("cowrect.out");
ifstream fin("cowrect.in");

int N;
char p[1005][1005];
vi r, c;
int dpG[505][505];
int dpH[505][505];
int maxH = 0, minA = INF;

bool rgG(int r1, int r2, int col)
{
   if (r1 == 0)
      return dpG[r2][col] != 0;
   return dpG[r2][col] != dpG[r1 - 1][col];
}

int rgH(int r1, int r2, int col)
{
   if (r1 == 0)
      return dpH[r2][col];
   return dpH[r2][col] - dpH[r1 - 1][col];
}

void precomp()
{
   for (int col = 0; col < sz(c); col++) {
      int tH = 0, tG = 0;
      for (int row = 0; row < sz(r); row++) {
         if (p[r[row]][c[col]] == 'H') ++tH;
         if (p[r[row]][c[col]] == 'G') ++tG;
         dpH[row][col] = tH;
         dpG[row][col] = tG;
      }
   }
}

void update(int tot, int area)
{
   if (tot > maxH) {
      maxH = tot;
      minA = area;
   }
   else if (tot == maxH) {
      minA = min(minA, area);
   }
}

int main()
{
   fin >> N;
   set<int> tr, tc;
   for (int i = 0; i < N; i++) {
      int x, y;
      fin >> x >> y;
      fin >> p[x][y];
      tr.insert(x);
      tc.insert(y);
   }
   for (int i : tr) r.pb(i);
   for (int i : tc) c.pb(i);
   precomp();
   for (int r1 = 0; r1 < sz(r); r1++) {
      for (int r2 = r1; r2 < sz(r); r2++) {
         int c1 = 0, c2 = 0, tot = 0, area = INF;
         while (c1 < sz(c) && c2 < sz(c)) {
            if (rgG(r1, r2, c2)) {
               c1 = c2 = c2 + 1;
               tot = 0, area = INF;
               continue;
            }
            if (c1 == c2 && rgH(r1, r2, c2) == 0) {
               c1 = c2 = c2 + 1;
               tot = 0, area = INF;
               continue;
            }
            tot += rgH(r1, r2, c2);
            area = (c[c2] - c[c1]) * (r[r2] - r[r1]);
            update(tot, area);
            c2++;
         }
      }
   }
   fout << maxH << '\n' << minA << endl;
}
