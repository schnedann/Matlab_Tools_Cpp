#ifndef MAT5WRITER_H
#define MAT5WRITER_H

#include <string>

#include "dtypes.h"

namespace Matlab_Util
{

class mat5writer
{
public:
  mat5writer();
  ~mat5writer();

  static std::string get_header();

};

}

#endif // MAT5WRITER_H
