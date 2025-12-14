#include <iostream>
#include <sstream>

constexpr int M = 15;
constexpr int N = 4;

// constexpr int M = 3724;
// constexpr int N = 5;

int main() {
  std::string line;
  long tot = 0;
  char G[M][N] = {{}};

  for (int i=0; std::getline(std::cin, line) && i<N; i++) {
    for (size_t j=0; j<line.size(); j++) G[j][i] = line[j];
  }

  auto is_empty = [](const char *s) {
    return std::all_of(s, s+N, [](const char c) {return std::isspace(c);});
  };

  for (int i=0; i<M;) {
    const char OP = G[i][N-1];
    long res = OP == '*' ? 1 : 0;
    long l;
    for (std::istringstream ss(G[i]); ss>>l; ss = std::istringstream(G[i])) {
      // std::printf("%ld ", l);
      res = OP == '*' ? res*l : res+l;
      i++;
      if (is_empty(G[i])) { i++; break; }
    }
    // std::printf("%c\n", op);
    tot += res;
  }

  std::printf("%ld\n", tot);
}