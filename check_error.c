/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:35 by crmunoz-          #+#    #+#             */
/*   Updated: 2025/02/11 15:26:31 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *argv)
{
	int		i;
	char	*cub;

	cub = ".cub";
	i = ft_strlen(argv) - 4;
	if (i < 4)
		return (-1);
	if (ft_strncmp(&argv[i], cub, 4) == 0)
		return (1);
	else
		ft_error('2');
	return (-1);
}

int	check_letters(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] != '1' && game->map[j][i] != '0'
				&& game->map[j][i] != 'W' && game->map[j][i] != 'N'
				&& game->map[j][i] != 'E' && game->map[j][i] != 'S'
				&& game->map[j][i] != ' ')
			{
				free_map(game->map);
				return (ft_error('2'));
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_error(char *argv, t_map *game)
{
	if (game->map && check_cub(argv) && check_letters(game))
		return (1);
	else
		return (-1);
}
