/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:55:55 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/26 22:01:27 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->head;
	while (node)
	{
		if (node->next)
		{
			if (node > node->next)
				return (FALSE);
			node = node->next;
		}
		else
			break ;
	}
	if (node->num == a->tail->num)
		return (TRUE);
	return (FALSE);
}

t_deque	*create_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->head = NULL;
	deque->tail = NULL;
	deque->remain_elements = 0;
	return (deque);
}

void	delete_deque(t_deque *deque)
{
	t_node	*node;

	node = deque->head;
	while (node)
	{
		free(node);
		node = node->next;
	}
	free(deque);
}

int	main(int argc, char **argv)
{
	t_deque	*deque;
	int		num;
	int		i;

	i = 1;
	if (check_args(argc, argv))
	{
		deque = create_deque();
		while (argv[i])
		{
			num = ft_atoi(argv[i]);
			add_node_tail(&deque, num);
			i++;
		}
	}
	delete_deque(deque);
	return (0);
}
