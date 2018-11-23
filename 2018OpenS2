#include <bits/stdc++.h>
using namespace std;

ofstream fout ("lemonade.out");
ifstream fin ("lemonade.in");

const int MAXN = 100005;

int N, w[MAXN];

int main() {
  // read in input
  fin >> N;
  for (int i = 0; i < N; i++)
    fin >> w[i];

  // sort from greatest to least
  sort(w, w + N, greater<int>());
  
  // count the number of cows that can stand in line in this configuration
  int ans = 0;
  for (int i = 0; i < N; i++)
    if (w[i] >= i)
      ans++;
  fout << ans << endl;
}
