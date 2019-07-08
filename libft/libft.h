/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:02:55 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/08 03:15:06 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define L_MAX (9223372036854775807L)
# define L_MIN (-9223372036854775808L)
# define UL_MAX (18446744073709551615)
# define I_MAX (2147483647)
# define I_MIN (-2147483648)
# define UI_MAX (4294967295)
# define BUFF_SIZE (1024)
# define FT_PI (3.14159265358979323846264338327950288)
# define RAD2DEG (180.0 / FT_PI)
# define DEG2RAD (FT_PI / 180.0)

# define V3_ZERO (t_vector3){0.0, 0.0, 0.0}
# define V3_UP (t_vector3){0.0, 1.0, 0.0}
# define V3_RIGHT (t_vector3){1.0, 0.0, 0.0}
# define V3_FORWARD (t_vector3){0.0, 0.0, 1.0}
# define V3_DOWN (t_vector3){0.0, -1.0, 0.0}
# define V3_LEFT (t_vector3){-1.0, 0.0, 0.0}
# define V3_BACKWARD (t_vector3){0.0, 0.0, -1.0}
# define V3_ONE (t_vector3){1.0, 1.0, 1.0}
# define V3_NEGONE (t_vector3){-1.0, -1.0, -1.0}
# define V4_ZERO (t_vector4){0.0, 0.0, 0.0, 0.0}
# define V4_POINT (t_vector4){0.0, 0.0, 0.0, 1.0}
# define V4_ONE (t_vector4){1.0, 1.0, 1.0, 0.0}
# define QU_IDENTITY (t_ernion){1.0, 0.0, 0.0, 0.0}

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_array
{
	long long		*field;
	size_t			length;
	size_t			mem_size;
}					t_array;

typedef struct		s_tring
{
	char			*field;
	size_t			length;
	size_t			mem_size;
}					t_ring;

typedef struct		s_quaternion
{
	double			w;
	double			x;
	double			y;
	double			z;
}					t_ernion;

typedef struct		s_vector3f
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef struct		s_vector4f
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector4;

typedef struct		s_matrix4x4
{
	double			value[4][4];
}					t_matrix4x4;

/*
** Fills (source) with (length) bytes of (chr). Returns a pointer to the
** filled memory.
*/
void				*ft_memset(void *source, int chr, size_t length);

/*
** Fills (source) with (length) zero bytes.
*/
void				ft_bzero(void *source, size_t length);

/*
** Copies into (target) from (source) for (length) bytes. Returns
** a pointer to (target) start.
*/
void				*ft_memcpy(void *target, const void *source,
	size_t length);

/*
** Copies into (target) from (source) for (length) bytes or until (chr)
** is reached. If (chr) is reached, returns pointer to (target) after the
** copy of (chr). Else, a NULL is returned.
*/
void				*ft_memccpy(void *target, const void *source,
	int chr, size_t length);

/*
** Non-destructively copies into (target) from (source) for (length) bytes.
** Returns a pointer to (target).
*/
void				*ft_memmove(void *target, const void *source,
	size_t length);

/*
** Finds in (source) the first occurence (chr) until (length) bytes.
** Returns a pointer to the symbol in (source), or NULL if not found.
*/
void				*ft_memchr(const void *source, int chr, size_t length);

/*
** Compares (in1) and (in2) for (length) symbols. Returns (*in1 - *in2) of
** the first difference or 0, if areas are identical.
*/
int					ft_memcmp(const void *in1, const void *in2, size_t length);

/*
** Returns the ammount of symbols in (target) string, excluding \0.
*/
size_t				ft_strlen(const char *target);

/*
** Creates a new string, with content of (target). Returns a pointer
** to the new string.
*/
char				*ft_strdup(const char *target);

/*
** Copies into (target) string from (source) string. Returns a pointer
** to (target).
*/
char				*ft_strcpy(char *target, const char *source);

/*
** Copies into (target) string from (source) string at most (length) symbols.
** If (src) is less than (length) characters long, the remainders
** of (target) is filled with \0.
*/
char				*ft_strncpy(char *target, const char *source,
	size_t length);

/*
** Adds to (s1) string a copy of (s2) string, explicitly adding a \0.
** Returns a pointer to (s1).
*/
char				*ft_strcat(char *s1, const char *s2);

