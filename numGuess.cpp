#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;  // non-deterministic generator
    mt19937 gen(rd()); // to seed mersenne twister.
    cout << "Choose level:\n"
         << "1. 1-10\n"
         << "2. 1-100\n"
         << "3. Custom\n"
         << "\nPick a number(1/2/3)\n🙇: ";
    int userLevel;
    string showLevel;
    uniform_int_distribution<> dist(1, 10);
    cin >> userLevel;
    if (userLevel == 1)
    {
        uniform_int_distribution<> dist(1, 100); // distribute results between desired numbers inclusive.
        showLevel = "1 and 10";
    }
    else if (userLevel == 2)
    {
        uniform_int_distribution<> dist(1, 100); // distribute results between desired numbers inclusive.
        showLevel = "1 and 100";
    }
    else if (userLevel == 3)
    {
        int firstRange, lastRange;
        cout << "Enter first range (Ex: 10):\n😀: ";
        cin >> firstRange;
        cout << "Enter last range (Ex: 80):\n😗: ";
        cin >> lastRange;
        uniform_int_distribution<> dist(firstRange, lastRange); // distribute results between desired numbers inclusive.
        showLevel = to_string(firstRange) + " and " + to_string(lastRange);
    }
    else
    {
        cout << "Invalid❗ input ⌨️ \n 🥹" << endl;
        return 0;
    }
    int userDifficulty;
    cout << "\nChoose your Difficulty :\n"
         << "1. Easy (5 tries)\n"
         << "2. Medium (3 tries)\n"
         << "3. Hard (1 try)\n"
         << "\nYour Choice (1/2/3)\n🙍 ";
    cin >> userDifficulty;
    int tries;
    if (userDifficulty == 1)
    {
        tries = 5;
    }
    else if (userDifficulty == 2)
    {
        tries = 3;
    }
    else if (userDifficulty == 3)
    {
        tries = 1;
    }
    else
    {
        cout << "\nInvalid Input 🥺" << endl;
    }
    int guessNumber = dist(gen); // storing guessed number
    string description = "👩: Guess a Number Between " + showLevel;
    string hint = "Guess 🧠";
    while (tries != 0)
    {
        cout << "\n"
             << description << "\n🤖: Left Tries = " << tries << "\n\n"
             << hint << ": ";
        int userGuess;
        cin >> userGuess;
        if (userGuess == guessNumber)
        {
            // cout << " \n🎊 You 🫵 guessed 🧠 it right ✅" << endl;
            cout << "\n🥳 yay! It was " << guessNumber << endl;
            return 0;
        }
        else
        {
            cout << "\n👩: Wrong Guess"
                 << endl;
            if (userGuess < guessNumber)
            {
                hint = "🤫 ⬆ Higher";
            }
            else
            {
                hint = "⬇ Lower";
            }
            tries--;
        }
    }
    cout << "\n Number 🤣 was " <<guessNumber << endl;
    return 0;
}