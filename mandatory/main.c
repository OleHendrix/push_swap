/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:43:56 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/13 14:16:06 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printstack(t_stack **a)
// {
// 	t_stack	*begin;

// 	begin = *a;
// 	while (begin != NULL)
// 	{
// 		printf("%d\n", begin->value);
// 		begin = begin->next;
// 	}
// }

int	ft_argcount(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	ft_stacksorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
	{
		if (current->index >= current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	bool	checkarray;

	a = NULL;
	checkarray = false;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (ft_putstr_fd("Error\n", 2), 0);
		checkarray = true;
		argc = ft_argcount(argv);
	}
	else
	{
		argv += 1;
		argc -= 1;
	}
	if (ft_stackinnit(&a, argv, argc, checkarray) == 0)
		return (freestack(a), 0);
	if (ft_stacksorted(&a))
		return (freestack(a), 0);
	ft_sort(&a, argc);
}