/*
** Adds to (s1) string a copy of (s2) string, not more
** than (length) characters, explicitly adding a \0. Returns a pointer to (s1).
*/
char				*ft_strncat(char *s1, const char *s2, size_t length);

/*
** Adds to (s1) string a copy of (s2) string, not more than (size) characters,
** size of target included, explicitly adding a \0. Returns random crap.
*/
size_t				ft_strlcat(char *target, const char *source, size_t size);

/*
** Finds in the (source) string the first occurence of (chr), including \0.
** Returns a pointer to the symbol in (source).
*/
char				*ft_strchr(const char *source, int chr);

/*
** Finds in the (source) string the last occurence of (chr), including \0.
** Returns a pointer to the symbol in (source).
*/
char				*ft_strrchr(const char *source, int chr);

/*
** Looks in the (haystack) string for the first occurence of (needle) string.
** Returns a pointer to the (needle) in (string), or NULL if none found.
*/
char				*ft_strstr(const char *haystack, const char *needle);

/*
** Looks in the (haystack) string for the first occurence of (needle) string,
** not more than (length) symbols. Returns a pointer to
** the (needle) in (string), or NULL if none found.
*/
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t length);

/*
** Compares (s1) string with (s2) string. Returns (*s1 - *s2) of the first
** difference or 0, if strins are identical.
*/
int					ft_strcmp(const char *s1, const char *s2);

/*
** Compares (s1) string with (s2) string, not more than (length) symbols.
** Returns (*s1 - *s2) of the first difference or 0, if strins are identical.
*/
int					ft_strncmp(const char *s1, const char *s2, size_t length);

/*
** Converts (str) into an integer. Trims leading space characters,
** supports +- symbols and leading 0s. Returns an int, an
** overflow int or 0/-1 if a long overflow happens.
*/
int					ft_atoi(const char *str);

/*
** Checks whether (chr) is in the 'a' - 'z' or 'A' - 'Z' range.
*/
int					ft_isalpha(int chr);

/*
** Checks whether (chr) is in the '0' - '9' range.
*/
int					ft_isdigit(int chr);

/*
** Checks whether (chr) is in the 'a' - 'z' / 'A' - 'Z' / '0' - '9' range.
*/
int					ft_isalnum(int chr);

/*
** Checks whether (chr) is in the 0 - 127 range.
*/
int					ft_isascii(int chr);

/*
** Checks whether (chr) is in the 32 - 126 range.
*/
int					ft_isprint(int chr);

/*
** Converts 'A' - 'Z' to 'a' - 'z'
*/
int					ft_tolower(int chr);

/*
** Converts 'a' - 'z' to 'A' - 'Z'
*/
int					ft_toupper(int chr);

/*
** Allocates a memory area of (size) bytes and fills it with zeroes.
** Returns a pointer to the new string.
*/
void				*ft_memalloc(size_t size);

/*
** Frees *(p) and sets it to NULL.
*/
void				ft_memdel(void **p);

/*
** Creates a \0 initialized string of (size) + 1.
*/
char				*ft_strnew(size_t size);

/*
** Frees *(string) and sets it to NULL
*/
void				ft_strdel(char **string);

/*
** Sets all symbols of (string) to 0
*/
void				ft_strclr(char *string);

/*
** For every symbol in (string) applies the function (*f).
*/
void				ft_striter(char *string, void (*f)(char*));

/*
** For every symbol in (string) applies the function (*f).
*/
void				ft_striteri(char *string, void (*f)(unsigned int, char*));

/*
** Creates a new string, of symbols (string), to which (*f) has been applied.
*/
char				*ft_strmap(char const *string, char (*f)(char));

/*
** Creates a new string, of symbols (string), to which (*f) has been applied.
*/
char				*ft_strmapi(char const *source,
	char(*f)(unsigned int, char));

/*
** Checks whether (s1) string and (s2) string are identical.
*/
int					ft_strequ(char const *s1, char const *s2);

/*
** Checks whether (s1) string and (s2) string are identical
** for (length) symbols.
*/
int					ft_strnequ(char const *s1, char const *s2, size_t length);

/*
** Creates a new string, cut from (string), starting
** from (start) position, (length) symbols in length.
*/
char				*ft_strsub(char const *string, unsigned int start,
	size_t length);

