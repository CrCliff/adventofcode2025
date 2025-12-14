#include <iostream>
#include <sstream>
#include <string>

constexpr int M = 4;
constexpr int N = 3;

int main() {
  std::string line;
  long tot = 0;
  char OPS[M] = {};
  long G[M][N] = {{}};

  for (int i=0; std::getline(std::cin, line) && i<N; i++) {
    std::istringstream ss(line);
    long x;
    for (int j=0; ss>>x; j++) G[j][i] = x;
  }

  std::istringstream ss(line);
  char c;
  for (int i=0; ss>>c; i++) OPS[i] = c;

  for (int j = 0; j < M; j++) {
    long res = OPS[j] == '*' ? 1 : 0;
    for (int i = 0; i < N; i++) {
      res = OPS[j] == '*' ? res*G[j][i] : res+G[j][i];
      // std::printf("%3ld %2c ", G[j][i], ops[j]);
    }
    tot += res;
    // std::printf("%3ld\n", res);
  }

  std::printf("%ld\n", tot);
}