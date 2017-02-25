#include "Stack.h"

char Stack::peek() {
    if (head == NULL) { return '\0'; } 
    return head->c;
}

char Stack::pop() {
    Node* n = new Node();
    n->next = head;
    n->c = token;
    head = n;
}

void Stack::push(char c) {
    if (head != NULL){
        char temp = head->c;
        Node* topOfStack = head;
        head = head->next;
        delete topOfStack;
        return temp;
    }
    
    return 0;
}