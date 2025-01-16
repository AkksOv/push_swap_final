/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-26 12:40:54 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-26 12:40:54 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

t_list	*new_node(int data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->prev = newnode;
	newnode->next = newnode->prev;
	return (newnode);
}

void	insert_end(t_list **head, int data)
{
	t_list	*newnode;
	t_list	*last;

	newnode = new_node(data);
	if (!newnode)
		return ;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		last = (*head)->prev;
		last->next = newnode;
		newnode->prev = last;
		newnode->next = *head;
		(*head)->prev = newnode;
	}
}

void	insert_begin(t_list **head, int data)
{
	t_list	*newnode;
	t_list	*temp;

	newnode = new_node(data);
	if (!newnode)
		return ;
	if (*head == NULL)
		*head = newnode;
	else
	{
		temp = *head;
		newnode->next = *head;
		newnode->prev = temp->prev;
		temp->prev->next = newnode;
		*head = newnode;
		temp->prev = *head;
	}
}

static void	deletenorm(t_list *temp, t_list **head, int key)
{
	t_list	*prev;

	prev = NULL;
	while (temp->data != key && temp->next != *head)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp->data == key)
	{
		prev->next = temp->next;
		temp->next->prev = prev;
		if (*head == temp)
			*head = temp->next;
		free(temp);
	}
}

void	delete_node(t_list **head, int key)
{
	t_list	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	if (temp->data == key)
	{
		if (temp->next == temp)
		{
			free(temp);
			*head = NULL;
			return ;
		}
		(*head) = temp->next;
		(*head)->prev = temp->prev;
		temp->prev->next = *head;
		free(temp);
		return ;
	}
	deletenorm(temp, head, key);
}
