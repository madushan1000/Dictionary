/* dictionary.c
Author: Weerawardhana J.L.M.N. E/10/389
*/

#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

dict* new_dictionary()
{
	dict *head;
	head = malloc(sizeof(dict));
	head -> key = 0;
	head -> value = 0;
	head -> next = NULL;
	return head;
}

int add_item(dict* dictionary, int key)
{
	dict *temp,*prev;
	while(dictionary)
	{
		
		if(dictionary -> key == key)
		{
			dictionary -> value +=1;
			return 1;
		}
		prev = dictionary;
		dictionary = dictionary -> next;
	}
	temp = malloc(sizeof(dict));
	if(!sizeof(temp))
	{
		return 0;
	}
	temp -> key = key;
	temp -> value = 1;
	temp -> next = 0;
	prev -> next = temp;
	
	return 1;
}

void sort_by_value(dict* dictionary)
{
	int swapped = 1;
	dict *temp,*head;
	temp = malloc(sizeof(dict));
	head = dictionary;
	while(swapped)
	{
		dictionary = head;

		while(dictionary)
		{
			swapped = 0;
			if(dictionary -> next)
			{
				if(dictionary -> value < dictionary -> next -> value)
				{
					*temp = *dictionary;
					dictionary -> key = dictionary -> next -> key;
					dictionary -> value = dictionary -> next -> value;
					dictionary -> next -> key = temp -> key;
					dictionary -> next -> value =temp -> value;
					swapped = 1;
				}
			}
			dictionary = dictionary -> next;
		}
	}
}

unsigned int get_value_by_position(dict* dictionary, int position)
{
	int i=0;
	while(dictionary)
	{
		if(i == position)
			return dictionary -> value;
		dictionary = dictionary -> next;
		i+=1;
	}
	return 0;
}

int get_key_by_position(dict* dictionary, int position)
{
	int i=0;
	while(dictionary)
	{
		if(i == position)
			return dictionary -> key;
		dictionary = dictionary -> next;
		i+=1;
	}
	return 0;
}