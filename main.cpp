#include <iostream>
#include <string>
#include <vector>

void assert_allowable_char(char ch) {
  if (ch < 'A' || ch > 'Z') {
    std::cout
        << "Input text can only contain Uppercase alphabetic characters (A-Z)"
        << std::endl;
    std::exit(-1);
  }
}

// NOTE: This is a really sucky enigma machine beause it doesn't accurately
// reflect how a real machine would behave: the rotors don't turn (the same
// letters in the input will be the same letters in output) and can each only
// encode a shift cipher, in addition there is no plugboard.
std::string enigma(std::string input, std::vector<unsigned> rotors,
                   int should_decode) {
  if (should_decode)
    std::transform(rotors.begin(), rotors.end(), rotors.begin(),
                   [](auto rotor) { return 26 - (rotor % 26); });

  std::string coded;
  for (auto i = 0; i < input.size(); ++i) {
    char ch = input[i];
    assert_allowable_char(ch);
    ch -= 'A';

    for (const unsigned &rotor : rotors)
      ch = (ch + rotor) % 26;

    // At least there is a reflector.
    for (unsigned j = rotors.size(); --j;)
      ch = (ch + rotors[j]) % 26;

    coded.push_back(ch + 'A');
  }
  return coded;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t rotor_count;
  std::cout << "How many rotors: ";
  std::cin >> rotor_count;

  std::vector<unsigned> rotors(rotor_count);
  std::cout << "Enter a space separated list of positive rotor vals on row "
               "below (i.e. 4 2 5): "
            << std::endl;
  for (auto &rotor : rotors)
    std::cin >> rotor;

  std::string input;
  std::cout << "Enter machine input: ";
  std::cin >> input;

  std::transform(input.begin(), input.end(), input.begin(), ::toupper);

  int should_decode;
  std::cout << "Encode (Enter 0) or Decode (Enter 1): ";
  std::cin >> should_decode;

  std::string output = enigma(input, rotors, should_decode);
  std::cout << output << std::endl;
}
