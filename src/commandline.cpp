#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char * getCommandLineParameter(int argc, char* argv[], const char *pcOpcion)
{
    char *pcValor;

    for (int i=0;i<argc;i++) {
        pcValor = strstr(argv[i],pcOpcion);

        // Parameter is found.
        if ((pcValor!=NULL) && strlen(pcValor)>strlen(pcOpcion) )
            return pcValor+strlen(pcOpcion);
        else if ((pcValor != NULL) && (i+1)<argc )
            return argv[i+1];
    }

    // Nothing found.
    return NULL;
}

int isPresentCommandLineParameter(int argc, char *argv[], const char *pcOpcion)
{
    char *pcValor;

    for (int i=0;i<argc;i++) {
        pcValor = strstr(argv[i],pcOpcion);

        // Parameter is found and it has some value.
        if ((pcValor!=NULL))
            return 1;
    }

    // Nothing found.
    return 0;
}

const char * getDefaultedCommandLineParameter(int argc, char* argv[], const char *pcOpcion, const char *defaultvalue)
{
    char *pcValor = getCommandLineParameter(argc,argv,pcOpcion);

    if (pcValor==NULL)
        return defaultvalue;
    else
        return pcValor;
}


int getDefaultedIntCommandLineParameter(int argc, char* argv[], const char *pcOpcion, int iDefault)
{
    char *pcValor = getCommandLineParameter(argc,argv,pcOpcion);

    if (pcValor==NULL)
        return iDefault;
    else
        return atoi(pcValor);
}
