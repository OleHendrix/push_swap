/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:42:39 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/12 17:46:53 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int check)
{
	if (check == 1 && (*b) == NULL)
		return ;
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_stack **a)
{
	reverserotate(a);
	ft_putstr_fd("rra\n", 1);
}
