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
int precedence (char o);

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

// Implementation of shunting yard algorithm
char* toPostfix(char *infix) {
    Stack s;
    char* postfix = new char[strlen(infix) + 1];
    int iInfix = 0, iPostfix = 0;
    
    while (infix[iInfix]) {
        if (infix[iInfix] == ' ') {
            iInfix++;
            continue; // Skip shunting yard operations if it's a space
        }
        
        // Check if the character is an integer
        if (isdigit(infix[iInfix])){
            while (isdigit(infix[iInfix])){
                postfix[iPostfix++] = infix[iInfix++];
            }
            postfix[iPostfix++] = ' ';
        }
        
        // Check if the character is an operator
        else if (infix[iInfix] == '+' || infix[iInfix] == '-' || 
                 infix[iInfix] == '*' || infix[iInfix] == '/' || 
                 infix[iInfix] == '^') {
            
            while (stack.peek() == '+' || stack.peek() == '-' || 
                   stack.peek() == '*' || stack.peek() == '/' || 
                   stack.peek() == '^') && 
                   ((infix[iInfix] != '^') &&  
                    (precedence(infix[iInfix]) <= precedence(stack.peek()))) || 
                   ((infix[iInfix] == '^') && 
                    (precedence(infix[iInfix]) < precedence(stack.peek())))) {
                postfix[iPostfix++] = stack.pop();
                postfix[iPostfix++] = ' ';
            }           
            stack.push(infix[iInfix++]);
        }
    }
}

int precedence (char o) {
    if (o == '+' || o == '-') { return 0; }
    if (o == '*' || o == '/') { return 1; }
    if (o == '^') { return 2; }
    return -1;
}
