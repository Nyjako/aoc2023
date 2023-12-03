#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

bool is_num(char c) 
{
    return c >= '0' && c <= '9';
}

int main(void)
{
    int total = 0;

    std::ifstream file("1.txt");
    std::string line;
    while (file >> line)
    {
        int l = -1, r = -1;
        for (int i = 0; i < line.size(); i++)
        {
            if (l == -1 && is_num(line[i])) l = line[i] - '0';
            if (r == -1 && is_num(line[line.size() - i - 1])) r = line[line.size() - i - 1] - '0';

            if (l >= 0 && r >= 0) break;
        }
        std::cout << "L: " << l << ", R: " << r << '\n';
        if (l == -1 || r == -1) continue;

        total += std::atoi( ( std::to_string(l) + std::to_string(r) ).c_str() );
    }

    std::cout << "Total: " << total << '\n';
}