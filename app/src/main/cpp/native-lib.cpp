#include <jni.h>
#include <string>
#include <iostream>
#include "analyze/include/Analyze.h"
#include <android/log.h>

#define DEBUG_TAG "NDK_Flite"
extern "C" JNIEXPORT jstring JNICALL Java_more_dsi_iii_com_flitetest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */)
{
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT void JNICALL Java_more_dsi_iii_com_flitetest_MainActivity_convertToLabels(
        JNIEnv *env, jobject thisObj, jstring text)
{
    jboolean isCopy;
    const char* cText = env->GetStringUTFChars(text, &isCopy);

   __android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG,"text: %s", cText);

    engtts::Analyze test = engtts::Analyze();
    engtts::TextFragmentPtr tf = engtts::TextFragmentPtr(new engtts::TextFragment(std::string(cText)));
    engtts::LabelsPtr resultLabelsPtr = test.AnalyzeTextFragment(tf);

    for (auto i = resultLabelsPtr->begin(); i != resultLabelsPtr->end(); i++)
    {
        __android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG,"%s", (*i)->getAsHTKLabel().c_str());

    }


}



