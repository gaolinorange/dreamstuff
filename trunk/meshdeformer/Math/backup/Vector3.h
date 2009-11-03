#ifndef VECTOR3_H
#define VECTOR3_H

#include "common.h"
#include <string>


class Vector3
{
 public:
  Vector3(float x,float y,float z);
  ~Vector3();
 public:
  Vector3(const Vector3 & vec);
  float x();
  float y();
  float z();

  Vector3 operator+(const Vector3 & rhs) const;
  Vector3& operator-(const Vector3 & rhs) const;
  Vector3& operator*(float s) const;
  Vector3& operator/(float s) const;

  //uniary operator
  Vector3& operator-() const;

  float length() const;

  bool operator<(const Vector3 & ) const;
  bool operator>(const Vector3 & ) const;
  bool operator<=(const Vector3 & ) const;
  bool operator>=(const Vector3 & ) const;
  bool operator==(const Vector3 & ) const;
  bool operator!=(const Vector3 & ) const;

  Vector3& operator=(const Vector3 & ) const;
  Vector3& operator-=(const Vector3& ) const;
  Vector3& operator+=(const Vector3& ) const;
  
 public://Helper functions
  std::string & toString() const;
  
 private:
  float _x,_y,_z;
};

#endif
