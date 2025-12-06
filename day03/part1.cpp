#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

int main()
{
    std::string line;
    long tot = 0;

    int i = 0;
    while (std::getline(std::cin, line) && !line.empty())
    {
        std::istringstream ss(line);
        char c0, c1, c2;

        ss >> c0;

        int n0 = c0 - '0';
        int n1 = 0;

        while (ss >> c2) {
            const int n2 = c2 - '0';
 
            if (n2 > n0 && ss.peek() != std::char_traits<char>::eof())
            {
                n0 = n2;
                n1 = 0;
            }
            else if (n2 > n1)
            {
                n1 = n2;
            }
        }

        const int mx = (n0*10) + n1;
        tot += mx;
        i++;
        // std::printf("%d %d\n", i, mx);
    }

    std::printf("%ld\n", tot);
}