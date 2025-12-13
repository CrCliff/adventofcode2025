#include <iostream>
#include <sstream>
#include <string>

constexpr int N = 1000;

int main() {
  std::string line;
  long tot = 0;
  long L[N], R[N];

  auto is_fresh = [&L, &R](long id, int n) {
    for (int i = 0; i < n; i++) {
      if (L[i] <= id && id <= R[i]) return true;
    }
    return false;
  };

  int i = 0;
  while (std::getline(std::cin, line) && !line.empty()) {
    std::istringstream ss(line);
    char c;
    ss >> L[i] >> c >> R[i];
    i++;
  }

  while (std::getline(std::cin, line) && !line.empty()) {
    std::istringstream ss(line);
    long id;
    ss >> id;
    if (is_fresh(id, i+1)) tot++;
  }

  std::printf("%ld\n", tot);
}