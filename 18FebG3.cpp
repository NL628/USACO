#include <bits/stdc++.h>
using namespace std;

ofstream fout ("taming.out");
ifstream fin ("taming.in");

const int MAXN = 105;

// input data
int N, A[MAXN];

// dp array
int dp[MAXN][MAXN][MAXN]; // [current index][last breakout index][# of breakouts up to current index]

int main() {
  // read in data
  fin >> N;
  for (int i = 0; i < N; i++)
    fin >> A[i];
  
  // implement dynamic programming
  
  // Initialize: set minimum of everything to MAXN because max tampers = MAXN
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= N; k++) // k must start from 0 because dp[][][0] is used in the dp loops
        dp[i][j][k] = MAXN;
  
  // Base Case: no change needed to first element if A[0] = 0, which it should be
  dp[0][0][1] = !(A[0] == 0);
  
  // loop through all indices
  for (int i = 1; i < N; i++) {
    // the last breakout index can be any index up to 'i'
    for (int j = 0; j <= i; j++) {
      // and the number of breakouts can be any number up to 'i' + 1
      for (int k = 1; k <= i + 1; k++) {
        // case 1: j < i; then, min # changes = dp[i - 1][j][k] + whether or not 'i'th element should be changed
        if (j < i)
          dp[i][j][k] = dp[i - 1][j][k];
          
        // case 2: j = i; then, min # changes = min of all dp[i - 1][j'][k - 1], as last breakout can be anywhere before 'i'
        else
          for (int jj = 0; jj < i; jj++)
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][jj][k - 1]);
            
        // now we check whether the ith element needs to be changed or not
        if (A[i] != i - j)
          dp[i][j][k]++;
      }
    }
  }
  
  // the kth answer is the min of all dp[N - 1][j][k] where 0 <= j < N
  for (int k = 1; k <= N; k++) {
    // maximum possible value of answer is MAXN
    int ans = MAXN;
    for (int j = 0; j < N; j++)
      ans = min(ans, dp[N - 1][j][k]);
    fout << ans << endl;
  }
  return 0;
}
