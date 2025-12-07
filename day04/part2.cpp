#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

constexpr int W = 10;
constexpr int H = 10;
constexpr int INF = -99;

void incr(int g[H+2][W+2], int i, int j, int v) {
    g[i][j - 1] += v;
    g[i][j + 1] += v;

    g[i - 1][j] += v;
    g[i - 1][j - 1] += v;
    g[i - 1][j + 1] += v;

    g[i + 1][j] += v;
    g[i + 1][j - 1] += v;
    g[i + 1][j + 1] += v;
}

int main()
{
    std::string line;
    long tot = 0;

    int G[H+2][W+2] = {0};

    int i = 1;
    while (std::getline(std::cin, line) && !line.empty())
    {
        std::istringstream ss(line);
        char c;

        int j = 1;
        while (ss >> c) {
            if (c == '.') {
                G[i][j] = INF;
            }

            if (c == '@') {
                incr(G, i, j, 1);
            }
            j++;
        }
        i++;
    }

    // Assume we can always remove at least roll.
    bool cont = true;
    while (cont) {
        cont = false;
        for (int i = 1; i < H+1; i++) {
            for (int j = 1; j < W+1; j++) {
                if (G[i][j] >= 0 && G[i][j] < 4) {
                    G[i][j] = INF;
                    incr(G, i, j, -1);
                    tot++;
                    cont = true;
                }
            }
        }
    }

    // for (int i = 0; i < H+2; i++) {
    //     for (int j = 0; j < W+2; j++) {
    //         printf("%4d ", G[i][j]);
    //     }
    //     printf("\n");
    // }

    std::printf("%ld\n", tot);
}