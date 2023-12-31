#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int njoro_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int printisha_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int printisha_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printisha_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printisha_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int printisha_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int printisha_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int pata_flags(const char *format, int *i);
int pata_width(const char *format, int *i, va_list list);
int pata_precision(const char *format, int *i, va_list list);
int pata_size(const char *format, int *i);

/*Function to print string in reverse*/
int printisha_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int printisha_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handler_kamba(char c, char buffer[],
	int flags, int width, int precision, int size);
int andika_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int andikisha_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_nambari(char buffer[], int is_negative, int i, int flags, int width, int precision, int size);

int andika_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_mwangi(char);
int mimi_huniambii_code(char, char[], int);
int is_nambari(char);

long int converter_mzee(long int num, int size);
long int converter_mtoto(unsigned long int num, int size);

#endif
