/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:46:50 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/29 10:19:46 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_STRING_H
# define GET_STRING_H

# include "printf/printf.h"

char		*arg_get_string(t_printf *t);
wchar_t		*arg_get_wstring(t_printf *t);

#endif
