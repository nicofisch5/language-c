#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main()
{
    DIR *directory;
    struct dirent *dirEntry;
    char fileType[2];

    // Open the dir
    directory = opendir("./");
    // Check if dir is right opened

    // Read the dir
    while(dirEntry = readdir(directory))
    {
        /*
        struct dirent {
               ino_t          d_ino;       // Inode number
               off_t          d_off;       // Not an offset; see below
               unsigned short d_reclen;    // Length of this record
               unsigned char  d_type;      // Type of file; not supported by all filesystem types
               char           d_name[256]; // Null-terminated filename
           };
        */

       switch (dirEntry->d_type)
        {
        case DT_REG:
            strcpy(fileType, "F");
            break;
        case DT_BLK:
            strcpy(fileType, "B");
            break;
        case DT_CHR:
            strcpy(fileType, "C");
            break;
        case DT_DIR:
            strcpy(fileType, "D");
            break;
        //case DT_FIFO:
        case DT_LNK:
            strcpy(fileType, "L");
            break;
        default:
            strcpy(fileType, "X");
            break;
        }

        printf("%-8ld\t %1s %-12s\t \n", dirEntry->d_ino, fileType, dirEntry->d_name);
    }

    // Close the dir
    closedir(directory);
}