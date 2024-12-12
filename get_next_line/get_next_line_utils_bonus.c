/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:08:39 by slakhrou          #+#    #+#             */
/*   Updated: 2024/12/09 20:13:02 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char	*s1)
{
	char	*copy;
	int		i;
	size_t	s1_len;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	copy = (char *) malloc ((s1_len + 1) * sizeof (char));
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*str_f;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str_f = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!str_f)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_f[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str_f[i++] = s2[j++];
	str_f[i] = '\0';
	return (str_f);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (*p == (char)c)
		return (p);
	return (NULL);
}

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= start + len)
		str = (char *) malloc ((ft_strlen(s) - start + 1) * sizeof (char));
	else
		str = (char *) malloc ((len + 1) * sizeof (char));
	if (str == NULL)
		return (NULL);
	while (j < len && s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
