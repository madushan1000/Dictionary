#include "dictionary.h"
#include <stdio.h>

void print_list(dict * list);

int main()
{
	dict *list,*head;
	list = new_dictionary();
	add_item(list,3);
	add_item(list,3);
	add_item(list,3);
	add_item(list,2);
	add_item(list,2);
	add_item(list,3);
	add_item(list,3);
	add_item(list,2);
	add_item(list,4);
	add_item(list,2);
	print_list(list);
	putchar('\n');
	sort_by_value(list);
	print_list(list);
	getch();
	return 0;
}

void print_list(dict * list)
{
	while(list)
	{
		printf("key %d val %d \n",list -> key,list -> value);
		list = list -> next;
	}
}