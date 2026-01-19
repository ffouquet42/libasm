#include "../includes/libasm.h"

int	testing_strlen(int test_number) // add proto .h?
{
	printf(YELLOW "*** Testing | ft_strlen ***\n" WHITE);

	const char *test_strings[] = {
        "Hello World!",
        "",
        // add long one
        "42",
        "abc\0def",
        "           ", // 11 spaces
        "			", // 3 tabs
        " 	 	 	", // mix 3 spaces + 3 tabs
		NULL
    };

	for (int i = 0; test_strings[i]; i++)
	{
		size_t res_strlen = strlen(test_strings[i]);
		size_t res_ft_strlen = 0; // ft_strlen

		printf(MAGENTA "\nTest #%i\n" WHITE, test_number++);
		printf("String    = [" CYAN "%s" WHITE "]\n", test_strings[i]);
		printf("strlen    = %zu\n", res_strlen);
		printf("ft_strlen = %zu\n", res_ft_strlen);
		res_strlen == res_ft_strlen ? printf("Result    = " GREEN "OK" WHITE "\n") : printf("Result    = " RED "KO " WHITE "\n");
	}

	return (test_number);
	// compter les OK/KO et rendre le bilan ou juste afficher un bilan OK KO propre a la fin de la serie de test ou alors a la toute toute fin ? genre une matrice de 0 et de 1 ?
	// on rempli une matrice globale et a la toute fin du main on affiche le bilan
}

int	main(int argc, char **argv)
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

	int	test_number = 1; // static / global ?

	test_number = testing_strlen(test_number); // += i
}