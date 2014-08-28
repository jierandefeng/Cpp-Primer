//! @Alan
//!
//! Exercise 11.32:
//! Using the multimap from the previous exercise, write a program to
//! print the list of authors and their works alphabetically.
//!

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::multimap<std::string, std::string> map
    {
        {"alan","google"},
        {"alan","bible"},
        {"Alan","fall"},
        {"Wang","sky"},
        {"Wang","oh sky"}
    };

    /**
     * @brief   print alphabetically    for Exercise 11.32
     *
     * @complx  O(n)
     *
     * @extra space O(n)
     *
     * @report  by @Queequeg
     */
    for(auto curr = map.begin(); curr != map.end();/* empty */)
    {
        //! print author
        std::cout << curr->first << ":";

        //! build buffer for works
        auto size = map.count(curr->first);
        std::vector<std::string> buffer(size);

        //! fill with works
        for(auto& elem : buffer)
            elem = curr++->second;

        //! sort works
        std::sort(buffer.begin(), buffer.end());

        //! print works in buffer
        for(const auto& elem : buffer)
            std::cout << elem << "  ";
        std::cout << std::endl;
    }

    return 0;
}
//! @output
//Alan:fall
//Wang:oh sky  sky
//alan:bible  google

