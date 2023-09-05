#include <stdio.h>

static	int ft_is_sign(char first_Char)
{
	if (first_Char == 45 || first_Char == 43)
    {
        printf("Found\n");
		return (1);
    }
	return(0);
}

static	int	ft_is_zeroes(char *arg_String)
{
	int	i;

	i = 0;
    printf("input ft_is_sign: %c\n", arg_String[i]);
	if (ft_is_sign(arg_String[i] && arg_String[i + 1] != '\0'))
		i++;
	while(arg_String[i] && arg_String[i] == '0')
		i++;
	if (arg_String[i] != '\0')
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
    int	zero_counter;
    int i;

	i = 1;
	zero_counter = 0;
	while(argv[i])
	{
		zero_counter += ft_is_zeroes(argv[i]);
        printf("Zero Counter: %d\n", zero_counter);
        i++;
    }
    return (0);    
}
