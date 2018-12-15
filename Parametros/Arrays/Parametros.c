#include <jni.h>
#include "Parametros.h"

JNIEXPORT jint JNICALL Java_Parametros_suma(JNIEnv * env, jobject obj, jint a, jint b)
{
return a+b;
}

JNIEXPORT jstring JNICALL Java_Parametros_pideTexto(JNIEnv * env, jobject obj, jstring prompt)
{
 char buffer [128];
 //Obtenermos el texto pasado como parametro
 const jbyte* prompt_c = (*env)->GetStringUTFChars(env, prompt, NULL);
 
 printf("%s:",prompt_c);
 (*env)->ReleaseStringUTFChars(env, prompt, prompt_c);
 //Pedimos un texto por consola
 //Suponemos que el usuario no escribira mas de 127 caracteres
  scanf("%s", buffer);
 return (*env)->NewStringUTF(env, buffer);

}

JNIEXPORT jintArray JNICALL Java_Parametros_sumaArrays(JNIEnv * env, jobject obj, jintArray arrayA, jintArray arrayB )
{
 jintArray arrayC; //Declaramos un array para la solucion
 jint* A;
 jint* B;
 jint* C;
 jsize i;
 
 //Medimos los arrays 
 jsize longitud = (*env)->GetArrayLength(env,arrayA);
 if (longitud!=(*env)->GetArrayLength(env, arrayB))
	return NULL; //No coinciden las longitudes
//Creamos un nuevo array con la solucion
arrayC = (*env)->NewIntArray(env,longitud);

A = (jint*) (*env)->GetPrimitiveArrayCritical(env, arrayA,NULL);
B = (jint*) (*env)->GetPrimitiveArrayCritical(env, arrayB,NULL);
C = (jint*) (*env)->GetPrimitiveArrayCritical(env, arrayC,NULL);

for (i=0;i<longitud;i++)
 C[i]= A[i]+B[i];
 
 (*env)->ReleasePrimitiveArrayCritical(env,arrayA,A,JNI_ABORT);
 (*env)->ReleasePrimitiveArrayCritical(env,arrayB,B,JNI_ABORT);
 (*env)->ReleasePrimitiveArrayCritical(env,arrayC,C,0);
 return arrayC;
}

JNIEXPORT jobjectArray JNICALL Java_Parametros_sumaMatrices (JNIEnv * env, jobject obj, jobjectArray arrayA, jobjectArray arrayB)
{
jobjectArray arrayC;
jsize i;
jclass tipo_array;
jsize n_vectores = (*env)->GetArrayLength (env, arrayA);
if (n_vectores!= (*env)->GetArrayLength(env, arrayB));
 return NULL; //No se pueden sumar los arrays
			  //por ser distintos
tipo_array = (*env)->FindClass(env,"[I");
if (tipo_array==NULL)
	return NULL; //Se produjo excepcion

arrayC = (*env)->NewObjectArray(env,n_vectores,tipo_array,NULL);
if (arrayC==NULL)
	return NULL; //Excepcion OutofMemoryError lanzada
 for(i=0;i<n_vectores;i++)
	{
	 jsize j;
	 jint* bufferA;
	 jint* bufferB;
	 jint* bufferC;
	 
	 jintArray vectorA = (jintArray) (*env)->GetObjectArrayElement(env,arrayA,i);
	 jintArray vectorB = (jintArray) (*env)->GetObjectArrayElement(env,arrayB,i);
	
	jsize longitud_vector = (*env)->GetArrayLength(env,vectorA);
	
	jintArray vectorC = (*env)->NewIntArray(env,longitud_vector);
	 
	 bufferA = (*env)->GetIntArrayElements(env,vectorA,NULL);
	 bufferB = (*env)->GetIntArrayElements(env,vectorB,NULL);
	 bufferC = (*env)->GetIntArrayElements(env,vectorC,NULL);
	 
	 for(j=0;j<longitud_vector;j++)
		bufferC[j] = bufferA[j]+bufferB[j];
		
	(*env)->ReleaseIntArrayElements(env,vectorA,bufferA,JNI_ABORT);
	(*env)->ReleaseIntArrayElements(env,vectorB,bufferB,JNI_ABORT);
	(*env)->ReleaseIntArrayElements(env,vectorC,bufferC,0);
	
	(*env)->SetObjectArrayElement(env,arrayC,i,vectorC);
	(*env)->DeleteLocalRef(env,vectorA);
	(*env)->DeleteLocalRef(env,vectorB);
	(*env)->DeleteLocalRef(env,vectorC);
	}
return arrayC;
}

