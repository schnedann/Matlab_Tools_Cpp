#include <sstream>

#include "mat5writer.h"

using namespace std;

Matlab_Util::mat5writer::mat5writer()
{
}

Matlab_Util::mat5writer::~mat5writer()
{
}

/**
 * @brief Generate a mat5 compatible Header String
 * @return 128 char String
 */
string Matlab_Util::mat5writer::get_header(){
  string str(128-1,' ');

  string HeaderTextField = "MATLAB 5.0 MAT-file, Mat5 Writer by Danny Schneider, Created on: ";
  HeaderTextField += __DATE__;
  HeaderTextField += " , ";
  //time = string(__TIME__).substr(0,8);
  HeaderTextField += __TIME__;

  str.replace(0,HeaderTextField.size()-1,HeaderTextField);

  string HeaderFlagFields(4,'\0');
  HeaderFlagFields[0] = 0x00u;
  HeaderFlagFields[1] = 0x01u;
  HeaderFlagFields[2] = 'I';
  HeaderFlagFields[3] = 'M';

  str.replace(str.size()-HeaderFlagFields.size(),HeaderFlagFields.size(),HeaderFlagFields);

  return str;
}

/**
 * @brief Data Element Envelop for Data
 * @param datatype
 * @param data
 * @return
 */
string Matlab_Util::mat5writer::DataElement(Matlab_Util::DataTypes const& datatype, string const& data){
  stringstream ss;
  s32 dts = DataTypeSizes[static_cast<s32>(datatype)];
  if((0<dts) && (4>=dts)){
    ss << shortDataElement(datatype,data);
  }else{
    stringstream ss;
    string header(8-1,'\0');

    {
      u32 dt = static_cast<u32>(datatype);
      char* ptr = reinterpret_cast<char*>(&dt);
      header.replace(0,4,ptr,4);
    }
    {
      u32 bytes = data.size();
      char* ptr = reinterpret_cast<char*>(&bytes);
      header.replace(4,4,ptr,4);
    }

    ss << header;
    ss << data;
  }

  return ss.str();
}

string Matlab_Util::mat5writer::shortDataElement(Matlab_Util::DataTypes const& datatype, string const& data){
  stringstream ss;
  string header(4-1,'\0');

  {
    u16 dt = static_cast<u16>(datatype);
    char* ptr = reinterpret_cast<char*>(&dt);
    header.replace(2,2,ptr,2);
  }
  {
    u16 bytes = data.size();
    char* ptr = reinterpret_cast<char*>(&bytes);
    header.replace(0,2,ptr,2);
  }

  ss << header;
  ss << data;

  return ss.str();
}

template<typename T, Matlab_Util::DataTypes dT> string genericadd(T const& _x){
  Matlab_Util::DataTypes dt = dT;
  u32 bytes = Matlab_Util::DataTypeSizes[static_cast<s32>(dt)];
  string data(4,'\0');

  for(u32 ii=0; ii<bytes; ++ii){
    data[ii] = (reinterpret_cast<char const *>(&_x))[ii];
  }
  return Matlab_Util::mat5writer::DataElement(dt,data);
}

string Matlab_Util::mat5writer::add(u8 const& _x){
  DataTypes dt = DataTypes::miUINT8;
  u32 bytes = DataTypeSizes[static_cast<s32>(dt)];
  string data(4,'\0');

  for(u32 ii=0; ii<bytes; ++ii){
    data[ii] = (reinterpret_cast<char const *>(&_x))[ii];
  }
  return DataElement(dt,data);
}

string Matlab_Util::mat5writer::add(u16 const& _x){
  return genericadd<u16,Matlab_Util::DataTypes::miUINT16>(_x);
}
