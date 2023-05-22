#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
}Node;

Node* allocNewNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->value = value;
	return newNode;
}

void printList(Node* head)
{
	for (Node* curr = head; curr != NULL; curr = curr->next)
	{
		printf("%d->", curr->value);
	}
	printf("\n");
}

void addValue(Node* head, int value)
{
	Node* curr = NULL;
	for (curr = head; curr->next != NULL; curr = curr->next);
	curr->next = allocNewNode(value);
}

Node* deleteValue(Node* head, int value)
{
	Node* curr = head;
	Node* prev = NULL;
	int count = 0;

	while (curr != NULL && curr->value != value)
	{
		prev = curr;
		curr = curr->next;
		count++;
	}
	if (curr == NULL)
	{
		printf("List is empty.");
		return head;
	}
	if (prev == NULL)
	{
		head = curr->next;
	}
	else
	{
		prev->next = curr->next;
	}
	free(curr);
	printf("Enter the position to delete: %d\n\n", value);
	printf("Move along the link: %d\n", count);
	return head;
}

int main()
{
	Node* head = NULL;

	int num;
	int value;

	while (1)
	{
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &num);

		if (num == 1)
		{
			printf("Enter the value to insert: ");
			scanf_s("%d", &value);
			if (head == NULL)
			{
				head = allocNewNode(value);
			}
			else
			{
				addValue(head, value);
			}
			printf("Value %d inserted.\n", value);
		}
		else if (num == 2)
		{
			printf("Enter the value to delete: ");
			scanf_s("%d", &value);
			head = deleteValue(head, value);
		}
		else if (num == 3)
		{
			printList(head);
		}
		else if (num == 0)
		{
			printf("Exit the program.\n");
			return 0;
		}
		else
		{
			printf("Invalid Menu. Please select again..\n");
		}
		printf("\n");
	}
}