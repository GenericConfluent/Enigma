#include <iostream>
#include <string>
#include "EnigmaMachine.hpp"

int main(){
  EnigmaMachine enigma;

  std::string testcipher = enigma.cipher("test");
  std::cout << "Test Cipher: " << testcipher << "\n";
  std::cout << "Test Decipher: " << enigma.decipher(testcipher) << "\n";
}
