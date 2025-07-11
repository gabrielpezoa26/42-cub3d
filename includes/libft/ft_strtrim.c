/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:20 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/06/02 22:56:24 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	while (ft_strchr(set, *s1) && *s1 != '\0')
	{
		s1++;
	}
	index = ft_strlen(s1);
	while (index != 0 && ft_strchr(set, s1[index - 1]))
	{
		index--;
	}
	if (index == 0)
	{
		return (ft_strdup(""));
	}
	return (ft_substr(s1, 0, index));
}
