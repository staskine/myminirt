/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:41:41 by sataskin          #+#    #+#             */
/*   Updated: 2024/12/27 12:32:24 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"



static int	arguments(char **values, int amount)
{
	int	i;

	i = 0;
	if (values == NULL)
		return (1);
	if (values[0] == NULL)
		return (1);
	while (values[i] != NULL)
		i++;
	if (i == amount)
		return (0);
	else
		return (1);
}

void	add_cylinder(char **values, t_minirt *rt)
{
	t_arg	*new;

	if (arguments(values, 6) > 0)
	{
		free_split(values);
		free_minirt(rt, "ERROR: Invalid Sphere\n");		
	}
	new = ft_calloc(1, sizeof(t_arg));
	if (!new)
	{
		free_split(values);
		free_minirt(rt, "Error: MALLOC FAIL\n");
	}
	new->next = NULL;
	new->cy = 1; 
	if (add_threed(values[2], new) == 1 || add_height(values[4], new) == 1
    || add_diameter(values[3], new) == 1 || add_coor(values[1], new) == 1
    || add_colors(values[5], new) == 1)
	{
		free_split(values);
		free(new);
		free_minirt(rt, "Error: Invalid Input\n");		
	}
	ft_lstadd_back_rt(&rt->l_list, new);
}


/* ∗ identifier: cy
∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255 
	
	*/