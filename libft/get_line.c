/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:26:10 by atoof             #+#    #+#             */
/*   Updated: 2023/04/14 14:40:33 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arr	*newlist(const int fd)
{
	t_arr	*new;

	new = (t_arr *)malloc(sizeof(t_arr));
	if (!new)
	{
		return (NULL);
	}
	new->fd = fd;
	new->rest = ft_strnew(BUFFER_SIZE);
	new->next = NULL;
	return (new);
}

static char	*checkrest(char **p_n, char *rest)
{
	char	*str;
	char	*p_n_temp;

	p_n_temp = ft_strchr(rest, '\n');
	if (p_n_temp != NULL)
	{
		*p_n = p_n_temp;
		str = ft_substr(rest, 0, *p_n - rest);
		ft_strcpy(rest, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

static void	process_buffer(char **line, char *rest, char *buf, int *rd)
{
	char	*p_n;
	char	*tmp;

	p_n = ft_strchr(buf, '\n');
	if (p_n != NULL)
	{
		ft_strcpy(rest, ++p_n);
		ft_strclr(--p_n);
	}
	tmp = ft_strjoin(*line, buf);
	if (!tmp || *rd < 0)
	{
		ft_strdel(&tmp);
		*rd = -1;
		return ;
	}
	ft_strdel(line);
	*line = tmp;
}

static int	read_and_append(const int fd, char **line, char *rest)
{
	char	buf[BUFFER_SIZE + 1];
	int		rd;

	rd = 1;
	while (*rest == 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0)
			break ;
		buf[rd] = '\0';
		process_buffer(line, rest, buf, &rd);
	}
	return (rd);
}

int	get_line(const int fd, char **line, char *rest)
{
	char	*p_n;
	int		rd;

	p_n = NULL;
	*line = checkrest(&p_n, rest);
	rd = read_and_append(fd, line, rest);
	if (ft_strlen(*line) || ft_strlen(rest) || rd)
		return (1);
	else
		return (0);
}
