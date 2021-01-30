#include "stdafx.h"
#include "MyString.h"

int main() {
  MyString hello("Hello"), world(" World");

  cout << (hello + world).getString() << endl;

  return 0;
}
