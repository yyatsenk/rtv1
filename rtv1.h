#ifndef RTV1_H
# define RTV1_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR_MSG			"Usage:./RTv1 [filename]\n"
# define BAD_FILE_MSG		"Map should be 24x24\n"
# define BAD_BORDERS_MSG	"Bad borders\n"
# define EMPTY_FILE_MSG		"Empty file\n"
//# define HEIGHT				600
//# define WIDTH				1080



typedef struct		s_float_c
{
	float			x;
	float			y;
}					t_float_c;

typedef struct		s_int_c
{
	int				x;
	int				y;
}					t_int_c;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	int				*data;
	int				bpp;
	int				size_line;
	int				end;

}					t_mlx;

#endif