#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(nullptr != smaller) smaller = nullptr;
  if(nullptr != larger) larger = nullptr;
  if(nullptr == head) return;
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

