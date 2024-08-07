    //
    //  main.cpp
    //  C++x_tmp
    //
    //  Created by MUC-StarChild-Mercury on 06.08.24.
    //

    #include <iostream>

    int main(int argc, const char * argv[]) {
        // insert code here...
        std::cout << "Hello, World!\n\n";
        // __cplusplus: This preprocessor macro provides a numeric value indicating
        // the C++ standard. However, it's not always reliable and might not reflect
        // the full capabilities of the compiler.
        std::cout << "__cplusplus\t\t\t" << __cplusplus << std::endl;
        std::cout << "__clang_version__\t" << __clang_version__ << std::endl;
        return 0;
    }
