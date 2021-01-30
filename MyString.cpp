//
// Created by devel on 2021-01-29.
//

#include "MyString.h"
#include <cstring>

MyString::MyString()
  : m_pszData(nullptr)
  , m_nLength(0)
{}

MyString::MyString(MyString &rhs)
  : m_pszData(rhs.m_pszData)
  , m_nLength(rhs.m_nLength)
{}

MyString &MyString::operator=(const MyString &rhs) {
  strcpy(m_pszData, rhs.m_pszData);
  m_nLength = rhs.m_nLength;

  return *this;
}

int MyString::setString(const char *pszParam) {
  release();

  if (pszParam == nullptr) return 0;

  int length = strlen(pszParam);

  if (length == 0) return 0;

  m_pszData = new char[length + 1];
  strcpy(m_pszData, pszParam);
  m_nLength = length;

  return m_nLength;
}

const char *MyString::getString() const {
  return m_pszData;
}

void MyString::release() {
  if (m_pszData != nullptr)
    delete[] m_pszData;

  m_pszData = nullptr;
  m_nLength = 0;
}

MyString::~MyString() {
  release();
}
