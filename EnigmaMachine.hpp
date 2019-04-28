#pragma once
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Rotor{
public:
  Rotor();
  void initRotor(int init);
  char shift(char character, bool first);
private:
  std::multimap<char, char> rotor;
  char reflectMap(char character);
  void rotate();
};

class EnigmaMachine{
public:
  EnigmaMachine();
  std::string cipher(std::string text);
  std::string decipher(std::string text);
private:
  Rotor r1;
  Rotor r2;
  Rotor r3;
};
