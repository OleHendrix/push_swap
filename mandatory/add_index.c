/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:38:19 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/12 18:12:08 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getindex(int *array, int value, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int	*sortarray(int *array, int argc)
{
	int	i;
	int	k;
	int	temp;

	i = 0;
	while (i < argc)
	{
		k = 0;
		while (k < argc - 1)
		{
			if (array[k] > array[k + 1])
			{
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
			}
			k++;
		}
		i++;
	}
	return (array);
}

int	ft_addindex(t_stack **a, int argc)
{
	t_stack	*current;
	int		*array;
	int		i;

	current = *a;
	array = malloc(argc * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < argc)
	{
		array[i] = current->value;
		i++;
		current = current->next;
	}
	array = sortarray(array, argc);
	current = *a;
	while (current != NULL)
	{
		current->index = getindex(array, current->value, argc);
		current = current->next;
	}
	free(array);
	return (1);
}
