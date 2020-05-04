#include "ft_print.h"

int	cap_x_with_precision(t_list opt, unsigned int ptr, int print_len)
{
	int ret;
	
	ret = 0;
	opt.zero = 0;
	ft_pad_left_zero(opt.width, print_len, opt.left, opt.zero);
	if (print_len > opt.precs_len)
		ft_pad_left_blnk(opt.width, print_len, opt.left, opt.zero);
	else
		ft_pad_left_blnk(opt.width, opt.precs_len, opt.left, opt.zero);
	ft_pad_left_zero(opt.precs_len, print_len, 0, 1);
	ft_putnbr_base(ptr, "0123456789ABCDEF");
	if (print_len > opt.precs_len)
		ft_pad_right_blnk(opt.width, print_len, opt.left);
	else
		ft_pad_right_blnk(opt.width, opt.precs_len, opt.left);
	if (opt.width > print_len || opt.precs_len > print_len)
		ret = ft_max(opt.width, opt.precs_len);
	else
		ret = print_len;
	return (ret);
}

int	cap_x_without_precision(t_list opt, unsigned int ptr, int print_len)
{
	int ret;
	
	ret = 0;
	ft_pad_left_zero(opt.width, print_len, opt.left, opt.zero);
	ft_pad_left_blnk(opt.width, print_len, opt.left, opt.zero);
	ft_putnbr_base(ptr, "0123456789ABCDEF");
	ft_pad_right_blnk(opt.width, print_len, opt.left);
	if (opt.width > print_len)
		ret = opt.width;
	else
		ret = print_len;
	return (ret);
}

int	cap_x_conversion(t_list opt, va_list *ap)
{
	int				ret;
	unsigned int	ptr;
	int				print_len;

	ret = 0;
	if (!(ptr = va_arg(*ap, int)))
		return (-1);
	print_len = ft_converted_len(ptr, "0123456789ABCDEF");
	if (opt.precision == 1)
		ret = cap_x_with_precision(opt, ptr, print_len);
	else
		ret = cap_x_without_precision(opt, ptr, print_len);
	return (ret);
}