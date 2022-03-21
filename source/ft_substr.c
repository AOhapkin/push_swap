#include "push_swap.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len <= start)
		return (ft_newstr(0));
	if ((len + start) > str_len)
		len = str_len - start;
	substr = ft_newstr(len);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	return (substr);
}
