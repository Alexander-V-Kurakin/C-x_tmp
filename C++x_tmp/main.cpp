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
#include <fstream>
#include <cstdio>       // For std::remove
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
    
    string in_file_name( "any_file_name" ), out_file_name( "any_file_name" );
    
    {
        ofstream out_file_stream( out_file_name );
        
        if ( !out_file_stream.is_open())
            cerr << "File " << out_file_name << " is not opened / created" << endl;
        
        ifstream in_file_stream( in_file_name );
        
        if ( !in_file_stream.is_open())
            cerr << "File " << in_file_name << " is not opened" << endl;
        
        // The file stream automatically be closed once out of scope.
    }
    
    remove( out_file_name.c_str());     // Only required once, same file name used.
    
    return 0;
}
