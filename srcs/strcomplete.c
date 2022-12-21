#include "parsing.h"

char	*strcomplete(char *str, int len)
{
	int idx;
	char *new_str;

	len++;
	idx = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while(str[idx])
	{
		new_str[idx] = str[idx];
		idx++;
	}
	while(idx < len)
	{
		new_str[idx] = ' ';
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}