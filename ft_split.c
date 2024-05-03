#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(const char *str, int start, int lenght)
{
	int		i = 0;
	char	*dest = malloc(sizeof(*str) * lenght + 1);
	
	while (i <= lenght)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}

int     ft_countw(const char *str, const char c)
{
    int		i = 0, j = 0;
	
	while (str[i])
	{
		if (str[i] == c)
		{
			j++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	printf("\n\n");
	return (j);
}

char    **ft_split(const char *str, const char c)
{
    char    **array;
    int     j = ft_countw(str, c) + 1;
    int     i = 0, k = 0, h = 0;
    
    array = malloc(sizeof(str) * j);
	while (i < j && str[h])
	{
		while (str[k] != c && str[k])
			k++;
		array[i] = ft_substr(str, h, (k - h - 1));
		while (str[k] == c)
			k++;
		while (str[h] != c && str[h])
			h++;
		while (str[h] == c)
			h++;
		i++;
	}
	array[j] = NULL;
	return (array);
}

int main(void)
{
	char	*str = "Je_suis_un_genie";
	char	c = '_';
	char 	**array = ft_split(str, c);
	int		j = ft_countw(str, c), i = 0;
	
	while (i <= (j + 1))
	{
		printf("main array[%d] = \"%s\"\n", i, array[i]);
		free (array[i++]);
    }
	return 0;
}