#include <iostream>
using namespace std;

void cipher (string statement);
void decipher (string statement);
string toLower(string choice);
string toUpper(string choice2);
void a_c_checker(int *num1, int *num2);
string stringVerifier(string statement);
int intVerifier(int num);
void abcInput();

// Global variables
int a, b, c;
string option, statement;

int main() {

    // Main program loop to cipher, decipher, or exit
    while (true)
    {
        cout << "Do you want to cipher, decipher, or exit the program? " << endl;
        cin >> option;
        option = stringVerifier(option);
        option = toLower(option);
        if (option == "cipher")
        {
            abcInput();
            cout << "Enter the statement you want to cipher: " << endl;
            cin >> statement;
            statement = stringVerifier(statement);
            statement = toUpper(statement);
            cipher(statement);
        }
        else if (option == "decipher")
        {
            abcInput();
            cout << "Enter the statement you want to decipher: " << endl;
            cin >> statement;
            statement = stringVerifier(statement);
            statement = toUpper(statement);
            decipher(statement);
        }
        else if (option == "exit")
            break;
        else
            cout << "Please choose a valid option from the ones below. " << endl;
    }

    return 0;
}

// Converts uppercase letters to lowercase ones
string toLower(string choice)
{
    for (char & i : choice) {
        i = tolower(i);
    }
    return choice;
}

// Converts lowercase letters to uppercase ones
string toUpper(string choice2)
{
    for (char & i : choice2) {
        i = toupper(i);
    }
    return choice2;
}

// Validates that a & c satisfy a certain equation
void a_c_checker(int *num1, int *num2)
{
    while ((*num1 * *num2) % 26 != 1)
    {
        cout << "Please enter values for a and c that satisfy this equation (a * c) % 26 = 1 \n a: ";
        cin >> *num1;
        cout << "\n c: ";
        cin >> *num2;
    }
}

// Makes sure the input is only string
string stringVerifier(string statement){
    for (int i = 0; i < statement.size(); ++i) {
        while (!isalpha(statement[i]))
        {
            cout << "Please enter a valid input: " << endl;
            cin >> statement;
        }
    }
    return statement;
}

// Makes sure the input is only numbers
int intVerifier(int num){
    while (!(cin >> num))
    {
        cout << "Please enter a number:\n";
        cin.clear();
        cin.ignore(256, '\n');
    }
    return num;
}

// Ciphering the statement
void cipher (string statement){
    statement = stringVerifier(statement);
    statement = toUpper(statement);
    for (char i : statement) {
        cout << char(((a * (i - 65) + b) % 26) + 65);
    }
    cout << endl;
}

// Deciphering the statement
void decipher(string statement)
{
    for (char i : statement) {
        int sum = (c * ((i - 65) - b));
        while(sum < 0)
        {
            sum += 26;
        }
        cout << char((sum % 26) + 65);
    }
    cout << endl;
}

// Getting a, b, c values
void abcInput()
{
    cout << "Please enter the value of the a: " << endl;
    cin >> a;
    a = intVerifier(a);
    cout << "Please enter the value of the b: " << endl;
    cin >> b;
    b = intVerifier(b);
    cout << "Please enter the value of the c: " << endl;
    cin >> c;
    c = intVerifier(c);
    a_c_checker(&a, &c);
}
