#include <iostream>
#include <string>
#include <math.h>

int SumCharNumOfParam1(const std::string& param1){
  int charvalsum = 0;
  
  for (int counter = 0; counter <= static_cast<int>(param1.size()); counter++) {
      charvalsum += param1[counter];
    }
  
  return charvalsum;
}

int CalcKey(char* argcont) {
  std::string stringofparam1=argcont;
  char firstletterofparam1 = *(argcont);
  int param1charvalsum = SumCharNumOfParam1(stringofparam1);
  int key = param1charvalsum ^ firstletterofparam1 * 3;
  std::cout << "The calculated checksum is: " << param1charvalsum << std::endl;
  std::cout << "The calculated key is: " << key << std::endl;
  return key;
}


//commandnumber is the number of commands that is sent into the program
//where the name of the program is one and the rest are the input arguments

//looped through var1 and printed each index to see its content.
//changed it to argcont as it seems to be an array that holds the name of the
//program and the content of the arguments.

//step 3 point 2: change to bool??
int main(int commandnumber, char *argcont[]) {
  if (commandnumber == 3) {
    std::string programname{argcont[0]};
    int prognamelength = programname.size();
    int param2toint = std::atoi(argcont[2]);

    if (CalcKey(argcont[1]) << (prognamelength & 0x1f) == param2toint) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Invalid or wrong input, parameter 1 should be a name as a string"<< std::endl;
      std::cout << "while paramter 2 should be a number as a string." << std::endl;
    }
  }
  else {
    std::cout << "Invalid input, should consist of the calling of the program"<< std::endl;
    std::cout << "and two parameters where parameter 1 should be a name as a string"<< std::endl;
    std::cout << "while paramter 2 should be a number as a string." << std::endl;
  }
}