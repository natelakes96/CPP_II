/*
 * Name: Nathaniel Stone, 202.1002, ASSIGNMENT_1
 * Description: This is a card sorting program that will sort cards based off of
 *              value and energy cost.
 * Input: an input file with a string, and two ints
 * Output: a terminal output with the cards before they are sorted
 *         after they are sorted by value, and after they are sorted
 *         by energy cost.
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/* ***********************************
    Class and Function Declaration
* ***********************************/
enum SortBy
{
    VALUE,
    ENERGYCOST
};

class Card
{
private:
    static int const CARDNAMEMAX = 50; //< Max Length of any card name
    string name;                       //< Name of the card.
    int value;                         //< Cost of the card.
    int energyCost;                    //< Energy required to play the card.

public:
    // Static Declarators
    static int cardNameScalar;

    // Constructors and Destructor
    Card() : name(""), value(0), energyCost(0) {} // Default Constructor
    Card(string name, int value, int energyCost); // Parameterized Constructor

    // Accessors (Getters)
    int getEnergyCost() const { return energyCost; } // Returns energyCost of the object.
    int getValue() const
    {
        return value;
    } // Returns value of the object.
    string getName() const
    {
        return name;
    } // Returns name of the object.

    // Static Accessors (Getters)
    int static getMaxName()
    {
        return CARDNAMEMAX;
    } // Returns the value of CARDNAMEMAX.

    // Mutators (Setters)
    void setEnergyCost(int);
    void setValue(int);
    void setName(string);

    // Functions
    void showCard();
    void operator=(const Card &);
};

// Initialize static values
int Card ::cardNameScalar = 0;

void sortCards(Card *cards, int size, SortBy order);

/* ***********************************
    Main Function
* ***********************************/
int main(int argc, char *argv[])
{
    Card cards[10];       //< Array to store up to 10 cards.
    ifstream infile;      //< Input file stream.
    string temp_str = ""; //< Used for storing a string from file stream.
    int temp_int = 0;     //< Used for storing an integer from file stream.
    int counter = 0;      //< Counts the number of cards read from the file.

    /*
        YOUR CODE HERE

        File must be passed in as a parameter to the program. If the number
        of parameters are incorrect throw an error and return -1. If the file
        does not exist or cannot be opened, throw an error and return -1.
    */
    // opens file
    infile.open(argv[1]);

    // checks if argument is there
    if (argc <= 1)
    {
        // outputs error and terminates
        std::cerr << "ERROR : Incorrect usage.\n./a.out < filename >"
                  << std::endl;
        return -1;
    }
    // checks if opening the file fails
    else if (infile.fail())
    {
        // outputs error and terminates
        std::cerr << "ERROR : Could not open file : " << argv[1] << std::endl;
        return -1;
    }
    /*
        Read the name, value, and energy cost of the card, and store
        it in the cards[10] array. Make sure to increment the counter
        after each entry. You can use the temp_int and temp_str variables
        for temporary storage to call the setName and setValue functions.

        Using the temp_str variable access the length of the string and update
        the value of cardNameScalar if length is greater while remaining less
        than .
    */

    // filling cards array with values from file
    while (!infile.eof())
    {
        // reads in name
        infile >> temp_str;
        cards[counter].setName(temp_str);

        // adjusts cardnameScalar
        if (static_cast<int>(temp_str.length()) > Card::cardNameScalar)
        {
            Card::cardNameScalar = temp_str.length();
        }
        // reads in value
        infile >> temp_int;
        cards[counter].setValue(temp_int);

        // reads in energy cost and increments counter
        infile >> temp_int;
        cards[counter++].setEnergyCost(temp_int);
    }

    for (int i = 0; i < counter; i++)
    {
        cards[i].showCard(); // Display all cards read.
    }
    cout << "\nSorting by Value...\n";
    sortCards(cards, counter, SortBy::VALUE);
    for (int i = 0; i < counter; i++)
    {
        cards[i].showCard(); // Display all cards after sorting by value.
    }
    cout << "\nSorting by Energy Cost...\n";
    sortCards(cards, counter, SortBy::ENERGYCOST);
    for (int i = 0; i < counter; i++)
    {
        cards[i].showCard(); // Display all cards after sorting by energyCost.
    }
    return 0;
}

