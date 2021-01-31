#include "stdafx.h"
#include "mystring/MyStringEx.h"

int main() {
  MyStringEx strTest;
  strTest.setString("개새끼");

  cout << (char*)strTest << endl;
}
