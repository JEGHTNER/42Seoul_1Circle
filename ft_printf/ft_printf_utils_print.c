#include<stdio.h>
#include<stdarg.h>
int print_percent(char format)
{
    int count;

    count = 0;
    printf("%");
    //write(1, "%", 1);
    count++;
    return (count);
}

void	display(long long number, int *count)
{
	if (number >= 10)
		display(number / 10, count);
    printf("%c",number % 10 + '0');
	//write(1, number % 10 + '0', 1);
    (*count)++;
}

int ft_putnbr_diu(int number)
{
	long long	nbr;
    int         count;

    count = 0;
	nbr = (long long) number;
	if (nbr < 0)
	{
		nbr *= -1;
        printf("-");
		//write(1, '-', 1);
	}
    display(nbr, &count);
	return (count);
}

int print_di(char format, va_list ap)
{
    int count;
    int ap_int;

    ap_int = va_arg(ap, int);
    count = ft_putnbr_diu(ap_int);
    return (count);
}

int print_u(char format, va_list ap)
{
    int             count;
    unsigned int    ap_uint;
    
    ap_uint = va_arg(ap, unsigned int);
    count = ft_putnbr_diu(ap_uint);
    return (count);
}

void	display_hex(unsigned long long number,char *hex, int *count)
{
	if (number >= 16)
		display_hex(number / 16, hex, count);
    printf("%c",hex[number % 16]);
	//write(1, hex[number % 16], 1);
    (*count)++;
}

int ft_puthex_xXp(char format, unsigned long long ap_xXp)
{
    int     count;
    char    *cap_hex;
    char    *low_hex;

    cap_hex = "0123456789ABCDEF";
    low_hex = "0123456789abcdef";
    if (format == 'x')
        display_hex(ap_xXp, low_hex, &count);
    else
        display_hex(ap_xXp, cap_hex, &count);
    return(count);
}

int print_xXp(char format, va_list ap)
{
    int count;
    unsigned long long    ap_xXp;

    if (format == 'p')
        ap_xXp = (unsigned long long)va_arg(ap, void *);
    else
        ap_xXp = va_arg(ap, unsigned int);
    count = ft_puthex_xXp(format, ap_xXp);

    return (count);

}

int print_c(char format, va_list ap)
{
    int count;
    unsigned char   ap_char;
    
    count = 0;
    ap_char = (unsigned char)va_arg(ap, int);
    printf("%c",ap_char);
    //write(1, &ap_char, 1);
    count++;

    return (count);
}