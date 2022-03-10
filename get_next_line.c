/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:52:07 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/10 23:57:52 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*read_line(int fd)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = read(fd, buf, BUFFER_SIZE);
	if (i == 0)
		return (NULL);
	buf[BUFFER_SIZE] = 0;
	return (buf);
}

char	*edit_line(char *line, int i)
{
	int		j;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		buf[j] = line[j];
		j++;
	}
	buf[j] = 0;
	return (buf);
}

char	*cut_line(char *line, char *remain)
{
	int		i;
	int		line_len;

	line = ft_strjoin(remain, line);
	i = 0;
	line_len = ft_strlen(line);
	while ((line[i] != '\n') && line[i])
		i++;
	if (i + 1 >= line_len)
		return (line);
	remain = (line + i + 1);
	line = edit_line(line, i);
	return (line);
}

int	check_newline(char *line, char *remain)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line[lin_len - 1] == '\n')
		return (1);
	else
	{
		remain = line;
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd);
	if (!line)
		return (NULL);
	line = cut_line(line, remain);
	if (check_newline(line, remain))
		return (line);
}
