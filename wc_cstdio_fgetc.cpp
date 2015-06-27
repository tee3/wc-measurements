#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "wc.hpp"

long long int
wc_cstdio_fgetc_files (char * filenames_begin [],
                       char * filenames_end [])
{
   long long int total = 0;

   for (auto filenames_i = filenames_begin;
        filenames_i != filenames_end;
        ++filenames_i)
   {
      auto fp = std::fopen (*filenames_i,"r");
      if (!fp)
      {
         std::cerr << "error: could not open " << *filenames_i << "\n";
         std::exit (1);
      }

      wordstate perfile;

      int c;
      do
      {
         c = std::fgetc (fp);
         perfile.update (c);
      } while (c != EOF);

#if 0
      std::cout << perfile.count () << "\t" << *filenames_i << "\n";
#endif

      total += perfile.count ();

      std::fclose (fp);
   }

   return total;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
