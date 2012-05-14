#include <nullvm.h>

char* toBinaryName(Env* env, Object* className) {
    char* classNameUTF = nvmGetStringUTFChars(env, className);
    if (!classNameUTF) return NULL;
    jint i;
    for (i = 0; classNameUTF[i] != '\0'; i++) {
        if (classNameUTF[i] == '.') classNameUTF[i] = '/';
    }
    return classNameUTF;
}

Class* Java_java_lang_VMClassLoader_findLoadedClass(Env* env, Class* cls, ClassLoader* cl, Object* name) {
    char* classNameUTF = toBinaryName(env, name);
    if (!classNameUTF) return NULL;
    return nvmFindLoadedClass(env, classNameUTF, cl);
}

Class* Java_java_lang_VMClassLoader_findClassInClasspathForLoader(Env* env, Class* cls, ClassLoader* cl, Object* name) {
    char* classNameUTF = toBinaryName(env, name);
    if (!classNameUTF) return NULL;
    Class* clazz = nvmFindClassInClasspathForLoader(env, classNameUTF, cl);
    if (!clazz) return NULL;
    return clazz;
}

