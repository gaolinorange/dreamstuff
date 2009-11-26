#ifndef MESHDEFORMER_HELPER_HELPER_H
#define MESHDEFORMER_HELPER_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

inline void TRACE(const char * format,...)
{
  FILE* fp = fopen("trace.txt","w");
  
  va_list args;
  int len;
  char* buffer;

  //retrieve the variable arguments
  va_start(args,format);
  //len = _vscprintf(format,args)+1; //_vscprintf doesn't count terminating '\0'
  len = vfprintf(fp,format,args)+1;

  buffer = (char*)malloc(len*sizeof(char));

  vsprintf(buffer,format,args);
    
  printf("%s",buffer);
  free(buffer);
  fclose(fp);
}

#endif
