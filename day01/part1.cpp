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

        // std::cout << line << " " << dir << " " << dist << " " << curr << std::endl;

        if (curr % 100 == 0) {
            tot++;
        }
    }

    std::cout << tot << std::endl;
}