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
  char shift(char character);
private:
  std::map<char, char> rotor;
  void rotate();
};

class EnigmaMachine{
public:
  EnigmaMachine();
  std::string cipher(std::string text);
private:
  Rotor r1;
  Rotor r2;
  Rotor r3;
};
