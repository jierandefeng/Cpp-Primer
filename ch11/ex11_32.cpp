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
        std::vector<std::string> works(size);

        //! fill and increment curr 
        for(auto& elem : works)
            elem = curr++->second;

        //! sort 
        std::sort(works.begin(), works.end());

        //! print works 
        for(const auto& elem : works)
            std::cout << elem << "  ";
        std::cout << std::endl;
    }

    return 0;
}
//! @output
//Alan:fall
//Wang:oh sky  sky
//alan:bible  google

