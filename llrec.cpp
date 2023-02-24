#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){

  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  if(head->val > pivot){
    Node* largerTemp = larger;
    larger = head;
    head = head->next;
    larger->next = largerTemp;
    llpivot(head, smaller, larger->next, pivot);
  }

  else {
    Node* smallerTemp = smaller;
    smaller = head;
    head = head->next;
    smaller->next = smallerTemp;
    llpivot(head, smaller->next, larger, pivot);
  }
  
}
