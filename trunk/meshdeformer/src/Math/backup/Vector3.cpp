#include "Vector3.h"

Vector3::Vector3(float x,float y,float z)
{
  _x = x; _y = y; _z = z;
}

Vector3::Vector3(const Vector3 & vec)
{
  _x = vec._x;
  _y = vec._y;
  _z = vec._z;
}

float Vector3::x()
{
  return _x;
}

float Vector3::y()
{
  return _y;
}

float Vector3::z()
{
  return _z;
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
  return Vector3(this->x()+rhs.x(),this->y()+rhs.y(),_z+rhs.z());
}

Vector3& Vector3::operator-(const Vector3& rhs) const
{
  return Vector3(_x-rhs.x(),_y-rhs.y(),_z-rhs.z());
}

Vector3& Vector3::operator*(float s) const
{
  return Vector3(_x*s,_y*s,_z*s);
}

Vector3& Vector3::operator/(float s) const
{
  return Vector3(_x*1.0/s,_y*1.0/s,_z*1.0/s);
}

Vector3& Vector3::operator-() const
{
  return Vector3(-1.0 * _x,-1.0 * _y,-1.0 * _z);
}

float Vector3::length() const
{
  return (_x*_x + _y*_y + _z*_z);
}


bool Vector3::operator<(const Vector3 & rhs) const
{
  return ( (_x < rhs.x() )&&(_y < rhs.y())&&(_z <  rhs.z()));
}

bool Vector3::operator>(const Vector3 & rhs) const
{
  return ( (_x>rhs.x()) && (_y>rhs.y()) && (_z>rhs.z()));
}

bool Vector3::operator<=(const Vector3 & rhs) const
{
  return ( (_x <= rhs.x() )&&(_y <= rhs.y())&&(_z <=  rhs.z()));
}

bool Vector3::operator>=(const Vector3 & rhs) const
{
  return ( (_x>=rhs.x()) && (_y>=rhs.y()) && (_z>=rhs.z()));
}

bool Vector3::operator==(const Vector3 & rhs) const
{
  return ( (fabs(_x-rhs.x()) < EPISLON) &&
	   (fabs(_y-rhs.y()) < EPISLON) &&
	   (fabs(_z-rhs.z()) < EPISLON)
	   );
}

bool Vector3::operator!=(const Vector3 & rhs) const
{
  return !( (*this)==rhs);
}


Vector3& Vector3::operator=(const Vector3 & rhs) const
{
  _x = rhs.x();
  _y = rhs.y();
  _z = rhs.z();
  return (*this);
}

Vector3& Vector3::operator-=(const Vector3& rhs) const
{
  _x -= rhs.x();
  _y -= rhs.y();
  _z -= rhs.z();
  return (*this);
}

Vector3& Vector3::operator+=(const Vector3& rhs) const
{
  _x += rhs.x();
  _y += rhs.y();
  _z += rhs.z();
  return (*this);
}



//Helper functions
std::string & Vector3::toString() const
{

  //todo
  return "";
}
