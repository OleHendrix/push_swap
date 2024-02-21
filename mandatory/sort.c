/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:45:18 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/21 12:31:30 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(int argc)
{
	int	i;

	i = 0;
	if (argc == 0)
		return (1);
	while (argc != 0)
	{
		i++;
		argc = argc / 2;
	}
	return (i);
}

int	ft_check(int index, int count)
{
	while (count > 0)
	{
		index = index / 2;
		count--;
	}
	return (index % 2);
}

void	ft_tinysort(t_stack **a, t_stack **b, int argc)
{
	int	highest;

	highest = argc - 1;
	while (argc > 3)
	{
		if ((*a)->index < 2)
		{
			pb(a, b);
			argc--;
		}
		else
			ra(a);
	}
	if ((*a)->index == highest)
		ra(a);
	if ((*a)->next->index == highest)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
	pa(a, b, ft_stacksorted(a));
	pa(a, b, ft_stacksorted(a));
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	ft_radixsort(t_stack **a, t_stack **b, int argc)
{
	int	i;
	int	arguments;

	i = 0;
	while (i < ft_count(argc) && ft_stacksorted(a) == 0)
	{
		arguments = argc;
		while (arguments > 0)
		{
			if (ft_check((*a)->index, i) == 0)
				pb(a, b);
			else
				ra(a);
			arguments--;
		}
		while ((*b) != NULL)
			pa(a, b, 0);
		i++;
	}
}

void	ft_sort(t_stack **a, int argc)
{
	t_stack	*b;

	b = NULL;
	if (argc == 2)
	{
		sa(a);
		return (freestack(*a));
	}
	if (argc < 6)
		ft_tinysort(a, &b, argc);
	else
		ft_radixsort(a, &b, argc);
	freestack(*a);
}
