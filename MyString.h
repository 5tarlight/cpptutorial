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
  MyString();
  MyString(MyString &rhs);
  ~MyString();

  MyString& operator=(const MyString &rhs);

  int setString(const char* pszParam);
  const char* getString() const;
  void release();
};


#endif //CPPTUTORIAL_MYSTRING_H
