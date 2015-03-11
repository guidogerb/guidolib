/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class guidoengine_guidopianorollbase */

#ifndef _Included_guidoengine_guidopianorollbase
#define _Included_guidoengine_guidopianorollbase
#ifdef __cplusplus
extern "C" {
#endif
#undef guidoengine_guidopianorollbase_kCLine
#define guidoengine_guidopianorollbase_kCLine 1L
#undef guidoengine_guidopianorollbase_kCSharpLine
#define guidoengine_guidopianorollbase_kCSharpLine 2L
#undef guidoengine_guidopianorollbase_kDLine
#define guidoengine_guidopianorollbase_kDLine 4L
#undef guidoengine_guidopianorollbase_kDSharpLine
#define guidoengine_guidopianorollbase_kDSharpLine 8L
#undef guidoengine_guidopianorollbase_kELine
#define guidoengine_guidopianorollbase_kELine 16L
#undef guidoengine_guidopianorollbase_kFLine
#define guidoengine_guidopianorollbase_kFLine 32L
#undef guidoengine_guidopianorollbase_kFSharpLine
#define guidoengine_guidopianorollbase_kFSharpLine 64L
#undef guidoengine_guidopianorollbase_kGLine
#define guidoengine_guidopianorollbase_kGLine 128L
#undef guidoengine_guidopianorollbase_kGSharpLine
#define guidoengine_guidopianorollbase_kGSharpLine 256L
#undef guidoengine_guidopianorollbase_kALine
#define guidoengine_guidopianorollbase_kALine 512L
#undef guidoengine_guidopianorollbase_kASharpLine
#define guidoengine_guidopianorollbase_kASharpLine 1024L
#undef guidoengine_guidopianorollbase_kBLine
#define guidoengine_guidopianorollbase_kBLine 2048L
#undef guidoengine_guidopianorollbase_kAutoLines
#define guidoengine_guidopianorollbase_kAutoLines 0L
#undef guidoengine_guidopianorollbase_kNoLine
#define guidoengine_guidopianorollbase_kNoLine -1L
#undef guidoengine_guidopianorollbase_kSimplePianoRoll
#define guidoengine_guidopianorollbase_kSimplePianoRoll 0L
#undef guidoengine_guidopianorollbase_kTrajectoryPianoRoll
#define guidoengine_guidopianorollbase_kTrajectoryPianoRoll 1L
/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    AR2PianoRoll
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_guidoengine_guidopianorollbase_AR2PianoRoll
  (JNIEnv *, jobject, jint);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    Midi2PianoRoll
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_guidoengine_guidopianorollbase_Midi2PianoRoll
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    DestroyPianoRoll
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_DestroyPianoRoll
  (JNIEnv *, jobject);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    SetLimits
 * Signature: (Lguidoengine/limitparams;)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_SetLimits
  (JNIEnv *, jobject, jobject);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    EnableKeyboard
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_EnableKeyboard
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    GetKeyboardWidth
 * Signature: (I)F
 */
JNIEXPORT jfloat JNICALL Java_guidoengine_guidopianorollbase_GetKeyboardWidth
  (JNIEnv *, jobject, jint);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    EnableAutoVoicesColoration
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_EnableAutoVoicesColoration
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    SetRGBColorToVoice
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_SetRGBColorToVoice
  (JNIEnv *, jobject, jint, jint, jint, jint, jint);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    SetHtmlColorToVoice
 * Signature: (IJ)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_SetHtmlColorToVoice
  (JNIEnv *, jobject, jint, jlong);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    EnableMeasureBars
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_EnableMeasureBars
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    SetPitchLinesDisplayMode
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_SetPitchLinesDisplayMode
  (JNIEnv *, jobject, jint);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    GetMap
 * Signature: (IILguidoengine/guidoscoremap;)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidopianorollbase_GetMap
  (JNIEnv *, jobject, jint, jint, jobject);

/*
 * Class:     guidoengine_guidopianorollbase
 * Method:    Init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_guidoengine_guidopianorollbase_Init
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif