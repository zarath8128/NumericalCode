#ifndef MATRIX_HPP_ZARATH
#define MATRIX_HPP_ZARATH

#include "Vector.hpp"

namespace zarath
{
  template<class Numeric, int Row, int Column>
  class Matrix
  {
  public:
    Matrix():val(new Numeric*[Row])
    {
      for(int r = 0; r < Row; ++r)
	val[r] = new Numeric[Column];
    }
    Matrix(const Matrix& m)
    {
      Row = m.Row;
      Column = m.COlumn;
      for(int i = 0; i < Row; ++i)
	for(int j = 0; j < Column; ++j)
	  val[i][j] = m.val[i][j];
    }

    Matrix& operator=(const Matrix &m)
    {
      for(int i = 0; i < Row; ++i)
	for(int j = 0; j < Column; ++j)
	  val[i][j] = m.val[i][j];
      return *this;
      }

    Matrix& operator+=(const Matrix &m)
    {
      for(int i = 0; i < Row; ++i)
	for(int j = 0; j < Column; ++j)
	  val[i][j] += m.val[i][j];
      return *this;
    }

    Matrix& operator-=(const Matrix &m)
    {
      for(int i = 0; i < Row; ++i)
	for(int j = 0; j < Column; ++j)
	  val[i][j] -= m.val[i][j];
      return *this;
    }

    Matrix& operator*=(const Matrix &m)
    {
      Numeric t[Row][Column];
      for(int i = 0; i < Row; ++i)
	for(int j = 0; j < Column; ++j)
	{
	  t[i][j] = Numeric(0);
	  for(int k = 0; k < Row; ++k)
	    t[i][j] += val[i][k]*m.val[k][j];
	}
      for(int i = 0; i < Row; ++i)
	for(int j = 0; j < Column; ++j)
	  val[i][j] = t[i][j];
      return *this;
    }
    
    const Numeric* operator[](unsigned int RowIndex)const
    {
      return val[RowIndex];
    }

    void SetVal(unsigned int RowIndex, unsigned int ColumnIndex, const Numeric& val)
    {
      this->val[RowIndex][ColumnIndex] = val;
    }

    void LUDecomposition(Matrix &buf)
    {
      for(int r = 0; r < Row; ++r)
      {
	for(int c = 0; c <= r; ++c)
	{
	  buf.val[r][c] = val[r][c];
	  for(int k = 0; k < c; ++k)
	    buf.val[r][c] -= buf[r][k]*buf[k][c];
	}

	for(int c = r + 1; c < Column; ++c)
	{
	  buf.val[r][c] = val[r][c];
	  for(int k = 0; k < r; ++k)
	    buf.val[r][c] -= buf[r][k]*buf[k][c];
	  buf.val[r][c] /= buf[r][r];
	}
      }
    }
  protected:
  private:
    Numeric **val;//[Row][Column];
//    int Row, Column;
  };

  //template<class Numeric, unsigned int Row, unsigned int Column>
//void LUSolve

  /*Matrix<Numeric, I, K> operator*(const Matrix<Numeric, I, J> A, const Matrix<Numeric, J, K> B)
  {
    Matrix<Numeric, I, K> C;
    Numeric t;
    for(int i = 0; i < I; ++i)
      for(int k = 0; k < K; ++k)
      {
	t = Numeric(0);
	for(int j = 0; j < J; ++j)
	  t += A[i][j]*B[j][k];
	C.SetVal(i, k, t);
      }
    return C;
  }*/

  template<class Numeric, unsigned int Row, unsigned int Column>
  std::ostream& operator << (std::ostream& dist, const Matrix<Numeric, Row, Column>& m)
  {
    for(int r = 0; r < Row; ++r)
    {
      for(int c = 0; c < Column; ++c)
	dist << std::setprecision(8) << std::setw(16) << std::right << m[r][c];
      dist << std::endl;
    }
    return dist;
  }
}

#endif
