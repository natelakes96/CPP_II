/**
 * @file vector.cpp
 * @author Nathaniel Stone, 8000617279
 * @brief this file will define the funtions and operators used
 *        in the vector class.
 *
 */
#include "vector.h"

#include <cassert>
#include <iostream>

using namespace std;

/*** Constructors and Destructor ***/

/// @brief Paramiterized constructor that will take in integers.
/// @param size The size of the Vector.
Vector::Vector(int size)
{
  this->size = size;
  this->contents = new float[size];
}

/// @brief A paramiterized constructor that will take in vectors.
/// @param rhs a vector that you want to make another object of.
Vector::Vector(const Vector &rhs)
{
  this->size = rhs.size;
  this->contents = new float[size];
  for (int i = 0; i < size; i++)
  {
    contents[i] = rhs.contents[i];
  }
}

/// @brief Deconstructor that frees the memory used.
Vector::~Vector()
{
  delete[] contents;
}

/*** Overloaded Operators ***/

/// @brief this will perform addition to the vectors
/// @param rhs Right hand side of addition operation
/// @return The restult of the addition of the vectors.
Vector Vector::operator+(const Vector &rhs) const
{

  try
  {
    if (size != rhs.size)
    {
      throw DimensionMismatchException("LHS and RHS aer of different sizes and could not be added.");
    }
    Vector temp;
    temp.size = size;
    temp.contents = new float[size];
    for (int i = 0; i < temp.size; i++)
    {
      temp.contents[i] = contents[i] + rhs.contents[i];
    }
    return temp;
  }
  catch (DimensionMismatchException &e)
  {
    throw;
  }
}

/// @brief Performs inplace scaling on a vector
/// @param scalar The scalar you want apply to the vector.
void Vector::operator*=(float scalar) const
{
  for (int i = 0; i < size; i++)
  {
    contents[i] = contents[i] * scalar;
  }
}

/// @brief This will find the dot product of a given vector
/// @param rhs The right hand side operand
/// @return Dot product of two vectors.
float Vector::operator*(const Vector &rhs) const
{
  try
  {
    // checks for size mismatch
    if (size != rhs.size)
    {
      throw DimensionMismatchException("LHS and RHS are of different sizes and could not be multiplied.");
    }
    // makes temp array of floats
    float temp[size];
    // multiplys the contents and saves into temp array
    for (int i = 0; i < size; i++)
    {
      temp[i] = contents[i] * rhs.contents[i];
    }
    // sums the array
    float sum = 0.0;
    for (int i = 0; i < size; i++)
    {
      sum = sum + temp[i];
    }
    // returns the dot product
    return sum;
  }
  catch (DimensionMismatchException &e)
  {
    throw;
  }
}

/// @brief This is the assignment operator for the Vector class
/// @param rhs Vector to be copied.
/// @return None
void Vector::operator=(const Vector &rhs)
{
  try
  {
    // checks for size mismatch
    if (size != rhs.size)
    {
      throw DimensionMismatchException();
    }
    // gaurd from self assignment
    if (this == &rhs)
    {
      throw -1;
    }
    // see if memory has been allocated
    if (contents != nullptr)
    {
      delete[] contents;
      size = rhs.size;
      contents = new float[size];
    }
    // copy all of the contents
    copy(rhs.contents, rhs.contents + size, contents);
  }
  catch (DimensionMismatchException &e)
  {
    throw;
  }
  catch (int)
  {
    cout << "Cannot self assign\n";
  }
}

/// @brief Overwrites the index of operator.
/// @param idx The index you want to access.
/// @return The value at the index requseted.
float &Vector::operator[](int idx)
{
  assert(0 <= idx && idx < size);
  return contents[idx];
}

/// @brief Overwrites the index of operator.
/// @param idx The index you watn to access.
/// @return The value at teh index requested.
const float &Vector::operator[](int idx) const
{
  assert(0 <= idx && idx < size);
  return contents[idx];
}

/*** Friended Operator Overloads ***/

/// @brief Overloads the stream incertion operator to handle a vector class.
/// @param outputer The ostream type used.
/// @param rhs The vector to be output
/// @return The output stream
std::ostream &operator<<(std::ostream &outputer, const Vector &rhs)
{
  outputer << "<";
  for (int i = 0; i < rhs.size; i++)
  {
    outputer << rhs.contents[i] << ", ";
  }
  outputer << "\b\b >";
  return outputer;
}

/// @brief
/// @param
/// @param
/// @return
std::istream &operator>>(std::istream &inputer, Vector &rhs)
{
  // checks if contents is full
  if (rhs.contents != nullptr)
  {
    delete[] rhs.contents;
    rhs.contents = nullptr;
  }
  // reads in size
  inputer >> rhs.size;
  // makes new array to point to
  rhs.contents = new float[rhs.size];
  // reads in the vector
  for (int i = 0; i < rhs.size; i++)
  {
    inputer >> rhs.contents[i];
  }

  return inputer;
}
