#include <jni.h>
/*Header for Class HolaMundo*/

#ifndef _Included_HolaMundo
	#define _Included_HolaMundo
	#ifdef __cplusplus
		extern "C" {
	#endif
/* 
	*Class: HolaMundo
	*Method: saluda
	*signature;: ()V
	*/

JNIEXPORT void JNICALL Java_HolaMundo_saluda(JNIEnv*, jobject);

#ifdef __cplusplus
}
#endif
#endif