// SquirrelSurfShop.cpp by Tom Bonino
//

#include <iostream>
#include <iomanip>
#include <algorithm> // streamline validating user selections by forcing upper case after entry

using namespace std;

// declare function prototypes
void headerLine();
void ShowUsage();
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalXXXs, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

int main()
{

    // declare variables to hold values required by program
    char cSentinel;
    int iTotalXXXS = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int user_quantity = 0;
    char user_board;
    int cost = 0;

    // output program header
    headerLine();
    cout << left << setw(5) << setfill('*') << "" << " Welcome to Johnny Utah's PointBreak Surf Shop " << setw(5) << setfill('*') << "" << endl;
    headerLine();
    cout << endl; // spacer

    // output first prompt
    ShowUsage();

    // do while loop to allow the prompt to execute at least once
    do
    {
        cout << "Please enter selection: ";

        // get sentinel value from user
        if (cin >> cSentinel)
        {

            /* transform(cSentinel.begin(), cSentinel.end(), cSentinel.begin(), ::toupper);*/

            switch (::toupper(cSentinel))
            {

                // show selection case
            case 'S':
                ShowUsage();
                break;

                // case to purchase a board
            case 'P':
                MakePurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
                break;

                // call function to display the number of each board sold
            case 'C':
                DisplayPurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
                break;

                // call function to display the running total
            case 'T':
                DisplayTotal(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
                break;

                // end program with sentinel value
            case 'Q':
                // simply output thank you statement, loop will end when cSentinel value evaluated
                cout << "Thank you, please come again!" << endl;

                // close program successfully when sentinel value entered.
                std::system("pause");
                return 0;
                break;

            default:
                cout << "Please make a valid entry." << endl;
                cout << endl; // spacer
                break; // continue loop until sentinel value entered
            }
        }

        // validate sentinel entry
        else
        {
            cout << "Please make a valid entry." << endl;
            cout << endl; // spacer
            continue; // continue loop until sentinel value entered
            cin.clear(); // clear stream
        }
        cin.clear(); // clear stream

    }     while (::toupper(cSentinel) != 'Q');
}

// function to create file header line
void headerLine()
{
    cout << left << setw(60) << setfill('*') << "" << endl;
}

// present usage menu
void ShowUsage()
{
    cout << left << "To show program usage press 'S'" << endl;
    cout << left << "To purchase a surfboard press 'P'" << endl;
    cout << left << "To display current purchases press 'C'" << endl;
    cout << left << "To display total amount due press 'T'" << endl;
    cout << left << "To quit the program press 'Q'" << endl;
    cout << endl; // spacer
}

// function to sell and track sales of surfboards
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    int user_quantity = 0;
    char user_board;

    // prompt user for entry
    cout << "Please enter the quantity and type (X=squirrel, S=small, M=medium, L=large) of surfboard(s) you would like to purchase: ";

    // validate user entry
    if (cin >> user_quantity >> user_board)
    {
        if (user_quantity > 0)
        {

            // increment running quantity totals
            switch (::toupper(user_board))
            {
            case 'X':
                cout << "You bought a squirrel size!" << endl;
                iTotalXXXS = iTotalXXXS + user_quantity;
                cout << endl; // spacer
                break;

            case 'S':
                cout << "You bought a small!" << endl;
                iTotalSmall = iTotalSmall + user_quantity;
                cout << endl; // spacer
                break;

            case 'M':
                cout << "You bought a medium!" << endl;
                iTotalMedium = iTotalMedium + user_quantity;
                cout << endl; // spacer
                break;

            case 'L':
                cout << "You bought a large!" << endl;
                iTotalLarge = iTotalLarge + user_quantity;
                cout << endl; // spacer
                break;

            default:
                cout << "Invalid selection. Please try again." << endl;
                cout << endl; // spacer
                break;
            }
        }

        else
        {
            cout << "Please enter a quantity greater than zero." << endl;
            cout << endl; // spacer
        }
    }

    else
    {
        cout << "Invalid entry." << endl;
        cin.clear(); // clear stream
        cin.ignore(4);
        cout << endl; // spacer
    }
}

void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    // local constant variables for calculation
    const int XXXS = 100;
    const int Small = 175;
    const int Medium = 190;
    const int Large = 200;

    // local variables to hold cost
    int squirrelCost = iTotalXXXS * XXXS;
    int smallCost = iTotalSmall * Small;
    int mediumCost = iTotalMedium * Medium;
    int largeCost = iTotalLarge * Large;

    // output results
    if (squirrelCost > 0)
        cout << "The total number of SQUIRREL surfboards is " << iTotalXXXS << " at a total of $" << squirrelCost << ".00" << endl;

    if (smallCost > 0)
        cout << "The total number of SMALL surfboards is " << iTotalSmall << " at a total of $" << smallCost << ".00" << endl;

    if (mediumCost > 0)
        cout << "The total number of MEDIUM surfboards is " << iTotalMedium << " at a total of $" << mediumCost << ".00" << endl;

    if (largeCost > 0)
        cout << "The total number of LARGE surfboards is " << iTotalLarge << " at a total of $" << largeCost << ".00" << endl;

    if ((squirrelCost + smallCost + mediumCost + largeCost) > 0)
    {
        cout << "Amount due: $" << squirrelCost + smallCost + mediumCost + largeCost << ".00" << endl;
        cout << endl; // spacer
    }

    else
    {
        cout << "No purchases made yet." << endl;
        cout << endl; // spacer
    }


}
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    // output results
    if (iTotalXXXS > 0)
        cout << "The total number of SQUIRREL surfboards is " << iTotalXXXS << endl;

    if (iTotalSmall > 0)
        cout << "The total number of SMALL surfboards is " << iTotalSmall << endl;

    if (iTotalMedium > 0)
        cout << "The total number of MEDIUM surfboards is " << iTotalMedium << endl;

    if (iTotalLarge > 0)
        cout << "The total number of LARGE surfboards is " << iTotalLarge << endl;

    // one more if to print one spacer
    if (iTotalXXXS + iTotalSmall + iTotalMedium + iTotalLarge > 0)
        cout << endl; // spacer

    else
    {
        cout << "No purchases made yet." << endl;
        cout << endl; // spacer
    }
}