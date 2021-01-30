//
// Created by devel on 2021-01-29.
//

#ifndef CPPTUTORIAL_MYSTRING_H
#define CPPTUTORIAL_MYSTRING_H


class MyString {
private:
  char* m_pszData;
  int m_nLength;

public:
  // Constructors and Destructor
  MyString();
  explicit MyString(const char *pszParam);
  MyString(MyString &rhs);
  MyString(MyString &&rhs) noexcept ;
  ~MyString();

  // Operators
  MyString& operator=(const MyString &rhs);
  MyString operator+(const MyString &rhs);
  MyString& operator+=(const MyString &rhs);
  char& operator[](int nIndex);
  char operator[](int nIndex) const;
  int operator==(const MyString &rhs);
  int operator!=(const MyString &rhs);
  explicit operator char*() { return m_pszData; }

  // Methods
  int setString(const char* pszParam);
  const char* getString() const;
  int getLength() const;
  int append(const char* pszParam);
  void release();
};


#endif //CPPTUTORIAL_MYSTRING_H
