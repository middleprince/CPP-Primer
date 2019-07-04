// ex15.19 
// derived member function and derived from derived (2 floor derive) 
// conversion and acessbility.
//
#include "ex15.20.Conversion.hpp"

int mian() {
    Pub_Dev d1;
    Prot_Dev d2;
    Priv_Dev d3;

    d1.pub_mem(); 

    // can not cast protected to base 
    //d2.pub_mem(); 
   
    // can not cast private to base 
    //d3.pub_mem(); 
   
    Deriv_from_Public dd1; 
    Deriv_from_Protect dd2;
    Deriv_from_Protect dd3;
   
    
    
    return 0;
}
