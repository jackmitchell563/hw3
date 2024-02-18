#include "llrec.h"
#include<iostream>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(nullptr == head){
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  if(head->val > pivot){
    Node* temp = head->next;
    larger = head;
    larger->next = nullptr;
    llpivot(temp, smaller, larger->next, pivot);
  } else {
    Node* temp = head->next;
    smaller = head;
    smaller->next = nullptr;
    llpivot(temp, smaller->next, larger, pivot);
  }
  head = nullptr;
}

