//
// Created by devel on 2021-01-30.
//

#include "MyStringEx.h"
#include <cstring>

int MyStringEx::find(const char *pszParam) {
  if (pszParam == nullptr || getString() == nullptr)
    return -1;

  const char *pszResult = strstr(getString(), pszParam);

  if (pszResult == nullptr)
    return -1;
  else
    return pszResult - getString();
}

void MyStringEx::onSetString(char *pszData, int nLength) {
  if(strcmp(pszData, "개새끼") == 0)
    strcpy(pszData, "착한애");
}
