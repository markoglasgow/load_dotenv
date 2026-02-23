#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

// Trim from start (in place)
static inline void ltrim(std::string& s)
{
    s.erase(s.begin(),
        std::find_if(s.begin(), s.end(),
            [](unsigned char ch) { return !std::isspace(ch); }));
}

// Trim from end (in place)
static inline void rtrim(std::string& s)
{
    s.erase(
        std::find_if(s.rbegin(), s.rend(),
            [](unsigned char ch) { return !std::isspace(ch); }).base(),
        s.end());
}

// Trim both ends
static inline void trim(std::string& s)
{
    ltrim(s);
    rtrim(s);
}

// Remove surrounding double quotes if present
static inline void stripOuterQuotes(std::string& s)
{
    if (s.length() >= 2 && s.front() == '"' && s.back() == '"')
    {
        s = s.substr(1, s.length() - 2);
    }
}

// Escape CMD special characters
std::string escapeForCmd(const std::string& value)
{
    std::string escaped;
    for (char c : value)
    {
        switch (c)
        {
        case '^':
        case '&':
        case '|':
        case '<':
        case '>':
            escaped += '^';
            escaped += c;
            break;
        default:
            escaped += c;
        }
    }
    return escaped;
}

int main(int argc, char* argv[])
{
    std::string filename = ".env";

    if (argc > 1)
        filename = argv[1];

    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line))
    {
        trim(line);

        // Skip empty lines
        if (line.empty())
            continue;

        // Skip comments
        if (line[0] == '#')
            continue;

        // Find '='
        size_t eqPos = line.find('=');
        if (eqPos == std::string::npos)
            continue;

        std::string key = line.substr(0, eqPos);
        std::string value = line.substr(eqPos + 1);

        trim(key);
        trim(value);

        if (key.empty())
            continue;

        // Remove surrounding quotes if present
        stripOuterQuotes(value);

        value = escapeForCmd(value);

        std::cout << "set \"" << key << "=" << value << "\"" << std::endl;
    }

    return 0;
}
