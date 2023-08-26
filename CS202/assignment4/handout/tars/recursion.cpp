/**
 * @file recursion.cpp
 * @author Nathaniel Stone, 8000617279
 * @brief This file will use recusion to raise a number to a power, search through an array
 *        using recusion, and finding the X in a maze.
 *
 */

#include <iostream>
#include <exception>

using namespace std;

const int WIDTH = 4;
const int HEIGHT = 5;

// Function prototypes
int power(const int &, int);
bool isValueInArray(int[], int, int, const int &);
void findTheX(char grid[HEIGHT][WIDTH], const int &x, const int &y);

// First maze to solve
char maze1[HEIGHT][WIDTH] = {
    {' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' '},
    {' ', ' ', 'X', ' '},
    {' ', ' ', ' ', ' '},
};

// Second maze to solve
char maze2[HEIGHT][WIDTH] = {
    {' ', 'X', 'O', ' '},
    {' ', ' ', 'O', ' '},
    {' ', ' ', 'O', ' '},
    {' ', ' ', 'O', ' '},
    {' ', ' ', ' ', ' '},
};

// Array for the search function
int arr[16]{1, 2, 5, 6, 7, 9, 10, 12,
            15, 18, 19, 20, 22, 23, 28, 30};

// Main just calls each of the individual recursion functions
int main()
{
  int functionToTest = -1;

  // Print a prompt
  cout << "Which function should be tested?" << endl;
  cout << "(1) power" << endl;
  cout << "(2) isValueInArray" << endl;
  cout << "(3) findTheX" << endl;

  cin >> functionToTest; // Read in the choice
  while (cin.fail() || functionToTest < 1 || functionToTest > 4)
  {
    cout << "Error, invalid choice. Please pick a number 1-4" << endl;
    cin.ignore(1024, '\n');
    cin.clear();
  }

  // After the read works, run the testing code for the choice
  switch (functionToTest)
  {
  case 1:
    cout << "2^10 = " << power(20, 3) << endl;
    cout << "4^0 = " << power(4, 0) << endl;
    break;
  case 2:
    cout << "Is 2 in the array? "
         << (isValueInArray(arr, 0, 16, 2) ? "yes" : "no") << endl;
    cout << "Is 6 in the array? "
         << (isValueInArray(arr, 0, 16, 6) ? "yes" : "no") << endl;
    cout << "Is 21 in the array? "
         << (isValueInArray(arr, 0, 16, 21) ? "yes" : "no") << endl;
    break;
  case 3:
    cout << "---- Maze 1 ----" << endl;
    findTheX(maze1, 1, 1);
    cout << "---- Maze 2 ----" << endl;
    findTheX(maze2, 3, 2);
    break;
  }
}

/**
 * @brief
 * Finds the base to the given power
 *
 * @param base Base number
 * @param pow Exponent number
 * @return int
 */
int power(const int &base, int pow)
{
  // checking base case
  if (pow == 0)
  {
    return 1;
  }
  // perform the function
  else
  {
    return base * power(base, pow - 1);
  }
}

/**
 * @brief
 * Tells whether or not the given value is in the array with the given length
 * and starting at the given start index
 * (either implement this linearly or with binary search as a challenge)
 *
 * @param arr
 * @param start
 * @param length
 * @param value
 * @return true
 * @return false
 */
bool isValueInArray(int arr[], int start, int length, const int &value)
{
  // length cant be zero
  if (length == 0)
  {
    return false;
  }
  // checks if value is at current spot
  if (value == arr[start])
  {
    return true;
  }
  else
  {
    // are we at the end of the array?
    if (start == length)
    {
      return false;
    }
    // *recursion*
    return isValueInArray(arr, start + 1, length, value);
  }
}

/**
 * @brief
 * Tries to find the 'X' char in the array. This starts the check at the spot
 * with the given x, y coordinate, and then searches all adjacent spaces in the
 * array. 'O' chars are considered walls and cannot be traversed. Prints the
 * position the x was found at
 *
 * @param grid
 * @param x
 * @param y
 */
void findTheX(char grid[HEIGHT][WIDTH], const int &x, const int &y)
{
  // If the char at the current spot is an X, then we solved it
  if (grid[y][x] == 'X')
  {
    cout << "Found the X at (" << x << ", " << y << ")\n";
    grid[y][x] = 'O';
    return;
  }
  else if (grid[y][x] == 'O')
  {
    return;
  }
  grid[y][x] = 'O';
  /*

  // CHECK FOR BASE CASES FIRST AND TRY THAT.

  * /
      // if (grid[x][y] != 'X' && grid[x][y] != 'O')
      // {
      //   grid[x][y] = 'O';
      /*
      for (int i = 0; i < HEIGHT; i++)
      {
        for (int j = 0; j < WIDTH; j++)
        {
          cout << grid[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      */
  if (x + 1 <= WIDTH)
  {
    findTheX(grid, x + 1, y);
  }
  if (y + 1 <= HEIGHT)
  {
    findTheX(grid, x, y + 1);
  }
  if (x - 1 >= 0)
  {
    findTheX(grid, x - 1, y);
  }
  if (y - 1 >= 0)
  {
    findTheX(grid, x, y - 1);
  }
  return;
}
// }