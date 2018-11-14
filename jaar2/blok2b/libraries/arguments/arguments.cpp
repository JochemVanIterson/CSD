// bron: https://linux.die.net/man/3/getopt
#include <iostream>
#include <string>

#include <getopt.h>

int main(int argc, char* argv[]) {
  int c;
  int digit_optind = 0;

  while (1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
      {"add",     required_argument, 0,  'c' },
      {"append",  no_argument,       0,  1 },
      {0,         0,                 0,  0 }
    };

    c = getopt_long(argc, argv, "ac:01", long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {
      case 0:
        printf("option %s", long_options[option_index].name);
        if (optarg)
          printf(" with arg %s", optarg);
        printf("\n");
        break;

      case 1:
        printf("test\n");
        break;

      case 'a':
        printf("no_argument a\n");
        break;

      case 'c':
        printf("required_argument c with value '%s'\n", optarg);
        break;

      case '?':
        break;

      default:
        printf("?? getopt returned character code 0%o ??\n", c);
    }
  }

  if (optind < argc) {
    printf("non-option ARGV-elements: ");
    while (optind < argc)
      printf("%s ", argv[optind++]);
      printf("\n");
  }

  exit(EXIT_SUCCESS);
}
