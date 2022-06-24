#include <algorithm>
#include <iostream>


std::string
spinWords(const std::string& str)
{
    std::string str_copy = str;
    // Single word, whole string can be reversed
    if (std::find(str.begin(), str.end(), ' ') == str.end())
        {
            std::reverse_copy(str.begin(), str.end(), str_copy.begin());
        }
    else
        {
            auto last_word_boundary = str_copy.begin();
            auto cur_word_boundary  = str_copy.begin();

            do
                {
                    std::advance(cur_word_boundary, str_copy.find_first_of(' '));
                    std::cout << *cur_word_boundary << '\n';
                }
            while (cur_word_boundary != str_copy.end());
        }
    return str_copy;
}    // spinWords


int
main()
{
    // std::cout << spinWords("Welcome") << '\n';
    std::cout << spinWords("Hey fellow warriors") << '\n';
    // std::cout << spinWords("Pizza is  the best vegetable") << '\n';
    return 0;
}
