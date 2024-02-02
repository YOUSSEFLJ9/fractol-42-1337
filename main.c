/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/02/02 23:24:46 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void ff(void)
// {
// 	system("leaks fractol");
// }

	/* atexit(ff);*/
int	main(int ac, char **av)
{
	t_fractol	frc;

	frc.av = av;
	if (ac == 2 || ac == 4)
	{
		if (ac == 2 && !ft_strncmp(frc.av[1], "Mandelbrot", 11))
			frc.is_julia = 0;
		else if (ac == 2 && !ft_strncmp(frc.av[1], "Tricorn", 8))
			frc.is_julia = 2;
		else if (ac == 4 && !ft_strncmp(frc.av[1], "Julia", 6))
			frc.is_julia = 1;
		init_windo(&frc, frc.av[1]);
		math(&frc);
		mlx_loop(frc.mlx_ptr);
	}
	else
		error_and_exit(
			"USAGE:\n./fractol Mandelbrot\n./fractol Tricorn\n"
			"./fractol Julia x y\n", -9);
	return (0);
}
