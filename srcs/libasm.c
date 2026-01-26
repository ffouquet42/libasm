#include "../includes/libasm.h"

static int	test_number = 1;

static const char	*test_strings[] = {
    "Hello World!",
    "",
    "zaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
    "42",
    "abc\0def",
    "           ", // 11 spaces
    "			", // 3 tabs
    " 	 	 	", // mix 3 spaces + 3 tabs
	"Hello World!\n",
	"\n",
	NULL
};

static int summary[100][100];

// print all tests results
static void print_summary(int max_x)
{
	printf(YELLOW "\n*** Summary ***\n\n" WHITE);

	int x = 0;
	int test_nb = 1;

	while (x < max_x)
	{
		int i = 0;
		while (summary[x][i] != 2)
		{
			if (summary[x][i] == 0)
				printf(GREEN "#%i[OK]" WHITE "|", test_nb++);
			else
				printf(RED "#%i[OK]" WHITE "|", test_nb++);
			i++;
		}
		x++;
	}
	printf("\n");
	return;
}

static void	testing_strdup(int x)
{
	printf(YELLOW "\n*** Testing | ft_strdup ***\n" WHITE);

	int i = -1;

	while (test_strings[++i])
	{
		char *res_strdup = strdup(test_strings[i]);
		char *res_ft_strdup = ft_strdup(test_strings[i]);

		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);

		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		printf("strdup    = [%s]\n", res_strdup);
		printf("ft_strdup = [%s]\n", res_ft_strdup);

		strcmp(res_strdup, res_ft_strdup) ? printf("Result    = " RED "[KO]" WHITE "\n") : printf("Result    = " GREEN "[OK]" WHITE "\n");
		if (strcmp(res_strdup, res_ft_strdup))
			summary[x][i] = 1;
		else
			summary[x][i] = 0;
		
		free(res_strdup);
		free(res_ft_strdup);
	}

	summary[x][i] = 2;
	return;
}

static void	testing_read(int x)
{
	int y = 0; // i

	// buff > file - est ce que buff est le bon terme
	printf(YELLOW "\n*** Testing | ft_read 1/2***\n" WHITE);

	int fd = open("srcs/testing/ft_read_testing_1.txt", O_RDONLY);
	if (fd < 0)
		return (perror("error")); // msg
	
	char buff_read[1000]; // test 1, 2 or empty file
	char buff_ft_read[1000]; // buff size
	
	printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);

	ssize_t res_read = read(fd, buff_read, sizeof(buff_read) - 1);
	if (res_read < 0) // if (res_read)?
	{
		close(fd);
		return (perror("error")); // 1 ligne ?
	}
	buff_read[res_read] = '\0';
	printf("read      = [%zd] | buff = [%s]\n", res_read, buff_read);

	lseek(fd, 0, SEEK_SET);

	ssize_t res_ft_read = ft_read(fd, buff_ft_read, sizeof(buff_ft_read) - 1);
	if (res_ft_read < 0)
	{
		close(fd);
		return (perror("error"));
	}
	buff_ft_read[res_ft_read] = '\0';

	printf("ft_read   = [%zd] | buff = [%s]\n", res_ft_read, buff_ft_read);

	lseek(fd, 0, SEEK_SET);

	if (res_read == res_ft_read && strcmp(buff_read, buff_ft_read) == 0)
	{
		printf("Result    = " GREEN "[OK]" WHITE "\n");
		summary[x][y++] = 0;
	}
	else
	{
		printf("Result    = " RED "[KO]" WHITE "\n");
			summary[x][y++] = 1;
	}
	close(fd);

	
	printf(YELLOW "\n*** Testing | ft_read 2/2***\n" WHITE);

	printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
	errno = 0;
	res_read = read(-1, buff_read, sizeof(buff_read) - 1);
	printf("read      = [%zd] | errno = [%d]\n", res_read, errno);
	int read_errno = errno;
	errno = 0;
	res_ft_read = ft_read(-1, buff_ft_read, sizeof(buff_ft_read) - 1);
	printf("ft_read   = [%zd] | errno = [%d]\n", res_ft_read, errno);
	int ft_read_errno = errno;
	errno = 0;
	if (res_read == res_ft_read && read_errno == ft_read_errno)
	{
		printf("Result    = " GREEN "[OK]" WHITE "\n");
		summary[x][y++] = 0;
	}
	else
	{
		printf("Result    = " RED "[KO]" WHITE "\n");
		summary[x][y++] = 1;
	}


	summary[x][y] = 2;
	return;
}

