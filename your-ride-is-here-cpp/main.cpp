#include <iostream>
#include <string>

std::string cometName{};
std::string groupName{};
int cometProduct{1};
int groupProduct{1};

void ComputeComet()
{

    for (int i = 0; i < cometName.length(); ++i)
    {
        cometProduct *= (int)cometName[i] - 64;
    }

    std::cout << "Comet total: " << cometProduct << '\n';
}

void ComputeGroup()
{

    for (int i = 0; i < groupName.length(); ++i)
    {
        groupProduct *= (int)groupName[i] - 64;
    }

    std::cout << "Group total: " << groupProduct << '\n';
}

void StayOrGo()
{
    std::cout << "cometProduct % 47 = " << cometProduct % 47 << '\n';
    std::cout << "groupProduct % 47 = " << groupProduct % 47 << '\n';
    if (cometProduct % 47 == groupProduct % 47)
        std::cout << "GO" << '\n';
    else
        std::cout << "STAY" << '\n';
}

int main()
{
    std::cout << "Enter a comet name: ";
    std::cin >> cometName;
    std::cout << "Now enter a group name: ";
    std::cin >> groupName;
    std::cout << "Comet: " << cometName << '\n';
    std::cout << "Group: " << groupName << '\n';

    ComputeComet();
    ComputeGroup();
    StayOrGo();
    return 0;
}

