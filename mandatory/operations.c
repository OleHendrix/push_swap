/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:48:41 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/13 14:06:26 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	second = top->next;
	top->next = second->next;
	second->next = top;
	*stack = second;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*push;

	if ((*src) == NULL)
		return ;
	push = *src;
	*src = (*src)->next;
	push->next = *dst;
	*dst = push;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	reverserotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
