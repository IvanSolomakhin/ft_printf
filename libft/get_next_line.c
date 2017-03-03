/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:36:57 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/02 18:04:06 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_line_and_cut_rest(char **line, char **rest)
{
	char	*old_rest;
	size_t	len;

	len = 0;
	while (*rest && (*rest)[len] && (*rest)[len] != '\n')
		len++;
	*line = ft_strsub(*rest, 0, len);
	if (*rest && (*rest)[len + 1] && (*rest)[len] != '\0')
	{
		old_rest = *rest;
		*rest = ft_strsub(*rest, len + 1, ft_strlen(*rest));
		ft_strdel(&old_rest);
		return (1);
	}
	ft_strdel(rest);
	return (0);
}

int		ft_read(int fd, char **rest)
{
	int		ret;
	char	*buffer;
	char	*temp;

	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = *rest;
		*rest = ft_strjoin(*rest, buffer);
		free(temp);
		if (*rest == NULL)
			*rest = ft_strdup(buffer);
	}
	if (ret < 0)
	{
		ft_strdel(&buffer);
		return (-1);
	}
	ft_strdel(&buffer);
	if (*rest == NULL)
		return (0);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*rest[M_FD];
	int			ret;

	ret = 1;
	if (!line || fd < 0 || BUFF_SIZE <= 0 || fd > M_FD)
		return (-1);
	if (rest[fd] == NULL)
		ret = ft_read(fd, &rest[fd]);
	if (ret == -1)
	{
		ft_strdel(&rest[fd]);
		return (-1);
	}
	if (ret == 0)
	{
		*line = NULL;
		ft_strdel(&rest[fd]);
		return (0);
	}
	get_line_and_cut_rest(line, &rest[fd]);
	return (1);
}
