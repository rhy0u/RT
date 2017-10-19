/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 02:57:29 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/10/19 02:57:08 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <gtk/gtk.h>
# include <SDL2/SDL.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# define L 1280
# define H 720
# define LIM 1000
# define SPHERE 1
# define CONE 2
# define CYL 3
# define PLANE 4
# define DISK 5
# define SPOT 6
# define DAM 7

static char *filename;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32			*pixels;
}					t_sdl;

typedef struct		s_thread
{
	SDL_Thread		*thread;
	SDL_mutex		*mutex;
}					t_thread;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_obj
{
	int				name;
	t_xyz			rot;
	t_xyz			trans;
	t_xyz			pos;
	t_xyz			n;
	float			radius;
	float			a;
	float			b;
	float			c;
	float			t1;
	float			t2;
	float			tcut;
	float			t;
	t_xyz			color;
	t_xyz			inter;
	t_xyz			normal_inter;
	t_xyz			inter_o;
	t_xyz			normal_inter_o;
	t_xyz			v;
	float			specular;
	float			cutonoff;
	float			cutisreal;
	t_xyz			cut;
	t_xyz			cutnorm;
	struct s_obj	*next;
	float			dc;
	float			dw;
}					t_obj;

typedef struct		s_ray
{
	t_xyz			eye;
	t_xyz			dir;
	t_xyz			rot;
	t_xyz			trans;
	float			t;
	t_xyz			color;
	t_obj			*obj;
}					t_ray;

typedef struct		s_cam
{
	t_xyz			pos;
	t_xyz			look_at;
	t_xyz			trans;
	t_xyz			rot;
	t_xyz			up_vec;
	t_xyz			right_vec;
	t_xyz			vec_dir;
	t_xyz			view_plane_up_left;
	float			ratio;
	float			width;
	float			height;
	float			xindent;
	float			yindent;
}					t_cam;

typedef struct		s_spot
{
	t_xyz			pos;
	t_xyz			trans;
	t_xyz			rot;
	t_xyz			dir;
	t_xyz			color;
	float			diffuse;
	float			specular;
	float			light_to_obj_dist;
	float			light_to_inter_dist;
	t_xyz			i;
	struct s_spot	*next;
}					t_spot;

typedef struct		s_scene
{
	t_spot			*spot;
	t_cam			cam;
	float			ambiante;
	t_obj			*obj;
	int				filter;
	int				res;
}					t_scene;

typedef struct		s_sdlpp
{
	t_scene			*scene;
	t_sdl			*sdl;
}					t_sdlpp;

void				ft_res(t_sdl *sdl, t_scene *scene);
void				ft_changefilter(t_sdl *sdl, t_scene *t_sdl);
t_xyz				filter(t_xyz color, int filter);
void 				ft_cut(t_ray ray, t_obj *s);
t_xyz 				ft_damcolor(t_obj *s);
void				recuperer_chemin(GtkWidget *bouton, GtkWidget *file_selection);
void				quitter(GtkWidget* widget);
void				creer_file_selection(GtkWindow *win);
Uint32				rgb(t_xyz color);
int					ft_sphere(t_ray r, t_obj *s);
int					ft_cylindre(t_ray r, t_obj *c);
int					ft_cone(t_ray r, t_obj *co);
int					ft_disk(t_ray ray, t_obj *obj);
int					ft_plane(t_ray ray, t_obj *obj);
int					ft_damier(t_ray ray, t_obj *obj);
void				ft_scene(t_sdl *sdl, t_scene *scene);
void				ft_get_scene(t_scene *scene, int fd);
t_xyz				get_xyz(char *str);
float				get_radius(char *str);
float				get_float(char *str);
void				get_cam(t_scene *s, char *str);
t_spot				*spot(char *str);
t_obj				*new_list(void);
void				list_push_back(t_obj **li, t_obj *new_obj);
void				list_add_spot(t_spot **li, t_spot *new_spot);
t_obj				*list_damier(char *str);
t_obj				*list_sphere(char *str);
t_obj				*list_cone(char *str);
t_obj				*list_cyl(char *str);
t_obj				*list_plane(char *str);
t_obj				*list_disk(char *str);
t_obj				*list_spot(char *str);
t_xyz				ft_camera(t_scene *s, t_cam c, float x, float y);
void				ft_cal_vec_cam(t_scene *s, t_cam *c);
void				ft_normal(t_xyz *vec);
float				ft_dot(t_xyz a);
t_xyz				ft_sub_vec(t_xyz a, t_xyz b);
t_xyz				ft_mul_vec_scal(t_xyz a, float b);
t_xyz				ft_div_vec(t_xyz a, t_xyz b);
t_xyz				ft_add_vec(t_xyz a, t_xyz b);
t_xyz				ft_mul_vec(t_xyz a, t_xyz b);
t_xyz				ft_cross_vec(t_xyz a, t_xyz b);
float				ft_magnitude_vec(t_xyz a);
float				ft_prod_scal(t_xyz a, t_xyz b);
t_xyz				ft_vect(float x, float y, float z);
int					ft_inter_obj(t_scene *s, t_ray *ray);
int					ft_get_inter(t_ray *ray, t_obj *obj);
void				ft_light(t_scene *s, t_ray *ray);
t_ray				ray_virt(t_ray r, t_obj *obj);
t_xyz				rot_all(t_xyz vect, float ax, float ay, float az);
void				deg_to_rad(t_xyz *a);
t_xyz				rotation_z(t_xyz vect, float a);
t_xyz				rotation_y(t_xyz vect, float a);
t_xyz				rotation_x(t_xyz vect, float a);
t_xyz				get_rad(char *str);
float				get_radius_rad(char *str);
t_xyz				rot_all_inv(t_xyz vect, float ax, float ay, float az);
t_obj				*free_obj(t_obj **obj);
t_spot				*free_spot(t_spot **spot);
void				free_all(t_scene *scene, t_sdl *sdl);
t_xyz				get_pos(char *str, t_xyz trans);
void 				ft_save(t_sdl *sdl);
void 				ft_movecam(t_sdl *sdl, t_scene *scene);


#endif
