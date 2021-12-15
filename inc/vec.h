/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 14:29:33 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 15:44:08 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H
# define X		0
# define FW		0
# define Y		1
# define UP		1
# define Z		2
# define RT		2
# define W		3
# define U		0
# define V		1
# define R		0
# define G		1
# define B		2
# define A		3

typedef float		t_vec __attribute__ ((vector_size (16)));
typedef t_vec		t_cnd4;
typedef t_vec		t_mat[4];

t_vec	vec(const float num);
t_vec	vec2(const float x, const float y);
t_vec	vec3(const float x, const float y, const float z);
t_vec	vec4(const float x, const float y, const float z, const float w);
float	length(const t_vec vector);
t_vec	normalize(const t_vec vector);
t_vec	saturate(const t_vec vector);
t_vec	clamp(const t_vec vector, const float min, const float max);
float	dot(const t_vec v1, const t_vec v2);
t_vec	cross(const t_vec v1, const t_vec v2);
t_vec	vmin(const t_vec v1, const t_vec v2);
t_vec	vmax(const t_vec v1, const t_vec v2);
t_vec	arrange(const t_vec v1, const char *order);
t_vec	vmod(const t_vec v1, const float mod);
t_vec	vsin(const t_vec vector);
t_vec	vcos(const t_vec vector);
t_vec	vtan(const t_vec vector);
t_vec	vasin(const t_vec vector);
t_vec	vacos(const t_vec vector);
t_vec	vatan(const t_vec vector);
t_vec	vabs(const t_vec vector);
t_vec	vpow(const t_vec vector, const float power);
t_vec	qrotate(const t_vec point, const t_vec axis, const float angle);
t_vec	qmul(const t_vec q1, const t_vec q2);
void	mat_init(t_mat mat);
void	mmul(t_mat dst, const t_mat src);
t_vec	vmul(const t_mat matrix, const t_vec vector);
t_vec	dmul(const t_mat matrix, const t_vec vector);
void	mat_transpose(t_mat matrix);
void	mat_rot(t_mat matrix, const float angle, const t_vec axis);
void	mat_roty(t_mat matrix, const float angle);
void	mat_rotx(t_mat matrix, const float angle);

#endif
