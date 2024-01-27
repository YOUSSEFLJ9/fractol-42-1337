/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:53:22 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/27 11:36:14 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	init_windo(t_facral *fract, char *name)
{
	fract->mlx_ptr = mlx_init();
	if (fract->mlx_ptr == NULL)
		error_and_exit("init_mlx", 1);
	fract->mlx_win = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, name);
	if (fract->mlx_win == NULL)
		error_and_exit("mlx_new_win", 1);
	fract->img.img = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (fract->img.img == NULL)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
		error_and_exit("mlx_new_img", 1);
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bits_per_pixel, &fract->img.line_length, &fract->img.endian);
	fract->etration = 50;
	fract->range = 4;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->zoom = 1.00;
	fract->color.b = 9;
	fract->color.g = 3;
	fract->color.r = 5; 
	events(fract);
}
