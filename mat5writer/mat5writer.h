#ifndef MAT5WRITER_H
#define MAT5WRITER_H

#include <string>
#include <array>

#include "dtypes.h"

namespace Matlab_Util
{

enum class DataTypes:u32{
  miINT8   = 1,
  miUINT8  = 2,
  miINT16  = 3,
  miUINT16 = 4,
  miINT32  = 5,
  miUINT32 = 6,
  miSINGLE = 7,
  miDOUBLE = 9,
  miINT64  = 12,
  miUINT64 = 13,
  miMATRIX = 14,
  miCOMPRESSED = 15,
  miUTF8   = 16,
  miUTF16  = 17,
  miUTF32  = 18
};

static const std::array<s32,(static_cast<u32>(DataTypes::miUTF32)+1)> DataTypeSizes = {
  -1, 1, 1, 2,
   2, 4, 4, 4,
  -1, 8,-1,-1,
   8, 8,-2,-2,
  -2,-2,-2
};

class mat5writer
{
public:
  mat5writer();
  ~mat5writer();

  static std::string get_header();
  static std::string DataElement(Matlab_Util::DataTypes const& datatype, std::string const& data);
  static std::string shortDataElement(Matlab_Util::DataTypes const& datatype, std::string const& data);

  static std::string add(u8 const& _x);

};

}

#endif // MAT5WRITER_H
