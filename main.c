/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/27 11:47:58 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_facral	fract;

	fract.av = av;
	if ((ac == 2 && !ft_strncmp(fract.av[1], "Mandelbrot", 11)))
	{
		init_windo(&fract, fract.av[1]);
		math(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else if (ac == 4 && !ft_strncmp(fract.av[1], "Julia", 6))
	{
		init_windo(&fract, fract.av[1]);
		math(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else
		error_and_exit("USAGE: ./fractol Mandelbrot or Julia x y\n", -9);
	return (0);
}