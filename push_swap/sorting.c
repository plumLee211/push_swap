/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:25:56 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/18 21:31:49 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->head;
	while (node && node->next)
	{
		if (node->num > node->next->num)
			break ;
		node = node->next;
	}
}

t_value	*init_val(t_deque *deque)
{
	t_value	*data;

	data->ra = 0;
	data->rb = 0;
	data->pa = 0;
	data->pb = 0;
	min_max(deque, data);
	data->big_piv = (data->min + data->max) / 2;
	data->small_piv = (data->min + data->big_piv) / 2;
	return (data);
}

void	a_to_b(t_deque *a, t_deque *b, t_value *info)
{
	init_val(a);
	if (a->head->num > info->big_piv)
	{
		exec_rotate(A, a, b);
		info->ra++;
	}
	else
	{
		exec_push(B, a, b);
		info->pb++;
		if (b->head->num > info->small_piv)
		{
			exec_rotate(B, a, b);
			info->rb++;
		}
	}
}

void	b_to_a(t_deque *a, t_deque *b, t_value *info)
{
	init_val(b);
	if (b->head->num > info->big_piv)
	{
		exec_rotate(B, a, b);
		info->rb++;
	}
	else
	{
		exec_push(A, a, b);
		info->pa++;
		if (a->head->num > info->small_piv)
		{
			exec_rotate(A, a, b);
			info->ra++;
		}
	}
}
