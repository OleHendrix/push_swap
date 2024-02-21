/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olehendrix <olehendrix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:07 by ohendrix          #+#    #+#             */
/*   Updated: 2024/02/12 22:46:24 by olehendrix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_fillremainder(char *remainder)
{
	remainder = malloc(1);
	if (!remainder)
		return (NULL);
	remainder[0] = '\0';
	return (remainder);
}

char	*freeremainder(char *remainder, char *buffer)
{
	free(remainder);
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			charsread;
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (freeremainder(remainder, NULL));
	if (!remainder)
		remainder = ft_fillremainder(remainder);
	charsread = 1;
	while (checkbuffer(remainder) != 1 && charsread != 0)
	{
		charsread = read(fd, buffer, BUFFER_SIZE);
		if (charsread == -1)
			return (remainder = freeremainder(remainder, buffer), NULL);
		buffer[charsread] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	line = ft_fillline(remainder);
	remainder = ft_cutremainder(remainder);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	char	*line = "a";

// 	fd = open("text.txt", O_RDONLY);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }