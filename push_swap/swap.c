/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:56:40 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/11 22:17:55 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_deque *deque)
{
	t_node	*fir;
	t_node	*sec;
	int		tem;

	if (deque->remain_elements < 2)
		write(-1, "Error\n", 7);
	tem = 0;
	fir = deque->head;
	sec = deque->head->next;
	tem = fir->num;
	fir->num = sec->num;
	sec->num = tem;
}

void	exec_swap(int flag, t_deque *a, t_deque *b)
{
	if (flag == A)
	{
		ft_swap(a);
		write(1, "sa\n", 4);
	}
	else if (flag == B)
	{
		ft_swap(b);
		write(1, "sb\n", 4);
	}
	else if (flag == BOTH)
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 4);
	}
	else
		write(-1, "Error\n", 7);
}
