/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:58 by ajordan-          #+#    #+#             */
/*   Updated: 2024/11/21 17:51:15 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *s1)
{
	size_t	a;

	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr_GNL(const char *string, int c)
{
	unsigned char	to_find;

	if (!string)
		return (0);
	to_find = (unsigned char)c;
	while (*string != '\0')
	{
		if (*string == to_find)
			return ((char *)string);
		string++;
	}
	if (to_find == '\0')
		return ((char *)string);
	return (0);
}

char	*ft_strjoin_GNL(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
