#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

constexpr int DIGITS = 12;

int main()
{
    std::string line;
    long tot = 0;

    while (std::getline(std::cin, line) && !line.empty())
    {
        std::istringstream ss(line);
        char c0;

        std::vector<int> ds;
        while (ss >> c0)
        {
            ds.push_back(c0 - '0');
        }

        int left = 0;
        std::vector<int> mxs;

        for (int j = 0; j < DIGITS; j++)
        {
            int mx = 0;
            for (int i = left; i < ds.size() - DIGITS + j + 1; i++)
            {
                if (ds[i] > mx) {
                    mx = ds[i];
                    left = i;
                }
            }
            left++;
            mxs.push_back(mx);
            // std::printf("%d ", mx);
        }

        long long N = 0;
        int p = DIGITS - 1;
        for (int mx : mxs) {
            N += mx * std::pow(10,p);
            p--;
        }

        tot += N;

        // std::printf("%lld \n", N);
    }

    std::printf("%ld\n", tot);
}