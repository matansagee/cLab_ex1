#ifndef __NODE_H
#define __NODE_H

#define CHAR_ARRAY_SIZE 100

typedef struct Node
{
	struct Node *next;
	int data;
} Node;

typedef struct List
{
	Node *firstNode;
	Node *lastNode; 
	int size_of_list;
} List;

List* CreateList();
Node* CreateNode();
Node* ReturnElementByData(List* list, int element_data, Node* previous_node);
Node* ReturnElementByIndex(List* list, int element_index, Node* previous_node);
void DeleteList(List* list);

//insert element I at end of list. Return 1 if succeed or 0 if List has bug. 
void AddElementAtEnd(List* list, int element_data);

//insert element I at start of list
void AddElemntAtStart(List* list, int element_data);

//insert element I after the first occurrence of element j.
//If j is not found, print an error and exit the program
void AddElemntIAfterJ(List* list, int element_i, int element_j);

//return the first index where element I is found, -1 if not found.
//The first element is index 1, the second is index 2, etc.
int ReturnIndexOfElement(List* list, int element_data);

//remove the element at the specified index.
//If index is too large return 0, else return 1.
void DeleteElementByIndex(List* list, int element_index);

//remove the first element with the specified data.
//If data does not exist return 0, else return 1.
int DeleteElementByData(List* list, int element_data);

//print the entire list.An empty list is printed as “[]”.
//A list with one element whose value is 1 is printed as “[1]”.
//A list with 3 elements, 1 - 3, is printed as “[1, 2, 3]”, with a space after each comma
void PrintList(List* list);

void StringToLower(char *str);
void CallSubFunctions(List *list,char *str);
#endif /* __NODE_H */


