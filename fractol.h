/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lj9 <lj9@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:52:24 by ymomen            #+#    #+#             */
/*   Updated: 2024/02/01 20:53:38 by lj9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# define HEIGHT 800
# define WIDTH 800

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_number
{
	double	r;
	double	i;
}	t_number;

typedef struct s_mg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mg;

typedef struct s_fractol
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_mg		img;
	float		range;
	int			etration;
	double		shift_x;
	double		shift_y;
	double		zoom;
	t_number	c;
	t_number	z;
	t_color		color;
	char		**av;
	int			is_julia;
	t_number	str;
	t_number	end;
}		t_facral;

/* FUNCTIONS */
double	ft_atof(char *str);
int		ft_isdigit(int c);
int		mouse_move(int x, int y, t_facral *frct);
/*double	scale(double old_min, double old_max, double new_min, 
	double new_max, double x);*/
double	scale(double old_max, double new_min, double new_max, double x);
int		end_fracts(t_facral *fract);
void	set_pixel(t_facral *fract, int x, int y);
void	events(t_facral *fract);
size_t	ft_strlen(char *str);
void	math(t_facral *fract);
void	init_windo(t_facral *fract, char *name);
void	error_and_exit(char *s, int exite);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	init_complix(t_facral *fract, int x, int y);
void	init_values(t_facral *fract);

#endif /*FRACTOL_H*/