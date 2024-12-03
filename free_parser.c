/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:53:55 by sataskin          #+#    #+#             */
/*   Updated: 2024/11/21 15:13:17 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_minirt(t_minirt *freeable, char *error)
{
	t_arg	*temp;

	temp = NULL;
	if (error != NULL)
		write(2, error, ft_strlen(error));
	if (freeable->l_list != NULL)
	{
		temp = freeable->l_list->next;
		while (freeable->l_list != NULL)
		{
			free(freeable->l_list);
			if (temp == NULL)
				exit(1);
			freeable->l_list = temp;
			temp = temp->next;
		}
	}
}

void free_split(char **str)
{
	int i;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
