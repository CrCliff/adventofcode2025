#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

constexpr int N = 1000;

int main() {
  std::string line;
  long tot = 0;
  long L[N], R[N];
  std::unordered_map<int, bool> incl;

  int M = 0;
  while (std::getline(std::cin, line) && !line.empty()) {
    std::istringstream ss(line);
    char c;
    ss >> L[M] >> c >> R[M];
    M++;
  }

  for (int i=0; i<M; i++) {
    incl[i] = true;

    for (int j=0; j<i; j++) {
      if (R[i] < L[j] || L[i] > R[j]) {
        ; // Not overlapping
      } else {
        // Mark the overlapped range to be ignored
        // since we extended our latest range to overlap it
        incl[j] = false;
        L[i] = std::min(L[i], L[j]);
        R[i] = std::max(R[i], R[j]);
      }
    }
  }

  for (int j=0; j<M; j++) {
    if (incl[j]) tot += R[j] - L[j] + 1;
  }

  std::printf("%ld\n", tot);
}