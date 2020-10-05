/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 04:29:16 by araout            #+#    #+#             */
/*   Updated: 2020/10/04 05:52:04 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int nm(char *ptr)
{
	unsigned int magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
	{
		write(1,"6444",4);
	}
	if (magic_number == MH_MAGIC)
	{
		write(1,"3222",4);
	}
	return (0);
}
int handle_file(char *filename)
{
	int				fd;
	char			*ptr;
	struct stat		buf;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (fstat(fd, &buf) < 0)
		return (EXIT_FAILURE);
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
		return (EXIT_FAILURE);
	nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
	{
		if (handle_file("./a.out") == EXIT_FAILURE)
		{
			write(2, "ERROR", 5);
			return (1);
		}
	}
	else
	{
		while (ac-- > 1)
		{
			if ((handle_file(av[++i])) == EXIT_FAILURE)
				write(2, "ERROR", 5);
		}
	}
	return (0);
}
