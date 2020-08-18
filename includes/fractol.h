/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:04:02 by theinone          #+#    #+#             */
/*   Updated: 2020/02/24 13:08:20 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <math.h>
# include "keys.h"
#include <stdlib.h>

#include <stdio.h>

# define W_WIDTH	1200
# define W_HEIGHT	1200

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct	s_frac
{
	void		*mlx_ptr;
	void		*win;
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			max_iter;
	int			x;
	int			y;
	double		movex;
	double		movey;
	int			color;
	double		zoom;
}				t_frac;


#endif