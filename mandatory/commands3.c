/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:42:55 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/12 17:42:56 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b)
{
	reverserotate(b);
	ft_putstr_fd("rrb\n", 1);
}
