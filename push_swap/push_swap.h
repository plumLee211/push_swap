/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:37:46 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/03/26 21:41:04 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef struct s_deque
{
	int		remain_elements;
	int		*dat;
	t_node	*head;
	t_node	*tail;
}		t_deque;

typedef struct s_value
{
	int	big_piv;
	int	small_piv;
	int	min;
	int	max;
	int	ra;
	int	rb;
	int	pa;
	int	pb;

}		t_value;

# define TRUE		1
# define FALSE		0
# define ERROR		-1
# define ADD		0
# define DEL		1
# define A			1
# define B			2
# define BOTH		3

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

void	count_zero(t_deque *deque, t_node *new_node, int flag);
t_deque	*create_deque(void);

void	add_node_head(t_deque *deque, int num);
void	add_node_tail(t_deque *deque, int num);

t_node	*remove_node_head(t_deque *deque);
t_node	*remove_node_tail(t_deque *deque);

void	ft_swap(t_deque *deque);
void	exec_swap(int flag, t_deque *a, t_deque *b);

void	ft_push(t_deque *init, t_deque *pop);
void	exec_push(int flag, t_deque *a, t_deque *b);

void	ft_rotate(t_deque *deque);
void	exec_rotate(int flag, t_deque *a, t_deque *b);

void	ft_reverse_rotate(t_deque *deque);
void	exec_reverse_rotate(int flag, t_deque *a, t_deque *b);

int		ft_atoi(const char *str);
void	min_max(t_deque *deque, t_value *data);
int		is_num(char *str);
int		is_same_num(char **argv, int i);
int		check_args(int argc, char **argv);

#endif
