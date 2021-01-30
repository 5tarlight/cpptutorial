//
// Created by devel on 2021-01-29.
//

#include "MyString.h"
#include <cstring>

MyString::MyString()
    : m_pszData(nullptr), m_nLength(0) {}

MyString::MyString(const char *pszParam)
    : m_pszData(nullptr), m_nLength(0) {
  setString(pszParam);
}

MyString::MyString(MyString &rhs)
    : m_pszData(rhs.m_pszData), m_nLength(rhs.m_nLength) {}

MyString::MyString(MyString &&rhs) noexcept
    : m_pszData(nullptr), m_nLength(0) {
  m_pszData = rhs.m_pszData;
  m_nLength = rhs.m_nLength;

  rhs.m_pszData = nullptr;
  rhs.m_nLength = 0;
}

MyString::~MyString() {
  release();
}

MyString &MyString::operator=(const MyString &rhs) {
  if (this == &rhs) return *this;

  strcpy(m_pszData, rhs.m_pszData);
  m_nLength = rhs.m_nLength;

  return *this;
}

MyString MyString::operator+(const MyString &rhs) {
  MyString str(m_pszData);
  str.append(rhs.m_pszData);

  return str;
}

MyString &MyString::operator+=(const MyString &rhs) {
  append(rhs.getString());

  return *this;
}

char &MyString::operator[](int nIndex) {
  return m_pszData[nIndex];
}

char MyString::operator[](int nIndex) const {
  return m_pszData[nIndex];
}

int MyString::operator==(const MyString &rhs) {
  if (m_pszData != nullptr && rhs.m_pszData!= nullptr) {
    return strcmp(m_pszData, rhs.m_pszData) == 0;
  }

  return 0;
}

int MyString::operator!=(const MyString &rhs) {
  if (m_pszData != nullptr && rhs.m_pszData!= nullptr) {
    return strcmp(m_pszData, rhs.m_pszData) != 0;
  }

  return 1;
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
  delete[] m_pszData;

  m_pszData = nullptr;
  m_nLength = 0;
}

int MyString::getLength() const {
  return m_nLength;
}

int MyString::append(const char *pszParam) {
  if (pszParam == nullptr) return 0;

  int length = strlen(pszParam);
  if (length == 0) return 0;

  if (m_pszData == nullptr) {
    setString(pszParam);
    return m_nLength;
  }

  int currentLen = m_nLength;

  char *pszResult = new char[currentLen + length + 1];
  strcpy(pszResult, "");

  strcat(pszResult, m_pszData);
  strcat(pszResult, pszParam);

  release();
  m_pszData = pszResult;
  m_nLength = currentLen + length;

  return m_nLength;
}
