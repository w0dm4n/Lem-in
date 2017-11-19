/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 01:04:03 by frmarinh          #+#    #+#             */
/*   Updated: 2016/03/09 01:43:42 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_sqrt(float x)
{
	float	xhalf;
	int		i;
	int		*ti;
	float	*tf;

	xhalf = 0.5f * x;
	ti = (int*)&x;
	i = *ti;
	i = 0x5f375a86 - (i >> 1);
	tf = (float*)&i;
	x = *tf;
	x = x * (1.5f - xhalf * x * x);
	x = x * (1.5f - xhalf * x * x);
	return (1 / x);
}
