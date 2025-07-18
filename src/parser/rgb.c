// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   rgb.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/17 15:59:52 by dteruya           #+#    #+#             */
// /*   Updated: 2025/07/18 01:43:58 by gcesar-n         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/cub3d.h"

// static bool	parse_rgb(int nbr)
// {
// 	if (nbr < 0)
// 		return (false);
// 	if (nbr > 255)
// 		return (false);
// 	return (true);
// }

// static int	strchaaaaar(const char *s, int c, int index)
// {
// 	int	i;

// 	i = index;
// 	while (s[i] != '\0' && !is_wspace(s[i]) && s[i] != '\n')
// 	{
// 		if (s[i] == (unsigned char)c)
// 		return (i);
// 		i++;
// 	}
// 	return (0);
// }

// static char	*ft_strduuup(const char *s)
// {
// 	int		i;
// 	char	*dest;

// 	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
// 	if ((dest == NULL) || (s == NULL))
// 		return (NULL);
// 	i = 0;
// 	while (s[i] != '\0' && s[i] != '\n')
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// static char	*outrafuncao(char *str, int *i)
// {
// 	char	*nbr;

// 	nbr = ft_substr(str, *i, strchaaaaar(str, ',', *i) - *i);
// 	if (parse_rgb(ft_atoi(nbr)))
// 	{
// 		free(nbr);
// 		nbr = ft_substr(str, *i, strchaaaaar(str, ',', *i) - *i + 1);
// 		return (nbr);
// 	}
// 	if (nbr != NULL)
// 		free(nbr);
// 	return (NULL);
// }

// static void	init_floor(t_info *info, int *i, char *line)
// {
// 	int		count;
// 	char	*tmp;
// 	char	*potato;

// 	tmp = NULL;
// 	potato = "";
// 	count = 0;
// 	while (count < 3)
// 	{
// 		while (is_wspace(line[*i]))
// 			(*i)++;
// 		if (outrafuncao(line, i) != NULL)
// 		{
// 			tmp = ft_strduuup(outrafuncao(line, i));
// 			*i += (int)ft_strlen(tmp);
// 			potato = ft_strjoin(potato, tmp);
// 			free(tmp);
// 			count++;
// 		}
// 		else
// 			return ;
// 	}
// 	info->floor_color = potato;
// }

// static void	init_ceiling(t_info *info, int *i, char *line)
// {
// 	int		count;
// 	char	*tmp;
// 	char	*potato;

// 	tmp = NULL;
// 	potato = "";
// 	count = 0;
// 	while (count < 3)
// 	{
// 		while (is_wspace(line[*i]))
// 			(*i)++;
// 		if (outrafuncao(line, i) != NULL)
// 		{
// 			tmp = ft_strduuup(outrafuncao(line, i));
// 			*i += (int)ft_strlen(tmp);
// 			potato = ft_strjoin(potato, tmp);
// 			free(tmp);
// 			count++;
// 		}
// 		else
// 			return ;
// 	}
// 	info->ceiling_color = potato;
// }

// void	init_rgb(t_info *info, int *i, char *line, char c)
// {
// 	(*i)++;
// 	if (c == 'F')
// 	{
// 		init_floor(info, i, line);
// 		printf("\nDEBUG: F color:  %s\n", info->floor_color);
// 	}
// 	else if (c == 'C')
// 	{
// 		init_ceiling(info, i, line);
// 		printf("\nDEBUG: C color: %s\n", info->ceiling_color);
// 	}
// }
