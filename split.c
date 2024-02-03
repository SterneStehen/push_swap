#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (substr)
			substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *) malloc (len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_world_count( char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		world_count;	
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	world_count = ft_world_count(s, c);
	result = (char **)malloc(sizeof(char *) * (world_count + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
			result[j++] = ft_substr(s, start, (i - start));
	}
	result[j] = NULL;
	return (result);
}