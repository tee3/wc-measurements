#include <iostream>
#include <cstdlib>

#include <chrono>

#include "wc.hpp"

template<typename F, typename It>
void
measure_and_print (F f,
                   const char * name,
                   It filenames_begin,
                   It filenames_end)
{
   auto duration_begin =
      std::chrono::high_resolution_clock::now ();

   auto total = f (filenames_begin,filenames_end);

   auto duration_end =
      std::chrono::high_resolution_clock::now ();
   auto duration =
      duration_end - duration_begin;
   auto duration_us =
      std::chrono::duration_cast<std::chrono::microseconds> (duration).count ();

   std::cout << name << " words: " << total << " (" << (duration_us / 1000.0) << " ms)\n";
}

int
main (int argc, char * argv [])
{
   if (argc < 2)
   {
      std::cerr << "usage: " << argv [0] << " <files>\n";
      std::exit (1);
   }

   measure_and_print (wc_cstdio_fgetc_files,"cstdio_fgetc",argv + 1,argv + argc);
   measure_and_print (wc_cstdio_fread_files,"cstdio_fread",argv + 1,argv + argc);
   measure_and_print (wc_iostream_operator_files,"iostream_operator",argv + 1,argv + argc);
   measure_and_print (wc_iostream_read_files,"iostream_read",argv + 1,argv + argc);
   measure_and_print (wc_os_mmap_files,"os_mmap",argv + 1,argv + argc);
   measure_and_print (wc_os_read_files,"os_read",argv + 1,argv + argc);

   return 0;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
