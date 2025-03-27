/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:21:44 by ehattab           #+#    #+#             */
/*   Updated: 2025/03/20 17:03:44 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int occ_z(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != 'P' && str[i] != 'E' && str[i] != '0'
			&& str[i] != 'C' && str[i] != '\n' && str[i] != '\0' && str[i] != 'F')
			error("There are invalid characters");
		else if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	error(char *str)
{
	ft_printf("error:\n%s\n", str);
	exit(1);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(const char *s)
{
	size_t	i;
	size_t	len;
	char	*src;
	char	*dest;

	i = 0;
	len = 0;
	src = (char *)s;
	while (src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr2(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	return (NULL);
}
