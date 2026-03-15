#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool b[10];
  for (int i = 0; i < 10; i++)
    cin >> b[i];

  bool res = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      res ^= (b[i] || b[j]);
      for (int k = j + 1; k < 10; k++)
        res ^= (b[i] || b[j] || b[k]);
    }
  }

  cout << res << "\n";

  return 0;
}