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
#define coutarr(cout, a, N) fori(i, N) cout << a[i] << " "; cout << endl;
#define cinarr(cin, a, N) fori(i, N) cin >> a[i];
 
const double PI = 4 * atan(1);
const int MOD = 1000000007;
const ll LINF = 1ll << 60;
const int INF = 1 << 30;
 
ofstream fout ("bphoto.out");
ifstream fin ("bphoto.in");
 
#define fin cin 
#define fout cout
 
int N, t[100005];
pi h[100005];
 
int sum(int i) {
    int m = 0; i++;
    while (i) {
        m += t[i];
        i -= i & (-i);
    }
    return m;
}
 
void add(int i, int x) {
    i++;
    while (i <= N) {
        t[i] += x;
        i += i & (-i);
    }
}
 
int main() {
	fin >> N;
	fori(i, N) {
		int x;
		fin >> x;
		h[i] = mp(x, i);
	}
	sort(h, h + N, greater<pi>());
	int t = 0;
	fori(i, N) {
		int l = sum(h[i].s);
		int r = i - l;
		if (l > r + r || r > l + l) t++;
		add(h[i].s, 1);
	}
	fout << t << endl;
}
