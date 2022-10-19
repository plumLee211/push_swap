/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:37:44 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/28 21:01:04 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_zero(t_list *list, t_node *new_node, int flag)
{
	if (flag == ADD)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		list->tail = new_node;
	}
	if (flag == DEL)
	{
		write(-1, "Error!\n", 8);
		list->tail = NULL;
	}
}

t_list	*create_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->remain_elements = 0;
	return (list);
}

void	add_node(t_list *list, int n, int num)
{
	t_node	*before_node;
	t_node	*new_node;
	int		i;

	before_node = list->tail;
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->num = num;
	if (list->remain_elements == 0)
		count_zero(&list, &new_node, ADD);
	else
	{
		i = 0;
		while (i < n)
		{
			before_node = before_node->next;
			i++;
		}
		new_node->next = before_node->next;
		new_node->prev = before_node;
		new_node->next->prev = new_node;
		before_node->next = new_node;
		if (n == list->remain_elements)
			list->tail = new_node;
	}
	list->remain_elements++;
}

void	remove_node(t_list	*list, int n)
{
	t_node	*node;
	t_node	*target;
	int		i;

	i = 0;
	node = list->tail;
	target = list->tail;
	if (list->remain_elements == 0)
		count_zero(&list, &node, DEL);
	else
	{
		while (i < n)
		{
			node = node->next;
			i++;
		}
		target = node->next;
		node->next = target->next;
		target->next->prev = node;
		free(target);
		if (n == list->remain_elements - 1)
			list->tail = node;
		list->remain_elements--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;
	int		i;

	list = create_list();
	if (argc < 2)
		write(-1, "Error\n", 7);
	i = 1;
	while (argv[i])
	{
		if (ft_is_num(ft_atoi(argv[i])))
			add_node(&list, i - 1, ft_atoi(argv[i]));
		else
			write(-1, "Error\n", 7);
		i++;
	}
	return (0);
}

