#include <iostream>

int main()
{
    char c;
    std::cout << "Enter an upper case character : ";
    std::cin >> c;
    std::cout << "ASCII value of " << c <<" is :  " << (int)c << '\n';
    std::cout << "We assign " << c << " the value of " << ((int)c - 64) << '\n';
    return 0;
}
