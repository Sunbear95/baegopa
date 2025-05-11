/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:33:12 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/08 21:47:28 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_freeall(char **temp, char **backup)
{
	if (*temp && **temp)
	{
		free(*temp);
		*temp = NULL;
	}
	if (*backup && **backup)
	{
		free(*backup);
		*backup = NULL;
	}
}

char	*cut_n_paste(char *str, char **backup, ssize_t i_cut)
{
	char	*temp;
	char	*line;
	char	*temp_backup;
	ssize_t	slen;

	if (*str == 0 && **backup)
		temp = *backup;
	else
		temp = str;
	line = gnl_substr(temp, 0, i_cut + 1);
	slen = gnl_strlen(temp);
	temp_backup = gnl_substr(temp, i_cut + 1, slen - i_cut - 1);
	if ((*str == 0 && **backup) || temp_backup)
	{
		gnl_freeall(&str, backup);
		*backup = temp_backup;
	}
	free(str);
	return (line);
}

char	*when_backup(char **backup)
{
	ssize_t	i_cut;

	i_cut = 0;
	if (*backup)
	{
		i_cut = chk_nl_eof(*backup, 0);
		return (cut_n_paste(gnl_strdup(""), backup, i_cut));
	}
	return (NULL);
}

ssize_t	chk_nl_eof(char *str, ssize_t flag)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (flag == 0)
		return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*temp;
	ssize_t		r_size;

	if (fd < 0 || GNL_BUFFERSIZE <= 0)
		return (free(backup), NULL);
	r_size = 1;
	temp = when_backup(&backup);
	buf = (char *)malloc(sizeof(char) * (GNL_BUFFERSIZE + 1));
	if (!buf)
		return (NULL);
	while (chk_nl_eof(temp, r_size) == -1)
	{
		r_size = read(fd, buf, GNL_BUFFERSIZE);
		if (r_size <= 0)
			break ;
		buf[r_size] = 0;
		temp = gnl_strjoin(&temp, buf);
	}
	free(buf);
	if (temp && r_size >= 0)
		return (cut_n_paste(temp, &backup, chk_nl_eof(temp, r_size)));
	gnl_freeall (&temp, &backup);
	return (NULL);
}
