#ifndef wc_hpp_
#define wc_hpp_

#include <cctype>

class wordstate
{
public:
   enum class machine
   {
      not_in_word,
      in_word
   };

public:
   void
   update (char c)
   {
      if ((ws_ == wordstate::machine::not_in_word) &&
          !std::isspace (c))
      {
         ws_ = wordstate::machine::in_word;

         ++count_;
      }
      else if ((ws_ == wordstate::machine::in_word) &&
               std::isspace (c))
      {
         ws_ = wordstate::machine::not_in_word;
      }
   }

   auto
   count () const
   {
      return count_;
   }

private:
   machine ws_ = machine::not_in_word;
   long long int count_ = 0;
};

long long int
wc_cstdio_fgetc_files (char * filenames_begin [],
                       char * filenames_end []);
long long int
wc_cstdio_fread_files (char * filenames_begin [],
                       char * filenames_end []);
long long int
wc_iostream_operator_files (char * filenames_begin [],
                            char * filenames_end []);
long long int
wc_iostream_read_files (char * filenames_begin [],
                        char * filenames_end []);
long long int
wc_os_mmap_files (char * filenames_begin [],
                  char * filenames_end []);
long long int
wc_os_read_files (char * filenames_begin [],
                  char * filenames_end []);

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:

#endif
