#include <sstream>

#include "mat5writer.h"

using namespace std;

Matlab_Util::mat5writer::mat5writer()
{
}

Matlab_Util::mat5writer::~mat5writer()
{
}

string Matlab_Util::mat5writer::get_header(){
  string str(128,' ');

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

  str.replace(str.size()-HeaderFlagFields.size()-1,HeaderFlagFields.size(),HeaderFlagFields);

  return str;
}
