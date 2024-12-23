/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:29:16 by sataskin          #+#    #+#             */
/*   Updated: 2024/12/23 15:18:40 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	int x = coordinate;
	int y = coordinate;
	int z = coordinate;
	checking also for overflow
*/

static int	free_minirt_coor(char **coor)
{
	free_split(coor);
	return (1);
}

static int	check_coor(char *values)
{
	int	i;
	int	comma;
	
	i = 0;
	comma = 0;
	while (values[i] != '\0')
	{
		if (ft_isdigit(values[i]))
			i++;
		else if (values[i] == ' ' || values[i] == '.')
			i++;
		else if (values[i] == ',' && values[i + 1] != ',')
		{
			comma++;
			i++;
		}
		else if (values[i] == '-' && (i == 0 || values[i - 1] == ','))
			i++;
		else
			return (1);
	}
	if (comma != 2)
		return (1);
	return (0);
}

int	add_coor(char *values, t_arg *new)
{
	char	**coor;
	int		i;

	i = 0;
	if (check_coor(values) == 1)
		return (1);
	coor = ft_split(values, ',');
	if (!coor)
		return (1);
	new->coor.x = ft_atoi(coor[0]);
	new->coor.y = ft_atoi(coor[1]);
	new->coor.z = ft_atoi(coor[2]);
	if ((ft_strlen(coor[0]) > 4 || (new->coor.x < 0 && ft_strlen(coor[0]) > 5)) 
		|| (ft_strlen(coor[1]) > 4 || (new->coor.y < 0 && ft_strlen(coor[1]) > 5))
		|| (ft_strlen(coor[2]) > 4 || (new->coor.z < 0 && ft_strlen(coor[2]) > 5)))
		return(free_minirt_coor(coor));
	free_split(coor);
	return (0);
}
