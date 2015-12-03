#include"list.h"
#include<stdio.h>
#include<stdlib.h>


void StringToLower(char *str)
{
	int i;
	for (i = 0;str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}

List* CreateList()
{
	List* new_list;
	new_list =(List*)malloc(sizeof(List));

	if (new_list == NULL)
		return NULL;

	new_list->firstNode = NULL;
	new_list->lastNode = NULL;
	new_list->size_of_list = 0;
	return new_list;
}

void AddElementAtEnd(List* list, int element_data)
{
	Node *new_node;
	do{
		new_node = CreateNode();
	} while (new_node == NULL);

	new_node->data = element_data;
	new_node->next = NULL;
	
	if (IsListEmpty(list))
	{
		list->firstNode = new_node;
		list->lastNode = list->firstNode;
	}
	else
	{
		list->lastNode->next = new_node;
		list->lastNode = new_node;
	}
		list->size_of_list++;
}

void AddElemntAtStart(List* list, int element_data)
{
	Node *TemporaryNode;
	Node *node_new;
	do{
		node_new = CreateNode();
	} while (node_new == NULL);

	node_new->data = element_data;
	node_new->next = NULL;
	
	if (IsListEmpty(list))
	{
		list->firstNode = node_new;
		list->lastNode = node_new;
	}
	else 
	{
		TemporaryNode = list->firstNode;
		list->firstNode = node_new;
		list->firstNode->next = TemporaryNode;
	}
	list->size_of_list++;
}

void AddElemntIAfterJ(List* list, int element_i, int element_j)
{
	Node *new_node;
	Node* current_node =list->firstNode;
	while (current_node->data != element_j)
	{
		current_node = current_node->next;
		if (current_node == NULL)
		{
			printf("ERROR!! , j not found");
			exit;
		}
	}
	
	do{
		new_node = CreateNode();
	} while (new_node == NULL);
	if (current_node->next == NULL)
	{
		list->lastNode = new_node;
	}
	new_node->data = element_i;
	new_node->next = current_node->next;
	current_node->next = new_node;

}

int ReturnIndexOfElement(List* list, int element_data)
{
	Node* current_node = list->firstNode;
	int index_of_element = 0;

	while (current_node != NULL)
	{
		if (current_node->data == element_data)
		{
			return index_of_element;
		}
		else
		{
			current_node = current_node->next;
			index_of_element++;
		}
	}
	return -1;
}

void DeleteElementByIndex(List* list, int element_index)
{
	Node* previous_node=NULL;
	Node* current_node = list->firstNode;
	int i;
	if (element_index > list->size_of_list)
	{
		printf("ERROR!! index is to large");
		exit;
	}
	if (current_node == NULL)
		return;
	if (current_node->next == NULL)
	{
		free(current_node);
		list->firstNode = NULL;
		return;
	}
	for (i = 0; i < element_index; i++)
	{
		previous_node = current_node;
		current_node = current_node->next;
	}
	previous_node->next = current_node->next;
	free(current_node);

}

void DeleteList(List* list)
{
	Node* current_node;
	Node* next_node;

	if (IsListEmpty(list))
		return;

	current_node = list->firstNode;
	next_node = current_node->next;

	while (current_node != NULL)
	{
		free(current_node);
		current_node = next_node;
		next_node = next_node->next;
	}
	
	free(list);
	printf("List has been deleted");
}

void PrintList(List* list)
{
	Node* current_node;
	current_node = list->firstNode;
	
	if (IsListEmpty(list))
	{
		printf("[]\n");
		return;
	}

	printf ("[");
	while (current_node->next != NULL)
	{
		printf("%d, ",current_node->data);
		current_node = current_node->next;
	}
	printf("%d]\n", current_node->data);
	
}

// Local functions
int IsListEmpty(List *list)
{
	return (list->firstNode == NULL)? 1 : 0;
}

Node* CreateNode()
{
	Node* new_node;
	new_node =(Node*)malloc(sizeof(Node));

	if (new_node == NULL)
		return NULL;

	new_node->next = NULL;
	new_node->data;
	return new_node;
}

Node* ReturnElementByData(List* list, int element_data, Node* previous_node)
{
	Node* current_node;

	current_node = list->firstNode;
	if (current_node->data == element_data)
	{
		previous_node = NULL;
		return current_node;
	}

	while (current_node != NULL)
	{
		previous_node = current_node;
		current_node = current_node->next;

		if (current_node->data == element_data)
		{
			return current_node;
		}
		else
			continue;
	}
	return NULL;
}

Node* ReturnElementByIndex(List* list, int element_index, Node* previous_node)
{
	Node* current_node;
	int index;
	previous_node = NULL;
	current_node = list->firstNode;
	
	if (element_index < 0)
	{
		printf("ERROR! Input index is illegal!");
		exit;
	}

	if (element_index == 0)
		return current_node;
		
	for (index = 1; index <= element_index; index++)
	{
		previous_node = current_node;
		current_node = current_node->next;

		if (current_node != NULL)
		{
			continue;
		}
		else
		{
			printf("ERROR!! Element index does not exist!");
			exit;
		}
	}
	return current_node;
}

// another funtions
int DeleteElementByData(List* list, int element_data)
{
	Node* node_to_del;
	Node* previous_node=NULL;

	node_to_del = ReturnElementByData(list, element_data, previous_node);
	if (node_to_del != NULL)
	{
		previous_node->next = node_to_del->next;
		free(node_to_del);
	}
	else
	{
		printf("Element does not exist!");
		return 0;
	}
	return 1;	 
}

void CallSubFunctions(List* list,char *str)
{
	char *arg1, *arg2, *arg3;
	arg1 = strtok(str," ");
	arg2 = strtok(NULL, " ");
	arg3 = strtok(NULL, " ");
	if (strcmp(arg1, "add_end")==0)
	{
		AddElementAtEnd(list, atoi(arg2));
		//printf("add_end\n");
	}
	else if (strcmp(arg1, "add_start")==0)
	{
		AddElemntAtStart(list, atoi(arg2));
		//printf("add_start\n");
	}
	else if (strcmp(arg1, "add_after")==0)
	{
		AddElemntIAfterJ(list, atoi(arg2), atoi(arg3));
		//printf("add_after\n");

	}
	else if (strcmp(arg1, "index")==0)
	{
		printf("%d\n",ReturnIndexOfElement(list, atoi(arg2)));
		////printf("index\n");

	}
	else if (strcmp(arg1, "del")==0)
	{
		DeleteElementByIndex(list, atoi(arg2));
		//printf("del\n");

	}
	else if (strcmp(arg1, "print")==0)
	{
		PrintList(list);
		//printf("print\n");

	}
}


