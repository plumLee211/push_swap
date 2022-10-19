/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:54:08 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/11 22:19:54 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_deque *deque)
{
	t_node	*node;

	node = NULL;
	if (deque->remain_elements < 2)
		write(-1, "Error\n", 7);
	node = remove_node_tail(deque);
	add_node_head(deque, node->num);
}

void	exec_reverse_rotate(int flag, t_deque *a, t_deque *b)
{
	if (flag == A)
	{
		ft_reverse_rotate(a);
		write(1, "rra\n", 5);
	}
	else if (flag == B)
	{
		ft_reverse_rotate(b);
		write(1, "rrb\n", 5);
	}
	else if (flag == BOTH)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
		write(1, "rrr\n", 5);
	}
	else
		write(-1, "Error\n", 7);
}
