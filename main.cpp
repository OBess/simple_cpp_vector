// C++
#include <iostream>
#include <cassert>

// Custom
#include "include/c_vector.hpp"

int main(int argc, char const *argv[])
{
   // Tests 1 - Default constructor
   {
      c_vector<int> c;
      assert(c.capacity() == 10);
   }

   // Tests 2 - Allocation constructor
   {
      c_vector<int> c(25);
      assert(c.capacity() == 30);
      assert(c.back() == 0);
   }

   // Tests 3 - Initializer list,
   //           CTAD idiom, copy constructor and front/back methods
   {
      c_vector c{25, 4, 6, 21, 65, -34, 65};
      assert(c.front() == 25);
      assert(c.back() == 65);

      c_vector c1(c);
      assert(c.front() == c1.front());
      assert(c.back() == c1.back());
   }

   // Tests 4 - Move semantic and operator[]
   {
      c_vector c({25, 4, 6, 21, 65, -34, 65});
      assert(c[0] == 25);
      assert(c[c.size() - 1] == 65);
   }

   // Tests 5 - operator=, pop_back() and push_back()
   {
      c_vector c = {25, 4, 6, 21, 65, -34, 65};
      c.pop_back();
      c.pop_back();
      c.pop_back();
      c.push_back(45);
      assert(c.back() == 45);
   }

   // Tests 6 - methods resize
   {
      c_vector c{25, 4, 6, 21, 65, -34, 65};
      c.resize(4);
      assert(c.back() == 21);
      c.resize(10, 100);
      assert(c.back() == 100);
      c.resize(12);
      assert(c.back() == 0);
   }

   return EXIT_SUCCESS;
}
