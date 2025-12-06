#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

int main()
{
    std::string line;
    long long tot = 0;

    while (std::getline(std::cin, line, ',') && !line.empty())
    {
        std::istringstream ss(line);
        char _dash;
        ulong n0, n1;

        ss >> n0 >> _dash >> n1;

        for (ulong i = n0; i <= n1; i++)
        {
            std::string s = std::to_string(i);
            const int l = s.length();

            bool is_valid = (l % 2 == 1);
            for (int j = 0; j < l/2; j++) {
                if (s[j] != s[j+l/2]) {
                    is_valid = true;
                    break;
                }
            }

            if (!is_valid) {
                // printf("%lu\n", i);
                tot += i;
            }
        }
    }

    std::cout << tot << std::endl;
}