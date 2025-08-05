unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	s;
	unsigned int	total;
	unsigned int	i;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (d >= size)
	{
		total = size + s;
		return (total);
	}
	total = d + s;
	i = 0;
	while (src[i] != '\0' && (d + 1) < size)
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (total);
}