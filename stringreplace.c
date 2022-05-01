/*
 * stringreplace.c
 * File String Replace
 * 
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILELEN 1048576 // One MB

int main(int argc, char** argv)
{
        char fileBuf[MAXFILELEN], fileBufTmp[MAXFILELEN],
                filePath[PATH_MAX + 1], *oldStr, *newStr;
        int n, m, oldStrLen, newStrLen;
        FILE *fp;

        if (argc != 4)
        {
                printf("Usage: Please include exactly three"
                        "arguments, a path, string to replace"
                        ", and string to replace it with!\n");
                return 0;
        }

        /* Initialize vars */

        if (realpath(argv[1], filePath) == NULL)
        {
                perror("Error: Unable to get absolute file path!\n");
                return 1;
        }

        if ((fp = fopen(filePath, "r")) == NULL)
        {
                printf("Usage: Unable to open file to read!\n");
                return 0;
        }

        if (fread(fileBuf, MAXFILELEN, 1, fp) < 0)
        {
                perror("Error: Unable to read file!\n");
                return 1;
        }

        if (fclose(fp) < 0)
        {
                perror("Error: Unable to close tmp file!\n");
                return 1;
        }

        n = m = 0; // indicies of fileBuf and fileBufTmp respectively
        oldStr = argv[2];
        newStr = argv[3];
        oldStrLen = strlen(oldStr);
        newStrLen = strlen(newStr);

        /* Execute/Run */

        while (fileBuf[n])
        {
                if (strstr(fileBuf + n, oldStr) == (fileBuf + n))
                {
                        memcpy(fileBufTmp + m, newStr, newStrLen);
                        n += oldStrLen;
                        m += newStrLen;
                }
                else
                        fileBufTmp[m++] = fileBuf[n++];
        }

        if ((fp = fopen(filePath, "w")) == NULL)
        {
                printf("Usage: Unable to open file to write!\n");
                return 0;
        }

        if (fwrite(fileBufTmp, m, 1, fp) < 0)
        {
                perror("Error: Unable to write tmp file!\n");
                return 1;
        }

        if (fclose(fp) < 0)
        {
                perror("Error: Unable to close tmp file!\n");
                return 1;
        }

        return 0;
}
