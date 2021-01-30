#include "stdafx.h"
#include "MyString.h"

int main() {
  MyString strData, strTest;
  strData.setString("Hello");
  strTest.setString("World");

  MyString strNewData(strData);
  cout << strNewData.getString() << endl;

  strNewData = strTest;
  cout << strNewData.getString() << endl;

  return 0;
}
