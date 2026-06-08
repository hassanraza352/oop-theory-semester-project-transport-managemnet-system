#include "UIUtils.h"
#include <windows.h>
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen()
{
    system("cls");
}

void printHeading()
{
    cout << "\n\n";
    // Silver/Platinum Gradient for Professional Look
    setColor(15);
    cout << "\t     _______ _____            _   _  _____ _____   ____  _____ _______ \n";
    cout << "\t    |__   __|  __ \\     /\\   | \\\\ | |/ ____|  __ \\ / __ \\|  __ \\__   __|\n";
    setColor(7);
    cout << "\t       | |  | |__) |   /  \\  |  \\| | (___ | |__) | |  | | |__) | | |   \n";
    cout << "\t       | |  |  _  /   / /\\ \\ | . ` |\\___ \\|  ___/| |  | |  _  /  | |   \n";
    setColor(8);
    cout << "\t       | |  | | \\ \\  / ____ \\| |\\  |____) | |    | |__| | | \\ \\  | |   \n";
    cout << "\t       |_|  |_|  \\_\\/_/    \\_\\_| \\_|_____/|_|     \\____/|_|  \\_\\ |_|   \n\n";

    setColor(8);
    cout << "\t\t\t+---------------------------------------+\n";
    cout << "\t\t\t|    ";
    setColor(14); cout << "MANAGEMENT SYSTEM OF UNIVERSITY"; setColor(8);
    cout << "    |\n";
    cout << "\t\t\t+---------------------------------------+\n\n";
    setColor(15);
}

void printSubHeading(string title)
{
    setColor(8);
    cout << "\n\t\t\t~=~=~=~ ";
    setColor(11); // Cyan for Subheading text
    cout << title;
    setColor(8);
    cout << " ~=~=~=~\n\n";
    setColor(15);
}

int getValidInt(string prompt)
{
    string input;
    while (true)
    {
        setColor(14); // Yellow for Prompt
        cout << prompt;
        setColor(15); // White for user input
        cin >> input;

        if (input == "r" || input == "R")
        {
            cin.ignore(10000, '\n');
            return -1;
        }

        bool valid = true;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                valid = false;
                break;
            }
        }

        if (valid && input.length() > 0)
        {
            cin.ignore(10000, '\n');
            return stoi(input);
        }
        else
        {
            setColor(12);
            cout << "\t\tInvalid Input! Please enter valid numbers only. (or press 'R' to go back)\n";
        }
    }
}

float getValidFloat(string prompt)
{
    string input;
    while (true)
    {
        setColor(14); // Yellow for Prompt
        cout << prompt;
        setColor(15); // White for user input
        cin >> input;

        if (input == "r" || input == "R")
        {
            cin.ignore(10000, '\n');
            return -1.0;
        }

        bool valid = true;
        int dotCount = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '.')
            {
                dotCount++;
                if (dotCount > 1) valid = false;
            }
            else if (input[i] < '0' || input[i] > '9')
            {
                valid = false;
                break;
            }
        }

        if (valid && input.length() > 0)
        {
            cin.ignore(10000, '\n');
            return stof(input);
        }
        else
        {
            setColor(12);
            cout << "\t\tInvalid Input! Please enter valid numeric values. (or press 'R' to go back)\n";
        }
    }
}
}