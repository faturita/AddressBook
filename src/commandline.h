#ifndef COMMANDLINE_H
#define COMMANDLINE_H

char * getCommandLineParameter(int argc, char* argv[], const char *pcOpcion);
int getDefaultedIntCommandLineParameter(int argc, char* argv[], const char *pcOpcion, int iDefault);
const char * getDefaultedCommandLineParameter(int argc, char* argv[], const char *pcOpcion, const char *defaultvalue);
int isPresentCommandLineParameter(int argc, char *argv[], const char *pcOpcion);

#endif // COMMANDLINE_H
