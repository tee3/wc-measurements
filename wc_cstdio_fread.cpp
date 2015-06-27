#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "wc.hpp"

long long int
wc_cstdio_fread_files (char * filenames_begin [],
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

      if (std::fseek (fp,0,SEEK_END) != 0)
      {
         std::cerr << "error: could not seek to end of " << *filenames_i << "\n";
         std::exit (1);
      }
      std::size_t size = ftell (fp);
      if (std::fseek (fp,0,SEEK_SET) != 0)
      {
         std::cerr << "error: could not seek to beginning of " << *filenames_i << "\n";
         std::exit (1);
      }

      auto data =
         static_cast<char *> (std::malloc (size * sizeof (char)));
      if (fread (data,sizeof (char),size,fp) != size)
      {
         std::cerr << "error: could not read all data from " << *filenames_i << "\n";
         std::exit (1);
      }

      wordstate perfile;

      for (auto data_i = data,
              data_end = data + size;
           data_i != data_end;
           ++data_i)
      {
         perfile.update (*data_i);
      }

#if 0
      std::cout << perfile.count () << "\t" << *filenames_i << "\n";
#endif

      total += perfile.count ();

      std::free (data);
      std::fclose (fp);
   }

   return total;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
