/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 19:28:14 by olehendrix    #+#    #+#                 */
/*   Updated: 2024/02/13 14:02:38 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include <stdbool.h>

# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct t_stack
{
	int				value;
	struct t_stack	*prev;
	struct t_stack	*next;
}	t_stack;

int		checkbuffer(char *buffer);
size_t	ft_strlen2(const char *str);
char	*ft_strjoin2(char *s1, char const *s2);
char	*ft_fillline(char *remainder);
char	*ft_cutremainder(char *remainder);
char	*ft_fillremainder(char *remainder);
char	*freeremainder(char *remainder, char *buffer);
char	*get_next_line(int fd);
int		ft_argcount(char **argv);
void	ft_checkinput(t_stack **a, t_stack **b);
void	ft_handleaction(char *str, t_stack **a, t_stack **b);
int		ft_stacksorted(t_stack **a);
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverserotate(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b, int check);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	freestack(t_stack *a);
void	freearray(char **argv, bool checkarray);
void	ft_addnode(t_stack **a, int nbr, char **argv, bool checkarray);
int		checkrepetion(t_stack *a, int nbr);
int		checkargv(char *argv);
long	ft_atol(const char *nptr);
int		ft_stackinnit(t_stack **a, char **argv, int argc, bool checkarray);

#endif