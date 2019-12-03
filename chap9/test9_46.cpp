#include <iostream>
#include <string>

auto add_pre_and_sufflix(std::string name, std::string const& pre, std::string const& su)
{
    name.insert(0, pre);
    name.insert(name.size(), su);
    return name;
}

int main()
{
    std::string name("alan");

    std::cout << add_pre_and_sufflix(name, "Mr.", ", Jr.") << std::endl;

    return 0;
}
