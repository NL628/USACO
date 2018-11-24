// COMPETITION: USACO
// URL: bit.ly/2zj8BX9
// DATE: Nov 23, 2018
// STATUS: Finished

#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pd;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second

const double PI = 4 * atan(1);
const int MOD = 1000000007;
const ll LINF = 1ll << 60;
const int INF = 1 << 30;

ofstream fout ("fortmoo.out");
ifstream fin ("fortmoo.in");

const int MX = 200 + 5;
int N, M;
char site[MX][MX];
int conv[MX][MX];

bool hasX(int c, int r1, int r2) {
  return conv[r2][c] != conv[r1 - 1][c];
}

int main() {
  fin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      fin >> site[i][j];
  
  for (int c = 1; c <= M; c++)
    for (int r = 1; r <= N; r++)
      conv[r][c] = conv[r - 1][c] + (site[r][c] == 'X');
  
  int ans = 0;
  for (int r1 = 1; r1 <= N; r1++) {
    for (int r2 = r1; r2 <= N; r2++) {
      int c1 = 1, c2;
      for (c2 = c1; c2 <= M; c2++) {
        if (c1 == c2) {
          if (hasX(c2, r1, r2)) {
            c1 = c2 + 1;
            continue;
          }
        }
        else {
          if (site[r1][c2] == 'X' || site[r2][c2] == 'X')
            c1 = c2 + 1;
          else
            if (!hasX(c2, r1, r2))
              ans = max(ans, (c2 - c1 + 1) * (r2 - r1 + 1));
        }
      }
    }
  }
  fout << ans << endl;
}
