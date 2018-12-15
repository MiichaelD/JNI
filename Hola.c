#include <stdio.h>
#include "Hola.h"

JNIEXPORT void JNICALL Java_Hola_saluda(JNIEnv * env, jobject obj){
          printf("Hello World");
          return;
}
