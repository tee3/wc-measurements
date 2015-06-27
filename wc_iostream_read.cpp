#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "wc.hpp"

long long int
wc_iostream_read_files (char * filenames_begin [],
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

      is.seekg (0,std::ios_base::seekdir::end);
      if (!is.good ())
      {
         std::cerr << "error: could not seek to end of " << *filenames_i << "\n";
         std::exit (1);
      }
      auto size = is.tellg ();
      is.seekg (0,std::ios_base::seekdir::beg);
      if (!is.good ())
      {
         std::cerr << "error: could not seek to beginning of " << *filenames_i << "\n";
         std::exit (1);
      }

      std::vector<char> data (size);

      is.read (data.data (),data.size ());
#if 0
      if (!is.eof ())
      {
         std::cerr << "error: could not read all data from " << *filenames_i << "\n";
         std::exit (1);
      }
#endif

      wordstate perfile;

      for (const auto c : data)
      {
         perfile.update (c);
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
