#include "ex15.36.TextQueryMsg.hpp"

int main() {
    
    //Query ret = ~ word1;
    Query ret = Query("fiery") & Query("bird") | Query("wind"); 
    //cout << ret;

    //BinaryQuery a = word1 & word2;
    //AndQuery a = word1 & word2;

    
    return 0;
}
