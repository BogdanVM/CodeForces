#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string& s, char sep) {
    std::stringstream stream(s);
    std::string temp;
    std::vector<std::string> v;

    while(std::getline(stream, temp, sep)) {
        v.push_back(temp);
    }

    return v;
}

void parseInstruction(std::string& cd, const std::string& cmd) {
    std::vector<std::string> args = split(cmd, ' ');

    if (args[0] == "pwd") {
        if (cd == "/") {
            std::cout << cd << "\n";
        } else {
            std::cout << cd << "/\n";
        }
        return;
    }

    /* Otherwise it's a cd command, so update the current directory */
    int i = 0;
    if (args[1][0] == '/') {
        i = 1;
        cd = "/";
    }

    std::vector<std::string> dirs = split(args[1], '/');
    int n = dirs.size();

    for (; i < n; ++i) {
        if (dirs[i] == "..") {
            int lastSlash = cd.find_last_of("/");
            cd = cd.substr(0, cd.size() - cd.substr(lastSlash).size());
        } else {
            if (cd == "/") {
                cd += dirs[i];
            } else {
                cd += "/" + dirs[i];
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::string currentDirectory = "/";
    for (int i = 0; i < n; ++i) {
        std::string cmd;
        std::getline(std::cin >> std::ws, cmd);

        parseInstruction(currentDirectory, cmd);
    }
    return 0;
}