/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:56:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/11 22:18:43 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_deque *deque)
{
	t_node	*node;

	node = NULL;
	if (deque->remain_elements < 2)
		write(-1, "Error\n", 7);
	node = remove_node_head(deque);
	add_node_tail(deque, node->num);
}

void	exec_rotate(int flag, t_deque *a, t_deque *b)
{
	if (flag == A)
	{
		ft_rotate(a);
		write(1, "ra\n", 4);
	}
	else if (flag == B)
	{
		ft_rotate(b);
		write(1, "rb\n", 4);
	}
	else if (flag == BOTH)
	{
		ft_rotate(a);
		ft_rotate(b);
		write(1, "rr\n", 4);
	}
	else
		write(-1, "Error\n", 7);
}
