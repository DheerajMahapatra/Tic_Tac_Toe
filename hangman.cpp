#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<stdlib.h>

using namespace std;

int tries = 3;

int check_guess(char, string, string&);
string message = "You have 3 chances!";

int check_guess(char guess, string real_month, string &hidden_month) {
    int match = 0;
    int len = real_month.length();
    for(int i = 0; i < len; i++) {
        if(guess == hidden_month[i]) {
            return 0;
        }
        if(guess == real_month[i]) {
            hidden_month[i] = guess;
            match++;
        }
    }
    return match;
}

int main() {
    system("Color B4");

    cout << "\t\t\t\tWelcome to the 'Guess the Month' game!" << endl;
    cout << "\t\tYou have to guess the name of a month by entering one letter at a time." << endl;
    cout << "\t\tYou have 3 chances to guess the correct letters in the month's name." << endl;
    cout << "\t\tLet's begin!" << endl << endl;
    char letter;
    string month;
    string months[] = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };

    srand(time(NULL));
    int month_number = rand() % 12;
    month = months[month_number];

    string hide_month(month.length(), 'X');

     while (tries != 0) {
        cout << "\t\t\t\t" << message << endl;
        cout << "\t\t\t\tLife:  " << tries << endl;
        cout << "\t\t\t\t" << hide_month << endl;
        cout << "\t\t\t\tGuess a letter: ";
        cin >> letter;

        system("cls");

        int guessResult = check_guess(letter, month, hide_month);

        if (guessResult == 0) {
            message = "Incorrect letter!!";
            tries--;
        } else if (guessResult > 0) {
            message = "Nice! Correct Guess!!";
        }

        if (hide_month == month) {
            message = "You are free!!";
            cout << "\t\t\t\tLife:  " << tries << endl;
            cout << "\t\t\t\t" << message << endl;
            cout << "\t\t\t\tThe month is:  " << month << endl;
            break;
        }
        else if(tries==0){
            string message1="You are hanged !";
            cout << "\t\t\t\tLife:  " << tries << endl;
            cout << "\t\t\t\t" << message1 << endl;
            cout << "\t\t\t\tThe month is:  " << month << endl;
        }
    }
    
}