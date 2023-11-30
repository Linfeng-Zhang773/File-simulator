#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//Files we are testing:

//------------------------------------------------------------------------------

using namespace std;



bool my_test(bool debug=false)
{
  return true;
}


//Lord help me! 
const bool debug = false;

TEST(MY_TEST, MyTest)
{
  bool success = my_test(debug);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}