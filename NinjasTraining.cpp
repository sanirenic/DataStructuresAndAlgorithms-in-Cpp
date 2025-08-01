#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>& points) {

  vector<vector<int>> dp(n, vector<int>(4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {

          int activity = points[day][task] + dp[day - 1][task];

          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }

  return dp[n - 1][3];
}

int main() {

  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
  int n = points.size();  
  cout << ninjaTraining(n, points);
}

