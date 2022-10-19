/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:37:44 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/07 15:48:54 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_zero(t_deque *deque, t_node *new_node, int flag)
{
	if (flag == ADD)
	{
		deque->head = new_node;
		deque->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	if (flag == DEL)
	{
		write(-1, "Error\n", 7);
		exit(0);
	}
}

void	add_node_head(t_deque *deque, int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (deque->remain_elements == 0)
		count_zero(deque, new_node, ADD);
	else
	{
		if (deque->dat[num] == 1)
			write(-1, "Error\n", 7);
		deque->head->prev = new_node;
		new_node->next = deque->head;
		deque->head = new_node;
		new_node->prev = NULL;
	}
	new_node->num = num;
	deque->dat[num] = 1;
	deque->remain_elements++;
}

void	add_node_tail(t_deque *deque, int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (deque->remain_elements == 0)
		count_zero(deque, new_node, ADD);
	else
	{
		if (deque->dat[num] == 1)
			write(-1, "Error\n", 7);
		deque->tail->next = new_node;
		new_node->prev = deque->tail;
		deque->tail = new_node;
		new_node->next = NULL;
	}
	new_node->num = num;
	deque->dat[num] = 1;
	deque->remain_elements++;
}

t_node	*remove_node_head(t_deque *deque)
{
	t_node	*target;

	target = NULL;
	if (deque->remain_elements == 0)
		count_zero(deque, target, DEL);
	else
	{
		target = deque->head;
		deque->head = deque->head->next;
		target->next = NULL;
		if (deque->remain_elements == 1)
			deque->head = NULL;
		else
			deque->head->prev = NULL;
		deque->dat[target->num] = 0;
		deque->remain_elements--;
	}
	return (target);
}

t_node	*remove_node_tail(t_deque *deque)
{
	t_node	*target;

	target = NULL;
	if (deque->remain_elements == 0)
		count_zero(deque, target, DEL);
	else
	{
		target = deque->tail;
		deque->tail = deque->tail->prev;
		target->prev = NULL;
		if (deque->remain_elements == 1)
			deque->head = NULL;
		else
			deque->tail->next = NULL;
		deque->dat[target->num] = 0;
		deque->remain_elements--;
	}
	return (target);
}
