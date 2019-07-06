#include "Query.hpp"

int main() {
    ifstream file("./textFile"); 
    TextQuery ts(file);

    Query q = Query("fiery") & Query("wind") | Query("bird"); 
    cout << q.eval(ts);


    return 0;
}
