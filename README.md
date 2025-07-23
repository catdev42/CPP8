# EX00

## NEW CONCEPTS

* Containers like vector and arrar: array is static size, vector is dynamic
* Iterators are like clases or structs tht are like smart pointers for specific container types (there is no << operator to print it)
* Value_type is a typedef of whatever thing the container is holding
* Catching exception by reference is important otherwise you will only "copy" the std::exception part of the exception and print the incorrect e.what()
* We can initialize a container in C++98 by making an array and then providing the pointer to the first element and the memory after the last element... bassically 2 pointers that iwll be copied into container memory. This is called something like range initiation
* std::find(x.begin(), c.end(), thingToFind) - returns an iterator to the thing found... which must be stored in THAT type of iterator...  
ex:  
`typename T::iterator it = std::find(x.begin(), c.end(), thingToFind);`  
`std::vector<int>::iterator it = std::find(x.begin(), x.end(), thingToFind);`

#EX01

### Should this Span class use an std::array inside? since arrays are containers that are a specific size? 
Array must be initialized at compile time, so it cannot be used. We will use a Vector container for this exercise

### LEARNINGS

* when working to compare 2 elements, can define 2 iterators, it and next_it for example in order to make the function work with MULTIPLE types of containers
* 
