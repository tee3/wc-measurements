#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "wc.hpp"

long long int
wc_iostream_operator_files (char * filenames_begin [],
                            char * filenames_end [])
{
   long long int total = 0;

   for (auto filenames_i = filenames_begin;
        filenames_i != filenames_end;
        ++filenames_i)
   {
      std::ifstream is (*filenames_i);
      if (!is.good ())
      {
         std::cerr << "error: could not open " << *filenames_i << "\n";
         std::exit (1);
      }

      wordstate perfile;

      char c;
      while (is >> std::noskipws >> c)
      {
         perfile.update (c);
      }

      if (!is.eof ())
      {
         std::cerr << "error: did not get to the end of file " << *filenames_i << "\n";
         std::exit (1);
      }

#if 0
      std::cout << perfile.count () << "\t" << *filenames_i << "\n";
#endif

      total += perfile.count ();
   }

   return total;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