/*
** Creates a new string, that is a combination of (s1) string and (s2) string.
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
** Creates a new string from (string), that is trimmed of whitespaces, newlines
** and tabs.
*/
char				*ft_strtrim(char const *string);

/*
** Splits (string) divided by (chr) into an array of new strings.
** Return array is \0 terminated.
*/
char				**ft_strsplit(char const *string, char chr);

/*
** Converts (n) int to a string. Returns a pointer to the new string.
*/
char				*ft_itoa(int n);

/*
** Writes char (chr) to console.
*/
void				ft_putchar(char chr);

/*
** Writes (string) to console.
*/
void				ft_putstr(char const *string);

/*
** Writes (string) to console and adds a '\n'.
*/
void				ft_putendl(char const *string);

/*
** Writes int (num) to console.
*/
void				ft_putnbr(int num);

/*
** Writes char (chr) to (fd) file.
*/
void				ft_putchar_fd(char chr, int fd);

/*
** Writes (string) to console to (fd) file.
*/
void				ft_putstr_fd(const char *string, int fd);

/*
** Writes (string) to console to (fd) file.
*/
void				ft_putendl_fd(char const *string, int fd);

/*
** Writes int (num) to console to (fd) file.
*/
void				ft_putnbr_fd(int num, int fd);

/*
** Creates a new t_list with a copy of (content), copied by (content_size).
** Returns a pointer to the item.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** Applies (*del) to t_list's contents, then frees *(targetlst) and sets
** it to NULL.
*/
void				ft_lstdelone(t_list **targetlst,
	void (*del)(void*, size_t));

/*
** Applies (*del) to every t_list in the stack, then frees *(targetlst) and
** sets them to NULL.
*/
void				ft_lstdel(t_list **targetlst, void (*del)(void *, size_t));

/*
** Prepends stack (targetlst) with (new), without creating an item.
*/
void				ft_lstadd(t_list **targetlst, t_list *new);

/*
** For every item in (targetlst), appies (*f).
*/
void				ft_lstiter(t_list *targetlst, void (*f)(t_list *elem));

/*
** Creates a new list, of items (targetlst), to which (*f) has been applied.
*/
t_list				*ft_lstmap(t_list *targetlst, t_list *(*f)(t_list *elem));

/*
** Appends stack (targetlst) with (new), without creating an item.
*/
void				ft_lstaddend(t_list **targetlst, t_list *new);

/*
** Appends stack (targetlst) with a new t_list with a copy of (content),
** copied by (content_size). Returns 1 if successful, 0 otherwise.
*/
int					ft_lstunshift(t_list **targetlst, void const *content,
	size_t content_size);

/*
** Prepends stack (targetlst) with a new t_list with a copy of (content),
** copied by (content_size). Returns 1 if successful, 0 otherwise.
*/
int					ft_lstpush(t_list **targetlst, void const *content,
	size_t content_size);

/*
** Frees *(targetlst) and its content, setting the pointer to NULL.
*/
void				ft_lstclr(t_list **targetlst);

/*
** Frees *(targetlst) and its content, setting the pointer to NULL,
** or to t_list.next, if present.
*/
void				ft_lstclrsf(t_list **lst);

/*
** Removes the last item from stack (targetlst).
*/
void				ft_lstpop(t_list **targetlst);

/*
** Removes the first item from (targetlst).
*/
void				ft_lstshift(t_list **targetlst);

/*
** Removes every item in (targetlst).
*/
void				ft_lstnuke(t_list **targetlst);

/*
** Creates a new string from every element in (data). Returns a string,
** or NULL if unsuccessful.
*/
char				*ft_lsttostr(t_list *data);

/*
** Reads from file (fd) a single line, ending with \n, allocating a new
** string into *(line). Returns 1 on success, 0 on EOF, -1 on error.
*/
int					get_next_line(const int fd, char **line);

/*
** Counts power^2 of (number). Returns 0 if the result doesn't fit into an int.
*/
unsigned int		ft_power(int num);

/*
** Counts power^2 of (number). Returns 0 if the result doesn't fit into a long.
*/
unsigned long		ft_powerl(long num);

