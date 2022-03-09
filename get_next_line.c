/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:52:07 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/09 19:21:28 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*remain(int fd)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = 0;
	return (buf);
}

char	*cut_line(char *line, char *remain)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	remain = *(line + i);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char	*line;

	if (BUFFER_SIZE =< 0)
		return (NULL);
	line = read_line(fd);
	line = cut_line(line, remain);
}
