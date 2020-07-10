#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void test(){
  std::cout << "before" << std::endl;
  std::cout << "after" << std::endl;
}

int main() {
  int test;
  char letter;
  std::string line;
  std::stringstream string;
  std::ifstream reader("./files/test.txt", std::ios::in);
  // reader >> line;
  reader >> test;
  // std::cout << reader.is_open() << std::endl;
  // std::cout << true << std::endl;
  // std::cout << false << std::endl;
  // std::cout << line << std::endl;
  std::cout << test << std::endl;
  reader >> letter;
  std::cout << letter << std::endl;
  reader.close();
  return 0;
}