/*
** Counts square root of (number). Rounds up.
*/
int					ft_sqrt(unsigned int num);
int					ft_abs(int input);
void				*ft_realloc(void *source, size_t src_size,
	size_t new_size);
t_array				*arr_init(void);
char				arr_sizeup(t_array *array);
char				arr_push(t_array *array, long long num);
char				arr_unshift(t_array *array, long long num);
char				arr_set(t_array *array, size_t index, long long value);
long long			arr_get(t_array *array, size_t index);
long long			arr_top(t_array *array);
long long			arr_last(t_array *array);
size_t				arr_length(t_array *array);
long long			arr_pop(t_array *array);
long long			arr_shift(t_array *array);
char				arr_contains(t_array *array, long long val);
void				arr_iter(t_array *array, void (*f)(size_t, long long));
void				arr_iterv(t_array *array, void *user_data,
	void (*f)(size_t, long long, void *));
void				arr_itervv(t_array *arr, void *user_data1,
	void *user_data2, void (*f)(size_t, long long, void *, void *));
long long			arr_drop(t_array *array, size_t index);
size_t				arr_find(t_array *array, long long target);
long long			arr_find_destroy(t_array *arr, long long target);
char				arr_absorb(t_array *array, long long *source,
	size_t ammount);
char				arr_rabsorb(t_array *array, long long *source,
	size_t ammount);
char				arr_topsorb(t_array *array, long long *source,
	size_t ammount);
char				arr_rtopsorb(t_array *array, long long *source,
	size_t ammount);
t_array				*arr_start(long long *source, size_t ammount);
void				arr_clear(t_array *arr);
void				arr_destroy(t_array *array);
void				ft_putmem(void *ptr, size_t var_size, size_t len,
	size_t indent);
void				ft_putbyte(unsigned char c);
void				ft_putvar(void *ptr, size_t size);
void				ft_puthexbyte(unsigned char c);
void				ft_puthex(void *ptr, size_t var_size, size_t len,
	size_t indent);
void				ft_swap(int *a, int *b);
long long			ft_clamp(long long value, long long min, long long max);
double				ft_clampd(double value, double min, double max);
void				ft_swapd(double *a, double *b);
t_vector3			ft_v3add(t_vector3 a, t_vector3 b);
t_vector3			ft_v3subtract(t_vector3 a, t_vector3 b);
t_vector3			ft_v3multnum(t_vector3 a, double b);
t_vector3			ft_v3divnum(t_vector3 a, double b);
t_vector3			ft_v3normalize(t_vector3 a);
t_vector3			ft_v3cross(t_vector3 a, t_vector3 b);
t_vector3			ft_v3inverse(t_vector3 a);
t_vector3			ft_v4tov3(t_vector4 a);
t_vector3			ft_m4xv3(t_matrix4x4 matrix, t_vector3 vector);
t_vector3			ft_v3rotate(t_vector3 vector, t_ernion rotation);
t_vector3			ft_v3euleur(t_vector3 vector,
	double degrees_x, double degrees_y, double degrees_z);
t_vector3			ft_v3abs(t_vector3 a);
double				ft_v3magnitude(t_vector3 a);
double				ft_v3dot(t_vector3 a, t_vector3 b);
double				ft_v3dot2(t_vector3 a);
t_vector4			ft_m4xv4(t_matrix4x4 matrix, t_vector4 vector);
t_vector4			ft_v3tov4(t_vector3 a);
t_vector4			ft_v3tov4point(t_vector3 a);
t_matrix4x4			ft_m4zero(void);
t_matrix4x4			ft_m4identity(void);
t_matrix4x4			ft_m4transpose(t_matrix4x4 a);
t_matrix4x4			ft_m4multiply(t_matrix4x4 a, t_matrix4x4 b);
t_matrix4x4			ft_m4inverse(t_matrix4x4 in);
t_matrix4x4			ft_m4multnum(t_matrix4x4 a, double num);
t_matrix4x4			ft_qurotmatrix(t_ernion rot);
t_ernion			ft_qumultiply(t_ernion first, t_ernion second);
t_ernion			ft_qurotation(t_vector3 axis, double angle);
t_ernion			ft_queuler(double angle_x, double angle_y,
	double angle_z);
t_ernion			ft_quinverse(t_ernion a);
char				*ft_readfile(char *path);
#endif
