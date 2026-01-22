#ifndef LIBASM_H
# define LIBASM_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include <stdio.h>
# include <string.h>

//**********************************************//
//					DEFINES						//
//**********************************************//

//----------------- colors ----------------//
# define RED        "\033[0;31m"
# define GREEN      "\033[0;32m"
# define YELLOW     "\033[0;33m"
# define BLUE       "\033[0;34m"
# define MAGENTA    "\033[0;35m"
# define CYAN       "\033[0;36m"
# define WHITE      "\033[0;37m"

//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//----------------- libasm.c ----------------//
int		main(void);

//----------------- asm ----------------//
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

#endif