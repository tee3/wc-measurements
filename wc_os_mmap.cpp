#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "wc.hpp"

long long int
wc_os_mmap_files (char * filenames_begin [],
                  char * filenames_end [])
{
   long long int total = 0;

   for (auto filenames_i = filenames_begin;
        filenames_i != filenames_end;
        ++filenames_i)
   {
      auto fd = open (*filenames_i,O_RDONLY);
      if (fd < 0)
      {
         std::cerr << "error: could not open " << *filenames_i << "\n";
         std::exit (1);
      }

      struct stat s;
      fstat (fd,&s);
      auto size = s.st_size;

      auto data =
         static_cast<char *> (mmap (0,
                                    size,
                                    PROT_READ,MAP_FILE | MAP_PRIVATE,
                                    fd,
                                    0));
      if (data == MAP_FAILED)
      {
         std::cerr << "error: could not mmap " << *filenames_i << "\n";
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

      munmap (data,-1);
      close (fd);
   }

   return total;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
