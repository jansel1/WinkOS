#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>

using namespace std;

void wait(int seconds) {
    Sleep(seconds * 1000);
}

void cls(int delay=0) {
    wait(delay);
    system("cls");
}

void renderOptions() {
    cout << "N - Notepad \t C - Calculator \t S - JSC Command Line (Alpha)" << endl << endl;
}

float calc(int a, int b, char op) {
    float result;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                cerr << "\nCannot multiply integer (b) by 0" << endl;
            }

            break;
        default:
            cerr << "\nInvalid operator: " << op << endl;
    }

    cout << "Result: " << result << endl << endl;
}

int renderMain() {
    string out;

    cout << "> ";
    getline(cin, out);

    if (out == "n") { // Notepad (key: n)
        cls();

        while (true) {
            string notepad_out;
            
            getline(cin, notepad_out);

            if (notepad_out == "$quit") {
                cls();

                renderOptions();
                renderMain();

                break;
            }
        }
    } else if (out == "c") { // Calculator (key: c)
        cls();

        while (true) {
            float firstNumber;
            float secondNumber;

            char op;

            if (firstNumber == -0.0 || secondNumber == -0.0 || op == '$') {
                cls();
                break;
            }

            cout << "First number: ";
            cin >> firstNumber;

            cout << "Operator: ";
            cin >> op;

            cout << "Second number: ";
            cin >> secondNumber;

            calc(firstNumber, secondNumber, op);
        }
    } else if (out == "s") {
        cls();
        
        system("cd external\\jsc-alpha");
        system("external\\jsc-alpha\\jsc.exe");
    }

    cls();
        
    renderOptions();
    renderMain();

    return 0;
}


int main() {
    cls();
    renderOptions();

    while (true) {
        int mainProcess = renderMain();
    }
}