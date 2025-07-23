# NEW CONCEPTS

* Containers like vector and arrar: array is static size, vector is dynamic
* Iterators are like clases or structs tht are like smart pointers for specific container types (there is no << operator to print it)
* Value_type is a typedef of whatever thing the container is holding
* Catchiing exception by reference is important otherwise you will only "copy" the std::exception part of the exception and print the incorrect e.what()
* We can initialize a container in C++98 by making an array and then providing the pointer to the first element and the memory after the last element... bassically 2 pointers that iwll be copied into container memory.

## What are containers and algorythms in C++?

In C++, the Standard Template Library (STL) provides a collection of container classes and generic algorithms.

**Containers** are objects that store collections of other objects (elements). They manage the storage for their elements and provide member functions to access them. Examples include `std::vector`, `std::list`, `std::map`, and `std::set`.

**Algorithms** are functions that perform operations on elements within containers. They are typically provided as standalone template functions and work with iterators to specify the range of elements to operate on. Examples include `std::sort`, `std::find`, and `std::copy`. This design separates the data structures from the operations performed on them, promoting code reuse and flexibility.

## What are associative containers?

**Associative containers** are a type of container that stores elements in a sorted manner, allowing for fast retrieval based on keys. Unlike sequence containers (like `std::vector`), elements are not stored in a linear sequence. Instead, their position depends on their key according to a specific sorting criterion.

The primary associative containers in C++ are:
- `std::set`: Stores a collection of unique keys.
- `std::multiset`: Similar to `std::set`, but allows duplicate keys.
- `std::map`: Stores key-value pairs with unique keys.
- `std::multimap`: Similar to `std::map`, but allows duplicate keys.

These containers provide efficient search, insertion, and deletion operations, typically with logarithmic time complexity (O(log n)).

## What does a standard container like a verctor or a map do if it does not find the value it is looking for? Does it throw an error or return some value like npos?

Standard containers generally do not throw exceptions when a search operation fails to find a value. Instead, they return a special value—typically an iterator—to indicate that the element was not found.

- **For sequence containers like `std::vector`**: You would typically use the `std::find` algorithm. If the value is not found, `std::find` returns an iterator equal to the container's `end()` iterator.

- **For associative containers like `std::map`**: The `find()` member function is used to search for an element by its key. If the key is not found, `map::find()` returns an iterator to the map's `end()` member.

It's important to note that some member functions for element access can throw exceptions. For example, the `at()` member function of both `std::vector` (for out-of-bounds index access) and `std::map` (if the key is not found) will throw an `std::out_of_range` exception.

The value `npos` (which stands for "no position") is a static member of `std::string` and is used by its member functions (like `find`) to indicate failure, but it is not used by other standard containers.

## What is the simplest way to compare the return of find() to the end iterator?

The simplest way to check if a `find` operation was successful is to compare the returned iterator with the container's `end()` iterator using the inequality operator (`!=`).

- If the returned iterator is **not equal** to the `end()` iterator, the element was found.
- If the returned iterator is **equal** to the `end()` iterator, the element was not found.

This approach is consistent for both `std::find` with sequence containers and the `find()` member function of associative containers.

Here is a common C++ idiom for this check:

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::find
#include <map>

