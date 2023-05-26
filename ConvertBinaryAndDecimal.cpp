// 20019829 Jamie Douglas
//
#include <iostream>
#include <string>
using namespace std;

string input;
int total, i;
bool valid;

void decimal(); //convert from decimal to binary
void binary(); //convert from binary to decimal

int main() {
  //User Input
  cout << "Enter a number: ";
  cin >> input;

  //Check all characters for invalid characters
  total = input.length();
  i = 0;
  valid = true;
  while (i != total) {
    if ((input[i] < '0') || (input[i] > '9')) {
      valid = false;
    }
    if (valid == false) {
      cout << "This is not a valid number.\n";
      i = total - 1;
    }
    i++;
  }

  if (valid == true) {
    if (input[0] == '0') {
      binary();
    } else {
      decimal();
    }
  }
}


void binary() {
  int exponent, output;
  //Check for valid binary number
  for (i = 0; i < total; i++) {
    if (input[i] >= '2') {
      cout << "This is not a valid binary number.\n";
      valid = false;
    }
    if (i == 9) {
      cout << "This binary number has more than 9 binary digits.\n";
      valid = false;
    }
    if (valid == false) {
      i = total;
    }
  }

  //If valid, convert to decimal
  if (valid == true) {
    exponent = 1;
    output = 0;
    for (i = total - 1; i >= 0; i--) {
      output = (input[i] - 48) * exponent + output;
      exponent = exponent * 2;
    }
    cout << "Converting binary to decimal. The result is " << output << endl;
  }
}


void decimal() {
  int num;
  string output, tempstring;

  //Convert string to int
  i = 0;
  num = 0;
  while (i != total) {
    num = num * 10 + input[i] - 48;
    i++;
  }
  if ((num > 255) || (num < 0)) {
    cout << "This decimal number is outside the range 0 to 255\n";
  } else {

    //Convert decimal to binary
    for (i = 0; i < 8; i++) {
      input[i] = num % 2;
      num = num / 2;
    }

    //Convert binary to string
    output = "";
    for (i = 0; i < 8; i++) {
      tempstring = input[i] + 48;
      output = tempstring + output;
      if (i == 3) {
        output = " " + output;
      }
    }
    cout << "Converting decimal to binary. The result is " << output << endl;
  }
}
