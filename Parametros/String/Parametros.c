#include <jni.h>
#include "Parametros.h"

JNIEXPORT jstring JNICALL Java_Parametros_pideTexto(JNIEnv * env, jobject obj, jstring prompt)
{
 char buffer [128];
 //Obtenermos el texto pasado como parametro
 const jbyte* prompt_c = (*env)->GetStringUTFChars(env, prompt, NULL);
 
 printf("%s aqui: ",prompt_c);
 (*env)->ReleaseStringUTFChars(env, prompt, prompt_c);
 //Pedimos un texto por consola
 //Suponemos que el usuario no escribira mas de 127 caracteres
  scanf("%s", buffer);
 return (*env)->NewStringUTF(env, buffer);

}