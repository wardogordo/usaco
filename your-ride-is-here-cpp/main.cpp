#include <iostream>
#include <string>

int main()
{

    std::cout << "Enter a comet name: ";
    std::string cometName{};
    std::cin >> cometName;
    std::cout << "Now enter a group name: ";
    std::string groupName{};
    std::cin >> groupName;
    std::cout << "Comet: " << cometName << '\n';
    std::cout << "Group: " << groupName << '\n';

    return 0;
}
