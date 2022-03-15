/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:48:03 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/15 17:07:39 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_newline(char *line)
{
	int	i;

	if (!line)
		return (0);
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
	while (i && !check_newline(temp))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = 0;
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*the_rest(char *temp)
{
	char	*str;
	int		temp_len;
	int		i;

	temp_len = ft_strlen(temp);
	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i] || (temp_len - i) == 1)
	{
		free(temp);
		return (NULL);
	}
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

	if (!temp[0])
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i])
		i -= 1;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, temp, i + 2);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	temp[fd] = read_line(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = cut_line(temp[fd]);
	temp[fd] = the_rest(temp[fd]);
	return (line);
}
