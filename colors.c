/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:53:45 by sataskin          #+#    #+#             */
/*   Updated: 2024/11/21 15:34:09 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*	FORMAT
		∗ R,G,B colors in range [0-255]: 255, 255, 255
*/

static void free_minirt_c(char **split, t_minirt *rt, char *error)
{
	free_split(split);
	free_minirt(rt, error);
}

static void	check_colors(char *values)
{
	int	i;
	int	comma;
	
	i = 0;
	comma = 0;
	while (values[i] != '\0')
	{
		if (ft_isdigit(values[i]))
			i++;
		else if (values[i] == ' ')
			i++;
		else if (values[i] == ',')
		{
			comma++;
			if (comma > 2)
				exit(1);
			i++;
		}
		else
		{
			exit (1);
		}
	}
}

void	add_colors(char *values, t_arg *new, t_minirt *rt)
{
	char	**colors;
	int		i;
	
	i = 0;
	check_colors(values);
	colors = ft_split(values, ',');
	if (!colors)
		free_minirt(rt, "Error: Malloc Fail\n");
	while (i < 3 && colors[i])
	{
		if (ft_strlen(colors[i]) > 3)
			free_minirt_c(colors, rt, "Error: Invalid Input\n");
		i++;
	}
	new->color.R = ft_atoi(colors[0]);
	if (new->color.R > 255 || new->color.R < 0)
		free_minirt_c(colors, rt, "Error: Invalid Input\n");
	new->color.G = ft_atoi(colors[1]);
	if (new->color.G > 255 || new->color.G < 0)
		free_minirt_c(colors, rt, "Error: Invalid Input\n");
	new->color.B = ft_atoi(colors[2]);
	if (new->color.B > 255 || new->color.B < 0)
		free_minirt_c(colors, rt, "Error: Invalid Input\n");
	free_split(colors);
}
