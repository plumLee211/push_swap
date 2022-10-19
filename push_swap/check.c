/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:58:03 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/26 22:01:17 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max(t_deque *deque, t_value *data)
{
	t_node	*node;

	node = deque->head;
	data->min = node->num;
	data->max = 0;
	while (node)
	{
		if (data->min > node->num)
			data->min = node->num;
		if (data->max < node->num)
			data->max = node->num;
		node = node->next;
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	int			num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (sign * num);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}	
	return (i);
}

int	is_same_num(char **argv, int i)
{
	int	j;

	j = 1;
	if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		return (0);
	while (j < i)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (0);
		j++;
	}
	if (j == i)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{	
	int	i;

	i = 1;
	if (argc == 1)
		exit (0);
	while (i < argc)
	{
		if (!is_num(argv[i]) || !is_same_num(argv, i))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	if (i > 1)
		return (1);
	return (0);
}
