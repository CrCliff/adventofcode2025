#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

int is_invalid(std::string str, int n) {
    const std::string init = str.substr(0, n);

    if (str.length() % n != 0) {
        return false;
    }

    if (str.length() < 2*n) {
        return false;
    }

    for (int i = n; i < str.length(); i += n) {
        if (str.substr(i, n) != init) {
            return false;
        }
    }

    return true;
}

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
            const std::string s = std::to_string(i);
            const int l = s.length();

            for (int j = 1; j <= l/2; j++) {
                if (is_invalid(s, j)) {
                    // printf("%s\n", s.c_str());
                    tot += i;
                    break;
                }
            }
        }
    }

    std::cout << tot << std::endl;
}