#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	node* left;
	node* right;
}

node* root;

bool contains(int value);

int main(void)
{
	node n1 = {7,NULL,NULL};
	root = &n1;
	node n2 = {3, NULL, NULL};
	node n3 = {6, NULL, NULL};
	node n4 = {9, NULL, NULL};

	n1.left = &n2;
	n1.right = &n3;
	n3.right = &n4;

	node n5 = {6, NULL, NULL};
	n2.right = &n5;

	printf("%i", bool contains(6));
	return 0
}

bool contains(int value)
{
	node* temp = root;
	while (temp != NULL)
	{
		if (value == temp->value)
			return true;
		else if
			temp = (value > temp) ? temp->right : temp-> left;

	}

	return false;

}

