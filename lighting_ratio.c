/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_ratio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:47:43 by sataskin          #+#    #+#             */
/*   Updated: 2024/11/21 15:27:57 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* FORMAT 
		 ambient lighting ratio in range [0.0,1.0]: 0.2
*/

void	add_lighting_ratio(char *str, t_arg *new, t_minirt *rt)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 3)
		free_minirt(rt, "Error: Invalid Input\n");
	new->l_rat = ft_atof(str);
	if (new->l_rat > 1.0 || new->l_rat < 0)
		free_minirt(rt, "Error: Invalid Input\n");
}
