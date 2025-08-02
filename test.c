#include "so_long.h"
#include <string.h>

int main()
{
	char *s = "123\n";
	printf("%lu\n", strlen(s));
	printf("%zu\n", ft_strlen(s));
}