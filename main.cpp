#include <iostream>
#include <string>
#include "EnigmaMachine.hpp"

int main(){
  EnigmaMachine enigma;

  std::string test = "test";

  test = enigma.cipher(test);

  std::cout << test << "\n";
}
