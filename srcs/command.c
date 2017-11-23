/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:18:23 by frmarinh          #+#    #+#             */
/*   Updated: 2017/11/23 10:18:27 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_command		*new_command(char *name)
{
	t_command	*command;

	if (!(command = (t_command*)malloc(sizeof(struct s_command))))
		return (NULL);
	command->name = ft_strdup(name);
	command->next = NULL;
	return (command);
}
