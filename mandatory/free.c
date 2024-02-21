/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:47:31 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/16 14:10:23 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_stack *a)
{
	t_stack	*next;

	while (a != NULL)
	{
		next = a->next;
		free(a);
		a = next;
	}
}

void	freearray(char **argv, bool checkarray)
{
	int	i;

	i = 0;
	if (checkarray == false || (!argv))
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
