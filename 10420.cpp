#include <map>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

int main(int argc, char const *argv[])
{
    char line[0xFF];
    char *pL;
    std::map<std::string, int> map;
    if(!fgets(line, 0xFF, stdin))
        return 1;
    while(fgets(line, 0xFF, stdin))
    {
        pL = &line[0];
        while(*pL && *pL != ' ')  ++pL;
        std::string country(line, pL - &line[0]);
        auto it = map.find(country);
        if(it == map.end())
            map.insert(std::pair<std::string, int>(country, 1));
        else
            it->second++;
    }

    for (auto it=map.begin(); it!=map.end(); ++it)
        printf("%s %d\n", it->first.c_str(), it->second);

    return 0;
}
