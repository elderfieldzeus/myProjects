#include <stdio.h>

int main(){
    printf("Different terminal commands (related to git):\n");
    printf("\"dir\" - open directory\n");
    printf("\"cd (directory name)\" - change directory\n");
    printf("\"git status\" - check status\n");
    printf("\"git add .\" or \"git add (name of file)\" - add before commiting\n");
    printf("\'git commit -m \"(message here)\" \' - commit git with message (required message)\n");
    printf("\"git push\" - push directory to github\n");
    printf("\"git pull\" - pull repository from github\n");
    printf("\'browser-sync start --server --directory --files \"*\" \' - for browser-sync\n");
    return 0;
}