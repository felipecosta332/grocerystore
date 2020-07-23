#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
  std::string line;
  std::cout << "ENTRADA:" << std::endl;
  getline(std::cin, line);
  std::cout << "SAÍDA: " << line << std::endl;
  if (line == "teste") {
    std::cout << "igual" << std::endl;
  } else {
    std::cout << "diferente" << std::endl;
  }
  return 0;
}