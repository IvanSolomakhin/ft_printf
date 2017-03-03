/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:20:00 by isolomak          #+#    #+#             */
/*   Updated: 2016/12/01 23:20:01 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

static char	*ft_mal_word(char const *s, int start, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * len + 1);
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_loop(char **arr, char const *s, char c)
{
	int i;
	int len;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		if (s[i - 1] != c)
			arr[words++] = ft_mal_word(s, i - len, len);
	}
	arr[words] = 0;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char **arr;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!arr)
		return (NULL);
	arr = ft_loop(arr, s, c);
	return (arr);
}
