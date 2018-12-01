// COMPETITION: USACO
// NAME: 2018JanS1, Lifeguards
// DATE: November 30, 2018
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

ofstream fout ("lifeguards.out");
ifstream fin ("lifeguards.in");

int N;
pair<ll, ll> g[100005];

void init()
{
   fin >> N;
   for (int i = 0; i < N; i++) {
      fin >> g[i].f >> g[i].s;
   }
   sort(g, g + N);
}

ll total()
{
   stack<pair<ll, ll>> s;
   s.push(g[0]);
   for (int i = 1; i < N; i++) {
      pair<ll, ll> top = s.top();
      if (top.s < g[i].f)
         s.push(g[i]);
      else if (top.s < g[i].s) {
         top.s = g[i].s;
         s.pop();
         s.push(top);
      }
   }
   ll tot = 0;
   while (!s.empty()) {
      pair<ll, ll> t = s.top();
      tot += t.s - t.f;
      s.pop();
   }
   return tot;
}

ll lose()
{
   set<int> s;
   map<int, vi> m;
   for (int i = 0; i < N; i++) {
      m[g[i].f].pb(i);
      m[g[i].s].pb(i);
   }
   vector<int> ans(N, 0);
   int pt = m.begin()->first;
   for (auto a : m) {
      int t = a.f;
      if (s.size() == 1) {
         ans[*s.begin()] += t - pt;
      }
      for (int i : a.s) {
         auto it = s.find(i);
         if (it == s.end()) {
            s.insert(i);
         }
         else {
            s.erase(it);
         }
      }
      pt = t;
   }
   return *min_element(ans.begin(), ans.end());
}

int main()
{
   init();
   ll tot = total();
   ll ans = lose();
   fout << tot - ans << endl;
}
