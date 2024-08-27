//
//  main.cpp
//  C++x_tmp
//
//  Created by MUC-StarChild-Mercury on 06.08.24.
//

//  C++ access modifiers/specifiers:
//
//              All users   Derived classes     Class' own users/members
//  Public          x               x                   x
//  Protected                       x                   x
//  Private                                             x

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define TRACE(x) (std::cout << #x << " = " << x << std::endl)

int main(int argc, const char * argv[]) {
    // insert code here...
    char *cp = const_cast<char*>("Hello, World!\n");
    std::cout << cp << std::endl;
    // __cplusplus: This preprocessor macro provides a numeric value indicating
    // the C++ standard. However, it's not always reliable and might not reflect
    // the full capabilities of the compiler.
//    TRACE(__cplusplus);
//    TRACE(__clang_version__);
    std::cout << "__cplusplus\t\t\t" << __cplusplus << std::endl;
    std::cout << "__clang_version__\t" << __clang_version__ << std::endl << std::endl;
    
    {
        
    }
    
    return 0;
}
