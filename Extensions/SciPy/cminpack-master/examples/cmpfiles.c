/*
  Compare two files line by line, output differences to stderr.
  Exit status is 0 if files are the same, 1 if different.

  Author: Frederic.Devernay@m4x.org
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
    char buf1[1024], buf2[1024];
    int differences = 0;
    
    if (argc != 3) {
        fprintf(stderr,"Usage: %s filename1 filename2\n", argv[0]);
        exit(2);
    }

    fp1 = fopen(argv[1],"r");
    if (fp1 == NULL) {
        perror("Error: cannot open input file");
        exit(1);
    }
    fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
        perror("Error: cannot open input file");
        exit(1);
    }

    while (fgets(buf1, sizeof(buf1), fp1) != NULL)
    {
        if(fgets(buf2, sizeof(buf2), fp2) == NULL) {
            fprintf(stderr, "<%s", buf1);
            ++differences;
        }
        else if(strcmp(buf1, buf2) != 0)
        {
            fprintf(stderr, "<%s", buf1);
            fprintf(stderr, ">%s", buf2);
            ++differences;
        }
    }
    while(fgets(buf2, sizeof(buf2), fp2) != NULL)  {
        fprintf(stderr, ">%s", buf2);
        ++differences;
    }
    if (differences != 0) {
        fprintf(stderr,"Total differences between files '%s' and '%s': %d lines\n",
                argv[1], argv[2], differences);
    }
    exit(differences != 0);
}
