#include "vector.h"

#include <fstream>  // ifstream
#include <iostream> // cout, endl;

int main(int argc, char *argv[])
{
  Vector v1, v2, v3;

  std::ifstream infile;
  if (argc != 2)
  {
    std::cout << "ERROR: Invalid Arguments\n";
    return -1;
  }
  infile.open(argv[1]);
  if (!infile.good())
  {
    std::cout << "Could not open " << argv[1]
              << ". Did you put it in the same directory?\n";
    return -1;
  }

  // Read in each of the vectors
  infile >> v1 >> v2 >> v3;

  // Close file.
  infile.close();

  // Test all of our operations:
  std::cout << "v1 = " << v1 << std::endl
            << "v2 = " << v2 << std::endl;

  Vector v4 = v3;
  std::cout << "\nTesting = assignment operation" << std::endl
            << "Checking if v3 and v4 are the same" << std::endl
            << "v3 = " << v3 << std::endl
            << "v4 = " << v4 << std::endl;

  v4 *= 5;
  std::cout << "\nTesting math operations" << std::endl
            << "v4 *= 5 = " << v4 << std::endl
            << "v1 + v2 = " << v1 + v2 << std::endl
            << "v1 * v2 = " << v1 * v2 << std::endl;

  std::cout << "\nTesting an invalid operation" << std::endl;
  try
  {
    std::cout << v1 * v3 << std::endl;
  }
  catch (DimensionMismatchException &e)
  {
    std::cout << "\nEncountered an error when multiplying: "
              << e.what() << std::endl;
  }
  try
  {
    std::cout << v1 + v3 << std::endl;
  }
  catch (DimensionMismatchException &e)
  {
    std::cout << "\nEncountered an error when adding: "
              << e.what() << std::endl;
  }
}
