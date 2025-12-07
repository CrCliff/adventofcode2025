#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

constexpr int W = 10;
constexpr int H = 10;
constexpr int INF = -99;

int main()
{
    std::string line;
    long tot = 0;

    int GRID[H+2][W+2] = {0};

    int i = 1;
    while (std::getline(std::cin, line) && !line.empty())
    {
        std::istringstream ss(line);
        char c;

        int j = 1;
        while (ss >> c) {
            // GRID[i][j] = 1;

            if (c == '.') {
                GRID[i][j] = INF;
            }

            if (c == '@') {
                GRID[i][j-1] += 1;
                GRID[i][j+1] += 1;

                GRID[i-1][j]   += 1;
                GRID[i-1][j-1] += 1;
                GRID[i-1][j+1] += 1;

                GRID[i+1][j]   += 1;
                GRID[i+1][j-1] += 1;
                GRID[i+1][j+1] += 1;
            }
            j++;
        }

        i++;
    }

    for (int i = 1; i < H+1; i++) {
        for (int j = 1; j < W+1; j++) {
            if (GRID[i][j] >= 0 && GRID[i][j] < 4) {
                tot++;
            }
        }
    }

    // for (int i = 0; i < H+2; i++) {
    //     for (int j = 0; j < W+2; j++) {
    //         printf("%3d ", GRID[i][j]);
    //     }
    //     printf("\n");
    // }

    std::printf("%ld\n", tot);
}