/**
 * Shunting Yard Algorithm
 * Translating mathematical expressions from infix to postfix notation, 
 * considering basic arithmetic expressions, integers, and parantheses.
 * 
 * @author Harish Palani
 * @version February 2017
 */
#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

// Function prototypes
char* toPostfix(char *infix);

int main() {
    char infix[128];
    while (true) {
        // Get infix expression
        cout << "Enter an infix expression: ";
        cin.getline(infix, 128);
        cout << "Infix: " << infix << endl;
        
        // Convert infix to postfix & display
        char* postfix = toPosfix(input);
        cout << "Postfix: " << postfix << endl;
        delete[] postfix;
    }
    return 0;
}

char* toPostfix(char *infix) {
    
}