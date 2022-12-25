#include<stdarg.h>

int print_argument(char format, va_list ap)
{
    int count;

    count = 0;
    if (format == '%')
        count = print_percent(format);
    else if (format == 'd' || format == 'i')
        count = print_di(format, ap);
    else if (format == 'u')
        count = print_u(format, ap);
    else if (format == 'x' || format == 'X' || format == 'p')
        count = print_xXp(format, ap);
    else if (format == 'c')
        count = print_c(format, ap);
    else if (format == 's')
        count = print_s(format, ap);
    return (count);
}

init_parse(char *format, int *i_ptr, va_list ap)
{
    int     count;

    count = 0;
    (*i_ptr)++;
    if (ft_strchr("cspdiuxX%", format[*i_ptr]))
    {
        count += print_argument(format[*i_ptr], ap);
    }
}

int parse_format(char *format, va_list ap)
{
    int ret_size;
    int i;
    int *i_ptr;

    ret_size = 0;
    i = 0;
    i_ptr = &i;

    while (format[i])
    {
        if (format[i] == '%')
            ret_size += init_parse(format, i_ptr, ap);
        else
        {
            write(1, &format[i] , 1);
            ret_size++;
        }
        i++;
    }
    return (ret_size);
}

int ft_printf(const char *format, ...)
{
    int     ret_size;
    va_list ap;

    va_start(ap, format);
    ret_size = parse_format((char *)format, ap);
    va_end(ap);
    return (ret_size);
}