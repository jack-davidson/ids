#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#define MODULE(IDENTIFIER) int IDENTIFIER(char **argv)

char *prompt = "\001\e[0;32m\002(ids)\001\e[0m\002 ";

MODULE(make)
{
	printf("building\n");
	system("make");
	return 0;
}

MODULE(help)
{
	printf("mk: make\ne: edit\ncl: clean\ns: shell run\n");
}

MODULE(edit)
{
	char *editor = getenv("EDITOR");
	printf("opening %s\n", editor);
	system(getenv("EDITOR"));
	return 0;
}

MODULE(clean)
{
	printf("cleaning\n");
	system("make clean");
	return 0;
}

MODULE(run)
{
	printf("running\n");
	char *file = readline("$ ");
	system(file);
	free(file);
	return 0;
}

int main()
{
	char linebuffer[128];
	char *input;

	while (1) {
		input = readline(prompt);

		if (!input)
			break;

		char **argv = NULL;

		if (strcmp(input, "mk") == 0) {
			make(NULL);
		}
		else if (strcmp(input, "cl") == 0) {
			clean(NULL);
		}
		else if (strcmp(input, "s") == 0) {
			run(NULL);
		}
		else if (strcmp(input, "e") == 0) {
			edit(NULL);
		}
		else if (strcmp(input, "h") == 0) {
			help(NULL);
		}

		add_history(input);
		free(input);
		memset(linebuffer, 0, sizeof(linebuffer));
	}
}
