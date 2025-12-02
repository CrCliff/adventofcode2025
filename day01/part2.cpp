#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    int curr = 50;
    int tot = 0;

    while (std::getline(std::cin, line) && !line.empty()) {
        char dir;
        int dist;

        std::istringstream stream(line);
        stream >> dir >> dist;

        if (dir == 'L') {
            dist *= -1;
        }

        curr += dist;

        while (curr < 0) {
            curr += 100;
            tot++;
        }

        while (curr >= 100) {
            curr -= 100;
            tot++;
        }

        // std::cout << line << " " << dir << " " << dist << " " << curr << std::endl;
    }

    std::cout << tot << std::endl;
}