static void	testing_write(int x)
{
	printf(YELLOW "\n*** Testing | ft_write 1/3 ***\n" WHITE);

	int y = 0;
	int i = -1;

	while (test_strings[++i])
	{
		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		errno = 0;
		ssize_t res_write = write(1, test_strings[i], strlen(test_strings[i]));
		printf("\nwrite     = [%zd] | errno = [%d]\n", res_write, errno);
		int write_errno = errno;
		errno = 0;
		ssize_t res_ft_write = ft_write(1, test_strings[i], strlen(test_strings[i]));
		printf("\nft_write  = [%zd] | errno = [%d]\n", res_ft_write, errno);
		int ft_write_errno = errno;
		if (res_write == res_ft_write && write_errno == ft_write_errno)
		{
			printf("Result    = " GREEN "[OK]" WHITE "\n");
			summary[x][y++] = 0;
		}
		else
		{
			printf("Result    = " RED "[KO]" WHITE "\n");
			summary[x][y++] = 1;
		}
	}

	printf(YELLOW "\n*** Testing | ft_write 2/3 ***\n" WHITE);

	i = -1;

	while (test_strings[++i])
	{
		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		errno = 0;
		ssize_t res_write = write(-1, test_strings[i], strlen(test_strings[i]));
		printf("\nwrite     = [%zd] | errno = [%d]\n", res_write, errno);
		int write_errno = errno;
		errno = 0;
		ssize_t res_ft_write = ft_write(-1, test_strings[i], strlen(test_strings[i]));
		printf("\nft_write  = [%zd] | errno = [%d]\n", res_ft_write, errno);
		int ft_write_errno = errno;
		if (res_write == res_ft_write && write_errno == ft_write_errno)
		{
			printf("Result    = " GREEN "[OK]" WHITE "\n");
			summary[x][y++] = 0;
		}
		else
		{
			printf("Result    = " RED "[KO]" WHITE "\n");
			summary[x][y++] = 1;
		}
	}

	printf(YELLOW "\n*** Testing | ft_write 3/3 ***\n" WHITE);
	
	printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
	printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[8]);
	errno = 0;
	int fd = open("srcs/testing/ft_write_testing.txt", O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		return (perror("error")); // msg - close ?
	ssize_t res_write = write(fd, test_strings[8], strlen(test_strings[8]));
	printf("\nwrite     = [%zd] | errno = [%d]\n", res_write, errno);
	int write_errno = errno;
	errno = 0;
	ssize_t res_ft_write = ft_write(fd, test_strings[8], strlen(test_strings[8]));
	printf("\nft_write  = [%zd] | errno = [%d]\n", res_ft_write, errno);
	int ft_write_errno = errno;
	if (res_write == res_ft_write && write_errno == ft_write_errno)
	{
		printf("Result    = " GREEN "[OK]" WHITE "\n");
		summary[x][y++] = 0;
	}
	else
	{
		printf("Result    = " RED "[KO]" WHITE "\n");
		summary[x][y++] = 1;
	}
	close(fd);
	
	errno = 0;
	summary[x][y] = 2;
	return;
}

static void testing_strcmp(int x)
{
	printf(YELLOW "\n*** Testing | ft_strcmp 1/2 ***\n" WHITE);

	int i = -1;
	int y = 0;

	while (test_strings[++i])
	{
		int res_strcmp = strcmp(test_strings[i], test_strings[i]);
		int res_ft_strcmp = ft_strcmp(test_strings[i], test_strings[i]);

		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("Strings   = [" CYAN "%s" WHITE "] - [" CYAN "%s" WHITE "]\n", test_strings[i], test_strings[i]);
		printf("strcmp    = [%i]\n", res_strcmp);
		printf("ft_strcmp = [%i]\n", res_ft_strcmp);
		res_strcmp == res_ft_strcmp ? printf("Result    = " GREEN "[OK]" WHITE "\n") : printf("Result    = " RED "[KO]" WHITE "\n");
		if (res_strcmp == res_ft_strcmp)
			summary[x][y++] = 0;
		else
			summary[x][y++] = 1;
	}

	printf(YELLOW "\n*** Testing | ft_strcmp 2/2 ***\n" WHITE);

	i = 0;

	while (test_strings[++i])
	{
		int res_strcmp = strcmp(test_strings[i], test_strings[i - 1]);
		int res_ft_strcmp = ft_strcmp(test_strings[i], test_strings[i - 1]);

		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("Strings   = [" CYAN "%s" WHITE "] - [" CYAN "%s" WHITE "]\n", test_strings[i], test_strings[i - 1]);
		printf("strcmp    = [%i]\n", res_strcmp);
		printf("ft_strcmp = [%i]\n", res_ft_strcmp);
		res_strcmp == res_ft_strcmp ? printf("Result    = " GREEN "[OK]" WHITE "\n") : printf("Result    = " RED "[KO]" WHITE "\n");
		if (res_strcmp == res_ft_strcmp)
			summary[x][y++] = 0;
		else
			summary[x][y++] = 1;
	}

	summary[x][y] = 2;
	return;
}

static void	testing_strcpy(int x)
{
	printf(YELLOW "\n*** Testing | ft_strcpy ***\n" WHITE);

	int i = -1;
	char dest_1[1000];
	char dest_2[1000];

	while (test_strings[++i])
	{
		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		printf("strcpy    = [%s]\n", strcpy(dest_1, test_strings[i]));
		printf("ft_strcpy = [%s]\n", ft_strcpy(dest_2, test_strings[i]));
		strcmp(dest_1, dest_2) ? printf("Result    = " RED "[KO]" WHITE "\n") : printf("Result    = " GREEN "[OK]" WHITE "\n");
		if (strcmp(dest_1, dest_2))
			summary[x][i] = 1;
		else
			summary[x][i] = 0;
	}

	summary[x][i] = 2;
	return;
}

static void	testing_strlen(int x)
{
	printf(YELLOW "\n*** Testing | ft_strlen ***\n" WHITE);

	int i = -1;

	while (test_strings[++i])
	{
		size_t res_strlen = strlen(test_strings[i]);
		size_t res_ft_strlen = ft_strlen(test_strings[i]);

		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		printf("strlen    = [%zu]\n", res_strlen);
		printf("ft_strlen = [%zu]\n", res_ft_strlen);
		res_strlen == res_ft_strlen ? printf("Result    = " GREEN "[OK]" WHITE "\n") : printf("Result    = " RED "[KO]" WHITE "\n");
		if (res_strlen == res_ft_strlen)
			summary[x][i] = 0;
		else
			summary[x][i] = 1;
	}

	summary[x][i] = 2;
	return;
}

int	main(void)
{
	int x = 0;

	testing_strlen(x++);
	testing_strcpy(x++);
	testing_strcmp(x++);
	testing_write(x++);
	testing_read(x++);
	testing_strdup(x++);
	print_summary(x);

	return (0);
}

// ----------------------------------------------
// make re ->
// section .note.GNU-stack noalloc noexec nowrite progbits