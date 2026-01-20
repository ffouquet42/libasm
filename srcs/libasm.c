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
	NULL
 };

static int summary[2][16];

static void print_summary(void)
{
	printf(YELLOW "\n*** Summary ***\n" WHITE);

	int x = 0;
	int i = 0;
	int test_nb = 1;

	while (x < 2)
	{
		while (summary[x][i] != 2)
		{
			if (summary[x][i] == 0)
				printf(GREEN "#%d[OK]" WHITE "|", test_nb++);
			else
				printf(RED "#%d[OK]" WHITE "|", test_nb++);
			i++;
		}
		x++;
	}
	printf("\n");
	return;
}

static void	testing_strcpy(void)
{
	printf(YELLOW "\n*** Testing | ft_strcpy ***\n" WHITE);

	// dev

	return;
}

static void	testing_strlen(void)
{
	printf(YELLOW "\n*** Testing | ft_strlen ***\n" WHITE);

	int i = -1;

	while (test_strings[++i])
	{
		size_t res_strlen = strlen(test_strings[i]);
		size_t res_ft_strlen = ft_strlen(test_strings[i]);

		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		printf("strlen    = %zu\n", res_strlen);
		printf("ft_strlen = %zu\n", res_ft_strlen);
		res_strlen == res_ft_strlen ? printf("Result    = " GREEN "[OK]" WHITE "\n") : printf("Result    = " RED "[KO]" WHITE "\n");
		if (res_strlen == res_ft_strlen)
			summary[0][i] = 0;
		else
			summary[0][i] = 1;
	}

	summary[0][i] = 2;
	return;
}

int	main(void)
{
	// dev
	printf(RED "color red\n");
	printf(GREEN "color green\n");
	printf(YELLOW "color yellow\n");
	printf(BLUE "color blue\n");
	printf(MAGENTA "color magenta\n");
	printf(CYAN "color cyan\n");
	printf(WHITE "color white\n");
	printf("\n");
	// dev
	
	testing_strlen();
	testing_strcpy();

	print_summary();

	return (0);
}