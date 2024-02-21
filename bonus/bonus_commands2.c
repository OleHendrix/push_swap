/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olehendrix <olehendrix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:42:39 by ohendrix          #+#    #+#             */
/*   Updated: 2024/02/12 22:47:12 by olehendrix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	pa(t_stack **a, t_stack **b, int check)
{
	if (check == 1 && (*b) == NULL)
		return ;
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rra(t_stack **a)
{
	reverserotate(a);
}
