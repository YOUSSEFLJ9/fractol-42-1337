/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:50:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/27 12:48:29 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_and_exit(char *s, int exite)
{
	if (exite == -9)
	{
		write(2, s, ft_strlen(s));
		exit(1);
	}
	perror(s);
	if (exite != 0)
		exit(exite);
}

int	end_fracts(t_facral *fract)
{
	mlx_destroy_image(fract->mlx_ptr,fract->img.img);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit(0);
}

void	init_complix(t_facral *fract, int x, int y)
{
	if (!ft_strncmp(fract->av[1], "Julia", 6))
	{
		fract->c.r = atof(fract->av[2]); 
		fract->c.i = atof(fract->av[3]);
		fract->z.r = (scale(0, WIDTH , -2, 2 , x)) * fract->zoom + fract->shift_x;
		fract->z.i = (scale(0, HEIGHT, 2, -2, y)) * fract->zoom + fract->shift_y;
	}
	else
	{
	fract->z.i = 0;
	fract->z.r = 0; 
	fract->c.r = (scale(0, WIDTH , -2, 2 , x)) * fract->zoom + fract->shift_x;
	fract->c.i = (scale(0, HEIGHT, 2, -2, y)) * fract->zoom + fract->shift_y;
	}
}