/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 23:44:09 by olehendrix    #+#    #+#                 */
/*   Updated: 2024/02/16 15:58:32 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_stacksorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
	{
		if (current->value >= current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_handleaction(char *str, t_stack **a, t_stack **b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(b);
	else
		ft_putstr_fd("Invalid Argument\n", 1);
}

void	ft_checkinput(t_stack **a, t_stack **b)
{
	char	*str;

	if (ft_stacksorted(a) == 1)
	{
		write(1, "OK\n", 3);
		return (freestack(*a));
	}
	while (1)
	{
		str = get_next_line(0);
		if (!str || ft_strncmp(str, "exit\n", 5) == 0)
			break ;
		ft_handleaction(str, a, b);
		free(str);
	}
	free(str);
	if (ft_stacksorted(a) == 1 && (*b) == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freestack(*a);
	freestack(*b);
}

int	ft_argcount(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	checkarray;

	a = NULL;
	b = NULL;
	checkarray = false;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (ft_putstr_fd("Error", 2), 0);
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
	ft_checkinput(&a, &b);
}
