/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 16:42:08 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/13 13:30:20 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include <stdbool.h>

# include "../Libft/libft.h"

typedef struct t_stack
{
	int				value;
	int				index;
	struct t_stack	*prev;
	struct t_stack	*next;
}	t_stack;

void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverserotate(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b, int check);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
long	ft_atol(const char *nptr);
void	printstack(t_stack **a);
int		getindex(int *array, int value, int argc);
int		*sortarray(int *array, int argc);
int		ft_addindex(t_stack **a, int argc);
void	ft_addnode(t_stack **a, int nbr, char **argv, bool checkarray);
int		checkrepetion(t_stack *a, int nbr);
void	freearray(char **argv, bool checkarray);
void	freestack(t_stack *a);
int		checkargv(char *argv);
int		ft_stackinnit(t_stack **a, char **argv, int argc, bool checkarray);
int		ft_argcount(char **argv);
int		ft_stacksorted(t_stack **a);
int		ft_count(int argc);
int		ft_check(int index, int count);
void	ft_sort(t_stack **a, int argc);
void	ft_tinysort(t_stack **a, t_stack **b, int argc);
void	ft_radixsort(t_stack **a, t_stack **b, int argc);

#endif