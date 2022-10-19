/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:53:54 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/11 22:16:16 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_deque *init, t_deque *pop)
{
	t_node	*node;

	if (pop->remain_elements == 0)
		write(-1, "Error\n", 7);
	node = remove_node_head(pop);
	add_node_head(init, node->num);
}

void	exec_push(int flag, t_deque *a, t_deque *b)
{
	if (flag == A)
	{
		ft_push(a, b);
		write(1, "pa\n", 4);
	}
	else if (flag == B)
	{
		ft_push(b, a);
		write(1, "pb\n", 4);
	}
	else
		write(-1, "Error\n", 7);
}
