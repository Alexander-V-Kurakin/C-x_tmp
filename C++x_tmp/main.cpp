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

void header() {
    char *cp = const_cast<char*>( "Hello, World!\n" );
    std::cout << cp << std::endl;
    // __cplusplus: This preprocessor macro provides a numeric value indicating
    // the C++ standard. However, it's not always reliable and might not reflect
    // the full capabilities of the compiler.
//    TRACE(__cplusplus);
//    TRACE(__clang_version__);
    std::cout << "__cplusplus\t\t\t" << __cplusplus << std::endl;
    std::cout << "__clang_version__\t" << __clang_version__ << std::endl << std::endl;
}

void do_operation( int a, int b, int ( *op )( int, int )) {
    cout << op( a, b ) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    header();
    
    {
        // 1. Since C++14 the leading () can be omitted if no parameters used.
        // The last () mean the lambda expression is called, no parameters used.
        [](){ cout << "Hello from lambda expression!" << endl; } ();
        []{ cout << "Hello from lambda expression!" << endl; } ();
        
        // 2. Named lambda expression.
        auto hello {[](){ cout << "Hello from named lambda expression!" <<  endl; }};
        hello();
        hello();    // is called as usual function.
        
        // 3. Parameterized lambda expression.
        auto print {[]( const string& text ) { cout << text << endl; }};
        print( "Hello from named lambda expression!" );
        print( "Goodbye from named lambda expression!" );
        []( const string& text ) { cout << text << endl; } ( "Hello from non-named lambda expression!" );
        
        // 4. Return of value of lambda expression.
        auto sum {[]( int a, int b ) { return a + b; }};
//        auto sum {[]( int a, int b ) -> int { return a + b; }};     // with return type
        cout << sum( 1, 2 ) << endl;
        int s = sum( 3, 4 );            // or int s{ sum( 3, 4 )};
        cout << s << endl;
        
        // 5. Lambda expression as function parameter.
        auto subtract {[]( int a, int b ) { return a - b; }};
        do_operation( 5, 6, sum );
        do_operation( 8, 7, subtract );
        do_operation( 2, 3, []( int a, int b ) { return a * b; });  // Lambda expression direct usage
        
        // 6. Generic (universal) lambda expression.
        auto add_2 = []( auto a, auto b ) { return a + b; };
        auto print_2 = []( const auto& value ) { cout << value << endl; };
     
        cout << add_2( 2, 3 ) << endl;              // sum of int
        cout << add_2( 2.2, 3.4 ) << endl;          // sum of double
     
        string hello_2{ "Hello from "};
        string lambda{ "lambda expression!" };
        cout << add_2( hello_2, lambda ) << endl;   // string concatenation
        
        print_2( "Hello from lambda expression!" );
        print_2( 1 );
        print_2( 123.4567 );
    }
    
    return 0;
}
