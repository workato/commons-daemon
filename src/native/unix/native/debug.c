/*
   Copyright 2001-2004 The Apache Software Foundation.
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
/* @version $Id: debug.c,v 1.2 2004/02/09 15:55:21 jfclere Exp $ */
#include "jsvc.h"

/* Wether debug is enabled or not */
bool log_debug_flag = false;

/* The name of the jsvc binary. */
char *log_prog = "jsvc";

/* Dump a debug message to stderr */
void log_debug(const char *fmt, ...) {
    va_list ap;

    if (log_debug_flag==false) return;
    if (fmt==NULL) return;

    va_start(ap,fmt);
    fprintf(stderr,"%s debug: ",log_prog);
    vfprintf(stderr,fmt,ap);
    fprintf(stderr,"\n");
    fflush(stderr);
    va_end(ap);
}

/* Dump an error message to stderr */
void log_error(const char *fmt, ...) {
    va_list ap;

    if (fmt==NULL) return;

    va_start(ap,fmt);
    fprintf(stderr,"%s error: ",log_prog);
    vfprintf(stderr,fmt,ap);
    fprintf(stderr,"\n");
    fflush(stderr);
    va_end(ap);
}

