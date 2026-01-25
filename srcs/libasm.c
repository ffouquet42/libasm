#include "../includes/libasm.h"

static int	test_number = 1;

static const char	*test_strings[] = {
    "Hello World!",
    "",
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
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

static void	testing_write(int x)
{
	printf(YELLOW "\n*** Testing | ft_write ***\n" WHITE);

	int i = 0;

	ssize_t res_write;
	ssize_t res_ft_write;

	

	summary[x][i] = 2;
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
	//
	//
	print_summary(x);

	return (0);
}