int main() {
    // Example with std::vector
    std::vector<int> my_vector = {10, 20, 30, 40};
    auto it_vec = std::find(my_vector.begin(), my_vector.end(), 30);

    if (it_vec != my_vector.end()) {
        std::cout << "Found 30 in vector." << std::endl;
    } else {
        std::cout << "30 not found in vector." << std::endl;
    }

    // Example with std::map
    std::map<int, std::string> my_map = {{1, "one"}, {2, "two"}};
    auto it_map = my_map.find(1);

    if (it_map != my_map.end()) {
        std::cout << "Found key 1 in map." << std::endl;
    } else {
        std::cout << "Key 1 not found in map." << std::endl;
    }

    return 0;
}
```

## Why do i have to write typename T::iterator?

In C++ templates, you must use the `typename` keyword before a qualified dependent name to tell the compiler that the name refers to a type.

Here's a breakdown:

1.  **Dependent Name**: `T::iterator` is a "dependent name" because its meaning depends on the template parameter `T`. The compiler doesn't know what `T` will be until the template is instantiated (e.g., with `std::vector<int>`).

2.  **Ambiguity**: When the compiler sees `T::iterator`, it can't be sure if `iterator` is a type (like a nested class or typedef) or a static member variable. For example:
    *   If `T` is `std::vector<int>`, then `T::iterator` is a type.
    *   But you could have a class `MyClass` where `iterator` is a static integer: `static int iterator;`.

3.  **The Rule**: To resolve this ambiguity, the C++ standard requires you to explicitly tell the compiler that a dependent name is a type by prefixing it with `typename`. Without it, the compiler assumes the name refers to a value (like a variable or function), which would cause a parsing error when it's used as a return type.

In short, `typename T::iterator` tells the compiler: "Trust me, for whatever type `T` is eventually used, `T::iterator` will be a type name."

## What is really the difference between an array container and a vector container?

Of course. The main difference between `std::vector` and `std::array` lies in how they manage their size and memory.

Here’s a breakdown:

### `std::vector`
*   **Dynamic Size**: A `std::vector` is a dynamic, resizable array. You can add or remove elements at runtime using functions like `push_back()` and `pop_back()`, and its size can grow or shrink as needed.
*   **Memory Allocation**: It manages its elements on the **heap**. This allows for flexibility but introduces a small performance overhead for memory allocation and potential reallocations if the vector grows beyond its current capacity.
*   **Use Case**: Use `std::vector` when you don't know the number of elements at compile time, or when the number of elements needs to change during the program's execution.

### `std::array`
*   **Fixed Size**: A `std::array` has a fixed size that must be known at **compile time**. The size is part of its type (e.g., `std::array<int, 5>` and `std::array<int, 10>` are different types). You cannot change its size after it's created.
*   **Memory Allocation**: It is an aggregate type that is typically allocated on the **stack**, just like a C-style array (`int arr[10];`). This makes it very fast, with no dynamic memory allocation overhead.
*   **Use Case**: Use `std::array` when you know the exact number of elements you need at compile time and that number will not change. It's essentially a safer, more modern replacement for C-style arrays, as it provides bounds checking (`at()`) and iterators.

### Summary Table

| Feature | `std::vector` | `std::array` |
| :--- | :--- | :--- |
| **Size** | Dynamic (run-time) | Fixed (compile-time) |
| **Memory** | Heap-allocated | Stack-allocated (usually) |
| **Flexibility** | High (can resize) | Low (size is constant) |
| **Performance** | Minor overhead for allocation | Slightly faster, no allocation overhead |


## Can you tell me more about "value_type" thing? What is it? Is it a function somewhere?

Of course. `value_type` is not a function; it's a **member typedef** (a type alias) that is defined inside every standard C++ container class.

Think of it as a public label inside the container that tells you what type of elements are stored within it.

### Key Points:

1.  **It's a Nested Type:** `value_type` is defined within the scope of the container class. That's why you access it with the `::` scope resolution operator, like `std::vector<int>::value_type`.

2.  **It Represents the Element Type:**
    *   For a `std::vector<int>`, its `value_type` is `int`.
    *   For a `std::list<std::string>`, its `value_type` is `std::string`.
    *   For a `std::map<int, double>`, its `value_type` is `std::pair<const int, double>`.

3.  **Purpose: Generic Programming:** The main reason `value_type` exists is to allow you to write generic code, especially in templates. When you write a function like `template <typename T>`, you don't know what `T` will be. But you can rely on the fact that if `T` is a standard container, it will have a `T::value_type` that you can use.

### Simplified Example

Imagine you were creating your own simple container. You would define `value_type` inside it like this:

```cpp
template <typename Element>
class MySimpleVector {
public:
    // This is the member typedef. It gives a public name
    // to the template parameter 'Element'.
    typedef Element value_type;

    // ... other functions like push_back, begin, end ...
private:
    Element* data;
};

// Now, you can use it:
MySimpleVector<int>::value_type my_integer; // This is the same as writing "int my_integer;"
MySimpleVector<char>::value_type my_char;   // This is the same as writing "char my_char;"
```

In your `easyfind` function, `typename T::value_type` allows your code to ask the container `T`, "What is the type of the elements you are holding?" This is what makes the C++98 type-checking trick possible.


## Iterator

Is a class or a struct inside the container template, its like a smart pointer that knows hw to nagigate the specific container

## How come is the esxception is not a reference here then i can't print the correct what()?

That's an excellent observation, and it gets to a very important concept in C++ called **object slicing**.

You are correct. If you catch the exception by value instead of by reference, you will likely get the wrong output from `what()`.

Here’s why:

### Catching by Value (The Problem)

```cpp
catch (std::exception e) // Catching by value
{
    std::cout << e.what() << std::endl;
}
```

1.  **The Throw:** Your code throws a `NotFoundException`.
2.  **The Catch:** The `catch` block is looking for a `std::exception`. Since `NotFoundException` *is a* `std::exception` (through inheritance), it matches.
3.  **The Slice:** Because you are catching by value, the compiler creates a **new** object `e` of type `std::exception` by *copying* the `std::exception` part of your `NotFoundException`. The `NotFoundException` part of the object is "sliced off" and discarded.
4.  **The Call:** You are now left with a plain `std::exception` object. When you call `e.what()`, you are calling `std::exception::what()`, not the overridden version in your `NotFoundException`.

### Catching by Reference (The Solution)

```cpp
catch (const std::exception& e) // Catching by reference (const is best practice)
{
    std::cout << e.what() << std::endl;
}
```

1.  **No Copying:** When you catch by reference, no new object is created. The reference `e` binds directly to the original `NotFoundException` object that was thrown.
2.  **Polymorphism Works:** The object's true type (`NotFoundException`) is preserved. Because `what()` is a `virtual` function, the call `e.what()` correctly uses the object's actual type to find and execute `NotFoundException::what()`.

In summary: **Always catch exceptions by reference (preferably `const` reference)** to prevent object slicing and to ensure that polymorphism works as expected.

## QUESTION