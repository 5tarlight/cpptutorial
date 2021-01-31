//
// Created by devel on 2021-01-30.
//

#ifndef CPPTUTORIAL_MYSTRINGEX_H
#define CPPTUTORIAL_MYSTRINGEX_H

#include "MyString.h"

#pragma once

class MyStringEx : public MyString {
public:
  using MyString::MyString;
  int find(const char *pszParam);
  void onSetString(char *pszData, int nLength) override;
};


#endif //CPPTUTORIAL_MYSTRINGEX_H
