//
// Exercise 16.60:
// Explain how make_shared (§ 12.1.1, p. 451) works.
//
//  make_shared shoudl be a variadic template function that forwards all arguments to
//  underlying constructors that allocate and initializes an object in dynamic memory and
//  , at last, build a shared_ptr by wrapping the raw pointer.
//
// Exercise 16.61:
// Define your own version of make_shared.
//

#ifndef  ex16_61_make_shared_hpp
#define  ex16_61_make_shared_hpp

#include <memory>

namespace ex16{
    template <typename T, typename... Args>
    auto make_shared(Args&&... rest) ->std::shared_ptr<T> {
        return std::shared_ptr<T>(new T(std::forward<Args>(rest)...)); 
    }

}

#endif
