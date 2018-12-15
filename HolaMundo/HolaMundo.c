#include <stdio.h>
#include "HolaMundo.h"

JNIEXPORT void JNICALL Java_HolaMundo_saluda(JNIEnv* env, jobject obj)
{
 printf("Hola Mundo\n");
 return;
}