/* *****************************************************************
    Function Definitions

    Make sure to write function descriptions above the
    function. Using the following template:

    Brief function description.
    @param parameter parameter description.
    @return what does the function return.

    Description for the sortCards function has been provided
    as an example.

* *****************************************************************/

/**
 *@brief this is a parameterized constructor for the Card class
 *@param name name of card
 *@param value value of card
 *@param energycost energy cost of the card
 * @return nothing
 */
Card::Card(string name, int value, int energyCost)
{
    // energy checks
    if (energyCost > 5)
    {
        energyCost = 5;
    }
    else if (energyCost < 0)
    {
        energyCost = 0;
    }

    // value checks
    if (value > 8)
    {
        value = 8;
    }
    else if (value < 0)
    {
        value = 0;
    }

    // name checks
    if (Card::name.length() > CARDNAMEMAX)
    {
        name = "<error>";
        std::cerr << "Name can't be longer than CARDNAMEMAX (50) characters.";
    }
}

/**
 *@brief This sets the energy cost for a card to an integer.
 *@param cost The integer that is to be set to the energyCost varible.
 *@return Nothing.
 */
void Card::setEnergyCost(int cost)
{
    // If energyCost is over 5 set it to 5; if it is below 0, set it to 0.
    energyCost = cost;
    if (energyCost > 5)
    {
        energyCost = 5;
    }
    else if (energyCost < 0)
    {
        energyCost = 0;
    }
}

/**
 *@brief This sets the value for a card to an integer.
 *@param val the integer that is to be set to the Value varible.
 *@return Nothing.
 */
void Card::setValue(int val)
{
    // If value is over 8 set it to 8; if it is below 0, set it to 0
    value = val;
    if (value > 8)
    {
        value = 8;
    }
    else if (value < 0)
    {
        value = 0;
    }
}

/**
 *@brief This sets the Name for a card to a string.
 *@param n String that is to be set to the Name varible.
 *@return Nothing.
 */
void Card::setName(string n)
{
    /*
        If name is over CARDNAMEMAX (50) characters, set it to "<error>" and
        print an error to std::cerr "Name can't be longer than CARDNAMEMAX (50) characters.".
    */
    Card::name = n;
    if (Card::name.length() > CARDNAMEMAX)
    {
        name = "<error>";
        std::cerr << "Name can't be longer than CARDNAMEMAX (50) characters.";
    }
}

/**
 * Prints the card to terminal.
 * @return None.
 */
void Card::showCard()
{
    cout << right << setw(Card::cardNameScalar) << name << " :: "
         << left
         << setw(3) << "VAL " << setw(2) << value
         << setw(3) << " ENG " << setw(2) << energyCost << "\n";
}

/**
 * Performs a deep copy when using the assignment operator with the Card class.
 *
 * This is an overloaded operator. We will cover this later in class. It has
 * been provided here to make sorting easier.
 * @param other R-value of assignment operator.
 * @return None.
 */
void Card::operator=(const Card &other)
{
    this->name = other.name;
    this->value = other.value;
    this->energyCost = other.energyCost;
}

/**
 * @brief Sorts an existing array of cards by a given parameter.
 * @param cards List of cards to sort.
 * @param size Size of list.
 * @param order Element used to sort by.
 * @return None
 */
void sortCards(Card *cards, int size, SortBy order)
{
    // this will sort by the value
    if (order == VALUE)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (cards[j].getValue() > cards[j + 1].getValue())
                {
                    Card tempCard;
                    tempCard.operator=(cards[j]);
                    cards[j] = cards[j + 1];
                    cards[j + 1] = tempCard;
                }
            }
        }
    }

    // this sorts by energy
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (cards[j].getEnergyCost() > cards[j + 1].getEnergyCost())
                {
                    Card tempCard;
                    tempCard.operator=(cards[j]);
                    cards[j] = cards[j + 1];
                    cards[j + 1] = tempCard;
                }
            }
        }
    }
}