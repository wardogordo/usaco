#include <iostream>
#include <string>
#include <regex>
#include <locale>

std::string cometName{};
std::string groupName{};
int cometProduct{1};
int groupProduct{1};

void ValidateCometInput(std::string str)
{
    if(!std::regex_match(str, std::regex("[A-Za-z]+")))
        {
            std::cin.clear(); //TODO => fix the cin buffer clear in order to redo after incorrect entries.
        std::cout << "Comet names can only include alpha characters.\n";
            std::cout << "Your entry: " << str << '\n';
            std::cin.clear();
            std::cout << "Try again with a comet name with only alpha characters: ";
            std::cin >> cometName;
            ValidateCometInput(cometName);
        }

    if (str.length() != 6)
    {
        std::cin.clear();
        std::cout << "Comet name length must be exactly 6 characters in length.\n";
        std::cout << "Your " << str.length() << " character entry: " << str << '\n';
        std::cin.clear();
        std::cout << "Try again with a 6 character comet name: ";
        std::cin >> cometName;
        ValidateCometInput(cometName);
    }

    std::cout << "Comet name entry successfully validated: " << cometName << '\n';
}

void ValidateGroupInput(std::string str)
{
    if(!std::regex_match(str, std::regex("[A-Za-z]+")))
    {
        std::cin.clear();
        std::cout << "Group names can only include alpha characters.\n";
        std::cout << "Your entry: " << str << '\n';
        std::cin.clear();
        std::cout << "Try again with a group name with only alpha characters: ";
        std::cin >> groupName;
        ValidateCometInput(groupName);
    }

    if (str.length() != 6)
    {
        std::cin.clear();
        std::cout << "Group name length must be exactly 6 characters in length.\n";
        std::cout << "Your " << str.length() << " character entry: " << str << '\n';
        std::cin.clear();
        std::cout << "Try again with a 6 character group name: ";
        std::cin >> groupName;
        ValidateCometInput(groupName);
    }

    std::cout << "Group name entry successfully validated: " << groupName << '\n';
}

void CometNameToUpper(std::string comet)
{
    std::locale loc;
    for (std::string::size_type i = 0; i < comet.length(); ++i)
    {
        comet[i] = std::toupper(comet[i], loc);
    }
     std::cout << "Comet name converted to uppercase: " << comet << '\n';
    cometName = comet;
}

void GroupNameToUpper(std::string group)
{
    std::locale loc;
    for (std::string::size_type i = 0; i < group.length(); ++i)
    {
        group[i] = std::toupper(group[i], loc);
    }
    std::cout << "Group name converted to uppercase: " << group << '\n';
    groupName = group;
}


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
    std::cout << "Please enter a comet name: ";
    std::cin >> cometName;
    ValidateCometInput(cometName);
    std::cout << "Now enter a group name: ";
    std::cin >> groupName;

    ValidateGroupInput(groupName);

    // Alphas to upper
    CometNameToUpper(cometName);
    GroupNameToUpper(groupName);

    ComputeComet();
    ComputeGroup();
    StayOrGo();
    return 0;
}

