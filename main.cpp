// C++
#include <iostream>
#include <vector>

// Custom
#include "include/c_vector.hpp"

int main(int argc, char const *argv[])
{
   // Tests
   c_vector<int> c{2, 3, 5};
   for (const auto &i : c)
      std::cout << i << std::endl;

   return EXIT_SUCCESS;
}
