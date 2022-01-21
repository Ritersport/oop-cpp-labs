#pragma once

#include <iostream>
#include <tuple>
#include <string>


template<class Ch, class Tr, class Tuple, std::size_t N>
class TuplePrinter
{
public:
    static void print(std::basic_ostream<Ch, Tr>& os, const Tuple& tuple)
    {
        TuplePrinter<Ch, Tr, Tuple, N - 1>::print(os, tuple);
        os << ", " << std::get<N - 1>(tuple);
    }
};


template<class Ch, class Tr, class Tuple>
class TuplePrinter<Ch, Tr, Tuple, 1>
{
public:
    static void print(std::basic_ostream<Ch, Tr>& os, const Tuple& tuple)
    {
       os << std::get<0>(tuple);
    }
};

template<typename Ch, typename Tr, typename... Args>
std::basic_ostream<Ch, Tr>& operator<< (std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>const& t)
{
    std::cout << "[";
    TuplePrinter<Ch, Tr, decltype(t), sizeof...(Args)>::print(os, t);
    std::cout << "]";
    return os;
}