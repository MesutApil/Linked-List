// Author : Mesut Apil
// Linked List
// <Singly Linked List>

#include<iostream>
#include<cstdlib>

using namespace std;

//*****************************************************************************
// Class has a structure that is used to create a link list
//
// Structure and all the functions are public
//
// ****************************************************************************

class Linked_List{

    public:
    struct ListNode{
    int data;
    ListNode* next;
};
    ListNode *head;
    Linked_List();
    void createList (int addData);
    void removeDuplicates( ListNode *list);
    void printList();
    ListNode* mergeList( ListNode* list1,  ListNode* list2);
    void endAddNode(int addData);
    void beginAddNode(int addData);
    void deleteNode(int data);
    void reverse_print(ListNode* list);
    void  getCount(ListNode* head);
    void  printList_list3();
};
//*****************************************************************
//
// Constructor
//
//Creates and Makes the list empty
//
//*******************************************************************

Linked_List::Linked_List(){
    head = NULL;
}
//*****************************************************************
//Adds data to the linked list
//
// param-1- Int Add data. Takes the integer and puts it in the list
//
//*******************************************************************

void Linked_List:: createList(int addData){

    ListNode *newNode;
    newNode = new ListNode;
    newNode->data = addData;
    newNode->next = NULL;
    if (!head)
        head = newNode;
    else {
        ListNode *nodePtr;
        nodePtr = head;
        while (nodePtr->next)
        nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
  }

//*****************************************************************
// Print function to print the list
//
//*******************************************************************

void Linked_List:: printList(){
    ListNode *nodePtr;
    for (nodePtr = head; nodePtr; nodePtr = nodePtr->next)
        cout << nodePtr->data << " ";
}
//*****************************************************************
// print function for list 3 as it needs to be printed in two different lines
//
//*******************************************************************

void Linked_List:: printList_list3(){
    int count =1;
    ListNode *nodePtr;
    for (nodePtr = head; nodePtr; nodePtr = nodePtr->next){
        cout << nodePtr->data << " ";
        count++;
        if (count > 15){
            cout << endl;
            count =0;
        }
    }
}
//*****************************************************************
// Adds list 2 at the end of list 1
//
// param-1-List1 linked list 1 is passes to the function
// param-2-list2 linked list 2 is passed to the function
//
// returns New list
//*******************************************************************

Linked_List::ListNode* Linked_List:: mergeList(ListNode* list1, ListNode* list2){

    ListNode *temp=list1;
    while(temp->next)
        temp=temp->next;
    temp->next=list2; // adding list_2 at the end of list_1
    return list1;
}
//*****************************************************************
// Removes duplicate
//
// param-1-List1 is passed to the function to remove duplicates
//
//*******************************************************************

void Linked_List:: removeDuplicates( ListNode *list1)
{
    struct ListNode *ptr1, *ptr2, *dup;
    ptr1 =list1;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
         of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
//*****************************************************************
// Deletes node with given value
//
// param-1- value - takes the given value and deletes it
//
//*******************************************************************

void Linked_List::deleteNode(int value){

    if (!head)
        return;
    ListNode *nodePtr; // to traverse the list
    if (head->data == value) { // if first node is num
        nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;
    }
    else {
        ListNode *previousNode; // trailing node pointer
        nodePtr = head;
        while (nodePtr && nodePtr->data != value) {
            previousNode = nodePtr; // save it!
            nodePtr = nodePtr->next; // advance it
        }
        if (nodePtr) { // num is found, set links + delete
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
//*****************************************************************
// adds node at the end with given value
//
// param-1- add data - takes the given value and adds it
//
//*******************************************************************

void Linked_List:: endAddNode(int addData){

    ListNode *newNode;
    newNode = new ListNode;
    newNode->data = addData;
    newNode->next = NULL;
    if (!head)
        head = newNode;
    else {
        ListNode *nodePtr;
        nodePtr = head;
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}
//*****************************************************************
// adds node at the beginning with given value
//
// param-1- add data - takes the given value and adds it in the beginning
//
//*******************************************************************

void Linked_List:: beginAddNode(int addData){

        ListNode *newNode;
        newNode = new ListNode;
        newNode ->next =NULL;
        newNode ->data = addData;
        newNode ->next = head;
        head = newNode;

}
//*****************************************************************
// prints the list in reverse
// param 1- list takes the list and prints in reverse
//*******************************************************************

void Linked_List:: reverse_print(ListNode* list)
{
    if (list!= NULL)
    {
        reverse_print(list->next);
        std::cout << list->data << ' ';
    }
}
//*****************************************************************
// counts the number of elements
// param 1 - list - takes the list and counts the elements
//*******************************************************************

void Linked_List:: getCount(ListNode* list)
{
    int count = 0;  // Initialize count
    ListNode* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    cout << count;
}

int main () {

  // creates four different list
    Linked_List list1;
    Linked_List list2;
    Linked_List list3;
    Linked_List list4;

    cout << "Welcome to my Singly LL Program" << endl << endl;
// filling list one and list two with random integers 1-25
    for (int i=0; i< 15; i++){
        list1.createList(rand()%26);
    }
    for (int i=0; i< 15; i++){
        list2.createList(rand()%26);
    }
    cout << "List 1" << endl;

    list1.printList();
    cout << endl << "List 2" << endl;
    list2.printList();
    cout << endl;

    list3 = list1;
    list3.mergeList(list1.head, list2.head);
    cout << "List 3 " << endl;
    list3.printList_list3();
    cout<<endl;
    list4 = list3;

    list4.removeDuplicates(list3.head);
    cout <<"List 4" << endl;
    list4.printList();
    list4.endAddNode(88);
    list4.endAddNode(99);
    list4.beginAddNode(200);
    list4.beginAddNode(100);
    cout <<endl << "List 4 added nodes" << endl;
    list4.printList();
    cout << endl << "List 4 element count is: ";
    list4.getCount(list4.head);
    list4.deleteNode(100);
    list4.deleteNode(99);
    cout << endl << "List 4 with deleted nodes" << endl;
    list4.printList();
    cout <<endl << "List 4 reversed" << endl;
    list4.reverse_print(list4.head);
    cout << endl << endl << "This Simple LL program is implemented by:\n"
    " Mesut Apil - March 27th, 2019" << endl << endl;

    return 0;

}




