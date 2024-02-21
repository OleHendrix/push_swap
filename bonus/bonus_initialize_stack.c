/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_initialize_stack.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 17:43:21 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/02/13 13:26:56 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_addnode(t_stack **a, int nbr, char **argv, bool checkarray)
{
	t_stack	*newnode;
	t_stack	*lastnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
	{
		freestack(*a);
		freearray(argv, checkarray);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	newnode->value = nbr;
	newnode->next = NULL;
	if (*a == NULL)
	{
		*a = newnode;
		newnode->prev = NULL;
		return ;
	}
	lastnode = *a;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->next = newnode;
	newnode->prev = lastnode;
}

int	checkrepetion(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->value == nbr)
			return (ft_putstr_fd("Error\n", 2), 1);
		a = a->next;
	}
	return (0);
}

int	checkargv(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	if (argv[i] == '\0')
		return (1);
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		k;
	long	nb;

	i = 0;
	k = 0;
	nb = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			k++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	if (k == 1)
		nb = -nb;
	return (nb);
}

int	ft_stackinnit(t_stack **a, char **argv, int argc, bool checkarray)
{
	int		i;
	long	nbr;

	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
		{
			ft_putstr_fd("Error\n", 2);
			return (freearray(argv, checkarray), 0);
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || checkargv(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (freearray(argv, checkarray), 0);
		}
		nbr = ft_atoi(argv[i]);
		if (checkrepetion(*a, nbr) == 1)
			return (freearray(argv, checkarray), 0);
		ft_addnode(a, nbr, argv, checkarray);
		i++;
	}
	freearray(argv, checkarray);
	return (1);
}
