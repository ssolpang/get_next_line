/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:52:07 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/13 20:54:31 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		else
			i++;
	}
	return (0);
}

char	*read_line(int fd, char *temp)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (i && !check_newline(buf))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[BUFFER_SIZE] = 0;
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*the_rest(char *temp, int i)
{
	char	*str;
	int		temp_len;

	temp_len = ft_strlen(temp);
	str = (char *)malloc(sizeof(char) * (temp_len - i));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &temp[i + 1], temp_len - i);
	free(temp);
	return (str);
}

char	*cut_line(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, temp, i + 2);
	temp = the_rest(temp, i);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line(fd, temp);
	if (!temp)
		return (NULL);
	line = cut_line(temp);
	return (line);
}
