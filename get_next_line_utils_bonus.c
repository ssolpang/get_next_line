/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:14 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/16 16:20:21 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(result + i) = *(s1 + i);
		i++;
	}
	*(result + i) = 0;
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		full_len;
	char	*new_str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (full_len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, (ft_strlen(s1) + 1));
	ft_strlcpy((new_str + ft_strlen(s1)), s2, (ft_strlen(s2) + 1));
	free(s1);
	return (new_str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (*(src + i) && i < (dstsize - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (len);
}
