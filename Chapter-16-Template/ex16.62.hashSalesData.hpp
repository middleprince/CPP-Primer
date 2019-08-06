#ifndef ex16_62_hashSalesData_hpp
#define ex16_62_hashSalesData_hpp

#include "../Chapter-14-Overload-Conversion/ex14.2.SalesData.hpp"

namespace std {
    template <>
    struct std::hash<SalesData> {
        typedef std::size_t result_type; 
        typedef SalesData argument_type; 
        result_type operator() (const SalesData &s) const noexcept {
            return hash<std::string>() (s.bookNo) ^ 
                   hash<unsigned>() (s.unit_sold) ^
                   hash<double>() (s.revenue); 
        }
    };
}
#endif
