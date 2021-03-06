#include <iostream>
#include <fstream>

#include "dtypes.h"
#include "mat5writer.h"

using namespace std;

int main(int argc, char **argv)
{
  cout << Matlab_Util::mat5writer::get_header() << "\n";

   string filename = "Test.mat";
    {
        ofstream ofs(filename, std::ios::out);
        ofs << Matlab_Util::mat5writer::get_header();
        ofs << Matlab_Util::mat5writer::add(static_cast<u8>(127));
        ofs << Matlab_Util::mat5writer::add(static_cast<u16>(32933));
        ofs << Matlab_Util::mat5writer::add(static_cast<u32>(0xABCD1234ul));
        ofs << Matlab_Util::mat5writer::add(static_cast<u64>(0xFE98ABCD12345678ull));
        //ofs << Matlab_Util::mat5writer::DataElement(Matlab_Util::DataTypes::miMATRIX,filename) << "\n";
        ofs.close();
    }

	return 0;
}
