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
            // 1. Lambda expressions Capture List: [=] all local objects passing by value,
            // [&] all local objects passing by reference, [] no external objects available.
            int n{ 10 };
            auto add = [ = ]( int x ) { cout << x + n << endl; };
            add( 4 );
            
            int* pn { &n };
            auto increment = [ pn ](){( *pn )++; };
            increment();
            cout << n << endl;
            
            auto add_2 = [ & ]( int& x ) { cout << ++x << endl; };  // if not const int&
            add_2( n );
            auto add_3 = [ & ]() { cout << ++n << endl; };
            add_3();
            
            // 2. mutable parameter. Only a copy of external n (passed by value) will be changed.
            auto add_4 = [ = ]( int x ) mutable { cout << x + ++n << endl; };
            add_4( 4 );
            cout << n << endl;  // The value of external n is not changed!
            
            // 3. The capture list spec examples:
            // [&n] only n can be captured by reference,
            // [=n] or just [n] only n can be captured by value,
            // [ &k, l, &m, n ] only k and m can be captured by reference, the rest - by value,
            // [ =, &m, &n ] all can be captured by value, the rest - by reference,
            // [ &, m, n ] all can be captured by reference, the rest - by value,
            // [ this, &n, m ] to capture a class members, the this is used.
        }
        
        return 0;
    }
