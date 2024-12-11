/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:42:29 by sataskin          #+#    #+#             */
/*   Updated: 2024/12/11 12:33:14 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void print_ll(t_arg *ll)
{
	t_arg *temp;
	int		i = 0;

	temp = ll;
	while (temp != NULL)
	{
		if (temp->A == 1)
		{
			printf("\nnode %i is ambient lighting\n", i);
			printf("colors are\nR = %i\nG = %i\nB = %i\n", temp->color.R, temp->color.G, temp->color.B);
			printf("lighting ratio is = %f\n", temp->l_rat);
		}
		if (temp->C == 1)
		{
			printf("\nnode %i is camera\n", i);
			printf("coordinates are\nX = %f\nY = %f\nZ = %f\n", temp->coor.x, temp->coor.y, temp->coor.z);
			printf("3d normalized orientation vectors are\nX = %f\nY = %f\nZ = %f\n", temp->coor3d.x, temp->coor3d.y, temp->coor3d.z);
			printf("horizontal field view is = %i\n", temp->FOV);
		}
		if (temp->L == 1)
		{
			printf("\nnode %i is a light\n", i);
			printf("coordinates are\nX = %f\nY = %f\nZ = %f\n", temp->coor.x, temp->coor.y, temp->coor.z);
			printf("light brightness ratio is= %f\n", temp->bright);				
		}
		if (temp->sp == 1)
		{
			printf("\nnode %i is a sphere\n", i);
			printf("coordinates are\nX = %f\nY = %f\nZ = %f\n", temp->coor.x, temp->coor.y, temp->coor.z);
			printf("colors are\nR = %i\nG = %i\nB = %i\n", temp->color.R, temp->color.G, temp->color.B);
			printf("diameter is= %i\n", temp->diameter);			
		}
		if (temp->pl == 1)
		{
			printf("\nnode %i is a plane\n", i);
			printf("coordinates are\nX = %f\nY = %f\nZ = %f\n", temp->coor.x, temp->coor.y, temp->coor.z);
			printf("3d normalized orientation vectors are\nX = %f\nY = %f\nZ = %f\n", temp->coor3d.x, temp->coor3d.y, temp->coor3d.z);
			printf("colors are\nR = %i\nG = %i\nB = %i\n", temp->color.R, temp->color.G, temp->color.B);
		}
		temp = temp->next;
		i++;
	}
}

static void	rm_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0')
	{
		if (line[i] == '\t')
			line[i] = ' ';
		if (line[i] == '\n')
			line[i] = ' ';
		i++;
	}
}

static void	get_values(char *line, t_minirt *rt)
{
	char	**values;
	rm_whitespace(line);
	values = ft_split(line, ' ');
	if (!values)
		free_minirt(rt, "Error: MALLOC FAIL\n");
	if (ft_strcmp(values[0], "A") == 0)
		add_ambient(values, rt);
	else if (ft_strcmp(values[0], "C") == 0)
		add_camera(values, rt);
	else if (ft_strcmp(values[0], "L") == 0)
		add_light(values, rt);
	else if (ft_strcmp(values[0], "sp") == 0)
		add_sphere(values, rt);
	else if (ft_strcmp(values[0], "pl") == 0)
	{
		printf("add plane\n");
		add_plane(values, rt);
	}
	else if (ft_strcmp(values[0], "cy") == 0)
	{
		printf("going to add cylinder\n");
		//add_cylinder(values, rt);
	}
	else
	{
		//close(fd);
		free_minirt(rt, "ERROR: Invalid Input in FILE\n");
	}
	free_split(values);
}

void check_content(char *file, t_minirt *rt)
{
	int		fd;

	fd = open(file, O_RDONLY);
	rt->l_list = NULL;
	rt->line = NULL;
	while (1)
	{
		rt->line = get_next_line(fd);
		if (!rt->line)
			break;
		if (!ft_strcmp(rt->line, "\n"))
		{
			free(rt->line);
			continue ;
		}
		get_values(rt->line, rt);
		free(rt->line);
	}
	print_ll(rt->l_list);
	close(fd);
}

/*char	*get_line(int fd)
{
	char	*line;
	char	*str;
	char	*temp;

	line = ft_strdup("");
	if (!line)
		exit_none("Malloc fail");
	while (1)
	{
		str = get_next_line(fd);
		temp = line;
		if (str == NULL)
			break ;
		if (ft_strcmp(str, "\n") == 0)
			exit_dstr(line, str, "Extra new line");
		line = ft_strjoin(temp, str);
		if (!temp)
			exit_str(str, "Malloc fail");
		free(temp);
		free(str);
	}
	if (str)
		free(str);
	check_char(line);
	return (line);
}*/
