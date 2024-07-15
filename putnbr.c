#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	putnbr(int n)
{
	char	buffer[32];
	int	index;

	index = 0;
	if (n == 0)
	{
		write(1, "0", 2);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n != 0)
	{
		buffer[index++] = (n % 10) + '0';
		n /= 10;
	}
	//TODO: Revert buffer ahah
	write(1, &buffer[0], strlen(buffer) + 1);
}

int	main( void )
{
	int	n = -12345;
	putnbr(n);
}

