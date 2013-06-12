#ifndef VECTOR_HPP_ZARATH
#define VECTOR_HPP_ZARATH

#include <iostream>
#include <iomanip>
#include <cstdint>

extern "C"
{
	void ADD_V(double* src1, double* src2, double* dist, uint32_t n);
	void SUB_V(double* src1, double* src2, double* dist, uint32_t n);	
}



namespace zarath
{
  template<class Numeric, unsigned int dim>
  class Vector
  { 
  public:
    Numeric val[dim];

    Vector(){}

    Vector(const Vector& v)
    {
      for(unsigned int i = 0; i < dim; ++i)
	val[i] = v.val[i];
    }

    Vector& operator+=(const Vector& v)
    {
      for(unsigned int i = 0; i < dim; ++i)
	val[i] += v.val[i];
      return *this;
    }

    Vector& operator-()
    {
      for(unsigned int i = 0; i < dim; ++i)
	val[i] = -val[i];
      return *this;
    }

    Vector& operator-=(const Vector& v)
    {
      for(unsigned int i = 0; i < dim; ++i)
	val[i] -= v.val[i];
      return *this;
    }

    Vector& operator*=(const Numeric &s)
    {
      for(int i = 0; i < dim; ++i)
	{
	  val[i] *= s;
	}
      return *this;
    }

    Vector& operator=(const Vector& v)
    {
      for(unsigned int i = 0; i < dim; ++i)
	val[i] = v.val[i];
      return *this;
    }

    bool operator==(const Vector& v)const
    {
      for(int i = 0; i < dim; ++i)
	if(val[i] != v.val[i])
	  return false;
      return true;
    }

    bool operator!=(const Vector& v)const
    {
      for(int i = 0; i < dim; ++i)
	if(val[i] != v.val[i])
	  return true;
      return false;
    }

    Numeric& operator[](unsigned int index)
    {
      return val[index];
    }

    void SetVal(unsigned int index, Numeric val)
    {
      this->val[index] = val;
    }
  };

  template<class Numeric, unsigned int dim>
  Numeric norm(const Vector<Numeric, dim>& v)
  {
    Numeric ans(0);
    for(int i = 0; i < dim; ++i)
      ans += v.val[i]*v.val[i];
    return ans;
  }
  
  template<class Numeric, unsigned int dim>
  std::ostream& operator<<(std::ostream& dist, Vector<Numeric, dim>& v)
  {
    for(unsigned int i = 0; i < dim; ++i)
      dist << std::setprecision(8) << std::setw(16) << std::right <<  v[i];
    return dist;
  }
}

#endif
