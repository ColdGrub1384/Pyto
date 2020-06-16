/* generate F77 test sources for MINPACK from the documentation
   author: Frederic.Devernay@m4x.org
*/
/* Original awk program was:
   /DRIVER FOR [A-Z1]+ EXAMPLE/{
    pgm=tolower($4);
    oname="t" pgm ".f";
    $0 = substr($0,3);
    print >oname;
    do {
        getline; $0 = substr($0,3);
        if (!/^ +Page$/) print >>oname;
    }
    while (!/LAST CARD OF SUBROUTINE FCN/);
    getline; $0 = substr($0,3); print >>oname;
    getline; $0 = substr($0,3); print >>oname;
   }
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int
main(int argc, char **argv)
{
    FILE *f_doc;
    char buf[256];
    
    if (argc != 2) {
        fprintf(stderr,"Usage: %s path/to/minpack-documentation.txt\n", argv[0]);
        exit(2);
    }
    f_doc = fopen(argv[1], "r");
    if (f_doc == NULL) {
        perror("Error: cannot open input file");
        exit(1);
    }
    while (fgets(buf, sizeof(buf), f_doc) != NULL)
    {
        const char *head = "DRIVER FOR";
        char *pos;
        pos = strstr(buf, head); /* fgets() always returns a NUL-terminated buffer, so there's no buffer over-read risk */
        if (pos != NULL) {
            FILE *f_src;
            /* we found a test source */
            char *name, *line;
            int i;
            int finished = 0;
            pos = pos + strlen(head);
            name = strdup(pos);
            assert(name[0] == ' ');
            name[0] = 't';
            i = 1;
            while(name[i] != 0 && name[i] != ' ') {
                if (name[i] >= 'A' && name[i] <= 'Z')
                    name[i] = name[i] - 'A' + 'a';
                i++;
            }
            assert(name[i] == ' ' && name[i+1] != 0);
            name[i] = '.';
            name[i+1] = 'f';
            name[i+2] = 0;
            f_src = fopen(name, "w");
            if (f_src == NULL) {
                perror("Error: cannot open output file");
                exit(1);
            }
            fputs(buf+2, f_src);
            while (!finished && fgets(buf, sizeof(buf), f_doc) != NULL)
            {
                /* test for page skip */
                const char *buf1 = buf;
                while(*buf1 != 0 && *buf1 == ' ')
                    buf1++;
                if (*buf1 == 0) {
                    /* blank line (happens before page skip) */
                }
                else if(strcmp(buf1, "Page\n") == 0) {
                    /* page skip */
                    /* fputs("\n",f_src); */
                }
                else {
                    /* test for end of function */
                    finished = (strstr(buf, "LAST CARD OF SUBROUTINE FCN") != NULL);
                    fputs(buf+2, f_src);
                }
            }
            assert(finished); /* two more lines */
            line = fgets(buf, sizeof(buf), f_doc);
            assert(line != NULL);
            fputs(buf+2, f_src);
            line = fgets(buf, sizeof(buf), f_doc);
            assert(line != NULL);
            fputs(buf+2, f_src);
            fclose(f_src);
        }
    }
    fclose(f_doc);
}
