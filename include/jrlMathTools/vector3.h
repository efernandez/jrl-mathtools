/*! This is a very fast and simple implementation
 * of a 3D vector class of double.
 * 
 * (c) Olivier Stasse and Florent Lamiraux, JRL, CNRS-AIST, ISRI, 2007
 */

#ifndef JRLMATHTOOLS_VECTOR3_H
#define JRLMATHTOOLS_VECTOR3_H

#include <iostream>
#include <cmath>

using namespace std;

namespace jrlMathTools
{
  
  /** 
      \brief Template to handle 3 dimensional vector 
  */
  template <typename T>
    struct Vector3D
    {
      public:
      
      T m_x,m_y,m_z;
      
      /*! Basic constructor: all the field 
	are set to zero. */
      inline Vector3D()
      { m_x= 0.0; m_y=0.0; m_z=0.0;};

      inline Vector3D(const T x, const T y, const T z)
	: m_x(x), m_y(y), m_z(z)
      { };
      
      /*! Assignement operator */
      inline Vector3D<T> operator= (const struct Vector3D<T> &v)
      {
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
	return *this;
      };
	
	
      /*! Unary operator - */
      inline Vector3D<T> operator-()
      {
	return Vector3D<T>(-m_x, -m_y, -m_z);
      };
    
      /*! Array operator */
      inline T& operator[](unsigned i) 
      {
	return ((i==0) ? m_x: (i==1)? m_y:m_z);
      };

      /*! Array operator */
      inline T operator[](unsigned i) const
      {
	return ((i==0) ? m_x: (i==1)? m_y:m_z);
      };

      /*! Array operator */
      inline T& operator()(unsigned i) 
      {
	return ((i==0) ? m_x: (i==1)? m_y:m_z);
      };

      /*! Binary operator == */
      inline bool operator==(const struct Vector3D<T> &v) const
      {
	return ((v.m_x==m_x) &&
		(v.m_y==m_y) && 
		(v.m_z==m_z));
      };
    
      /*! Binary operator + */
      inline Vector3D<T> operator+ (const struct Vector3D<T> &v) const
      {
	Vector3D<T> vr;
	vr.m_x = m_x + v.m_x;
	vr.m_y = m_y + v.m_y;
	vr.m_z = m_z + v.m_z;
	return vr;
      };

      /*! Binary operator - */
      inline Vector3D<T> operator- (const struct Vector3D<T> &v) const
      {
	Vector3D<T> vr;
	vr.m_x = m_x - v.m_x;
	vr.m_y = m_y - v.m_y;
	vr.m_z = m_z - v.m_z;
	return vr;
      };
    
      /*! Binary operator += */
      inline void operator+= (const struct Vector3D<T> &v)
      {
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
      };

      /*! Binary operator -= */
      inline void operator-= (const struct Vector3D<T> &v)
      {
	m_x -= v.m_x;
	m_y -= v.m_y;
	m_z -= v.m_z;
      };

      /*! Binary operator * */
      inline Vector3D<T> operator* (const T& t) const
      {
	Vector3D<T> vr;
	vr.m_x = m_x * t;
	vr.m_y = m_y * t;
	vr.m_z = m_z * t;
	return vr;
      };
    

	  /*! Binary operator * : dot product */
	  inline T operator* (const Vector3D<T>& v) const
	  {
	T tr = m_x * v.m_x;
	tr += (m_y * v.m_y);
	tr += (m_z * v.m_z);
	return tr;
	  }


      /*! Binary operator / */
      inline Vector3D<T> operator/ (const T &t) const
      {
	Vector3D<T> vr;
	vr.m_x = m_x/t;
	vr.m_y = m_y/t;
	vr.m_z = m_z/t;
	return vr;
      };

      /*! Binary operator *= */
      inline void operator*= (const T &t) 
      {
	m_x = m_x*t;
	m_y = m_y*t;
	m_z = m_z*t;
      };
    
      /*! Binary operator /= */
      inline void operator/= (const T &t) 
      {
	m_x = m_x/t;
	m_y = m_y/t;
	m_z = m_z/t;
      };
    
    
      /*! Normalize . */
      inline void normalize()
      {
	T in = static_cast<T> (1/sqrt(m_x*m_x+m_y*m_y+m_z*m_z));
	m_x *= in;
	m_y *= in;
	m_z *= in;
      };

      /*! Get the norm. */
      inline T norm() const
      {
	return static_cast<T>(sqrt(m_x*m_x+m_y*m_y+m_z*m_z));
      };
	  
	  inline bool IsZero() const
	  {
	return ((m_x == 0) && (m_y == 0) && (m_z == 0));
	  }

      /*! Get the norm squared */
      inline T normsquared() const
      {
	return (m_x*m_x+m_y*m_y+m_z*m_z);
      };

      /*! Cross product */
      inline struct Vector3D<T> operator ^ (const struct Vector3D<T>& v2) const
      {
	struct Vector3D<T> vr;
	vr.m_x = m_y*v2.m_z - v2.m_y*m_z;
	vr.m_y = m_z*v2.m_x - v2.m_z*m_x;
	vr.m_z = m_x*v2.m_y - v2.m_x*m_y;
	return vr;
      };
    
      inline friend std::ostream& operator<<(std::ostream &os,Vector3D<T> const &v) 
      {
	os << v.m_x << " " << v.m_y << " " << v.m_z << " ";
	return os;
      };
    };
};

#endif /* _VECTOR3D_PATTERNGENERATOR_JRL_ */
