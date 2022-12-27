#include <iostream>
#include <string>

const std::string vowels = "aeiou";

const std::string pigLatinify(const std::string& str)
{
    if(str.size() == 0)
        return str;

    if(str.find("qu") == 0)
        return str.substr(2, str.size()-2) + "-" + str.substr (0, 2) + "ay";

    else if(vowels.find(str[0]) != std::string::npos )
        return str + "way";

    else
        return str.substr(1, str.size()-1) + "-" + str[0] + "ay";
}

int main()
{
    std::string str;
    std::cout<< "Enter a word to pig-latinify: ";

    std::cin>>str;
    std::cout<< pigLatinify(str) << '\n';

    return 0;
}
