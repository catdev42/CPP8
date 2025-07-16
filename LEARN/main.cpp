#include <string>
#include <iostream>
#include <vector>

int main()
{
    // WHAT ARE REFERENCES?
    // A reference is an ALIAS (another name) for an existing object

    int x = 42;
    int &ref_x = x; // ref_x is a reference to x (they are the SAME object)

    std::cout << "x = " << x << std::endl;         // prints 42
    std::cout << "ref_x = " << ref_x << std::endl; // prints 42

    ref_x = 100; // This changes x too! They're the same object
    std::cout << "After ref_x = 100:" << std::endl;
    std::cout << "x = " << x << std::endl;         // prints 100
    std::cout << "ref_x = " << ref_x << std::endl; // prints 100

    // KEY POINT: References are NOT objects themselves!
    // They don't have their own memory address - they ARE the original object

    std::cout << "\nMemory addresses:" << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Address of ref_x: " << &ref_x << std::endl; // SAME address!

    // WHY CAN'T WE HAVE vector<int&>?
    // Because:
    // 1. References must be initialized when declared
    // 2. References cannot be reassigned
    // 3. References are not objects - they don't exist independently

    // This would be INVALID:
    // std::vector<int&> vec_of_refs;  // ERROR! Can't store references

    // But we CAN have:
    std::vector<int> vec_of_ints = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> vec_of_vecs = {{1, 2}, {3, 4}, {5, 6}};

    // And we can have vectors of POINTERS (which ARE objects):
    std::vector<int *> vec_of_pointers;
    vec_of_pointers.push_back(&x);

    std::cout << "\nVector examples:" << std::endl;
    std::cout << "vec_of_ints[0] = " << vec_of_ints[0] << std::endl;
    std::cout << "vec_of_vecs[0][1] = " << vec_of_vecs[0][1] << std::endl;
    std::cout << "*(vec_of_pointers[0]) = " << *(vec_of_pointers[0]) << std::endl;

    return 0;
}