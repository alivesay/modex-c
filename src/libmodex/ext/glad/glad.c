/*

    OpenGL ES loader generated by glad 0.1.10a0 on Thu May 12 09:27:11 2016.

    Language/Generator: C/C++
    Specification: gl
    APIs: gles2=2.0
    Profile: core
    Extensions:
        
    Loader: True
    Local files: False
    Omit khrplatform: True

    Commandline:
        --profile="core" --api="gles2=2.0" --generator="c" --spec="gl" --omit-khrplatform --extensions=""
    Online:
        http://glad.dav1d.de/#profile=core&language=c&specification=gl&loader=on&api=gles2%3D2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/glad.h>

struct gladGLversionStruct GLVersion;

#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
#define _GLAD_IS_SOME_NEW_VERSION 1
#endif

static int max_loaded_major;
static int max_loaded_minor;

static const char *exts = NULL;
static int num_exts_i = 0;
static const char **exts_i = NULL;

static int get_exts(void) {
#ifdef _GLAD_IS_SOME_NEW_VERSION
    if(max_loaded_major < 3) {
#endif
        exts = (const char *)glGetString(GL_EXTENSIONS);
#ifdef _GLAD_IS_SOME_NEW_VERSION
    } else {
        int index;

        num_exts_i = 0;
        glGetIntegerv(GL_NUM_EXTENSIONS, &num_exts_i);
        if (num_exts_i > 0) {
            exts_i = (const char **)realloc((void *)exts_i, num_exts_i * sizeof *exts_i);
        }

        if (exts_i == NULL) {
            return 0;
        }

        for(index = 0; index < num_exts_i; index++) {
            exts_i[index] = (const char*)glGetStringi(GL_EXTENSIONS, index);
        }
    }
#endif
    return 1;
}

static void free_exts(void) {
    if (exts_i != NULL) {
        free((char **)exts_i);
        exts_i = NULL;
    }
}

static int has_ext(const char *ext) {
#ifdef _GLAD_IS_SOME_NEW_VERSION
    if(max_loaded_major < 3) {
#endif
        const char *extensions;
        const char *loc;
        const char *terminator;
        extensions = exts;
        if(extensions == NULL || ext == NULL) {
            return 0;
        }

        while(1) {
            loc = strstr(extensions, ext);
            if(loc == NULL) {
                return 0;
            }

            terminator = loc + strlen(ext);
            if((loc == extensions || *(loc - 1) == ' ') &&
                (*terminator == ' ' || *terminator == '\0')) {
                return 1;
            }
            extensions = terminator;
        }
#ifdef _GLAD_IS_SOME_NEW_VERSION
    } else {
        int index;

        for(index = 0; index < num_exts_i; index++) {
            const char *e = exts_i[index];

            if(strcmp(e, ext) == 0) {
                return 1;
            }
        }
    }
#endif

    return 0;
}
int GLAD_GL_ES_VERSION_2_0;
PFNGLISTEXTUREPROC glad_glIsTexture;
PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
PFNGLDEPTHFUNCPROC glad_glDepthFunc;
PFNGLUNIFORM4FVPROC glad_glUniform4fv;
PFNGLUNIFORM4IVPROC glad_glUniform4iv;
PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage;
PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv;
PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource;
PFNGLRELEASESHADERCOMPILERPROC glad_glReleaseShaderCompiler;
PFNGLUNIFORM1FPROC glad_glUniform1f;
PFNGLUNIFORM2FVPROC glad_glUniform2fv;
PFNGLSCISSORPROC glad_glScissor;
PFNGLENABLEPROC glad_glEnable;
PFNGLUNIFORM3IVPROC glad_glUniform3iv;
PFNGLHINTPROC glad_glHint;
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
PFNGLBLENDEQUATIONPROC glad_glBlendEquation;
PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv;
PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate;
PFNGLGETSHADERPRECISIONFORMATPROC glad_glGetShaderPrecisionFormat;
PFNGLUNIFORM3FPROC glad_glUniform3f;
PFNGLUNIFORM2FPROC glad_glUniform2f;
PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate;
PFNGLDISABLEPROC glad_glDisable;
PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate;
PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer;
PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders;
PFNGLGETUNIFORMIVPROC glad_glGetUniformiv;
PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f;
PFNGLREADPIXELSPROC glad_glReadPixels;
PFNGLLINKPROGRAMPROC glad_glLinkProgram;
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
PFNGLSHADERSOURCEPROC glad_glShaderSource;
PFNGLBUFFERDATAPROC glad_glBufferData;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv;
PFNGLISSHADERPROC glad_glIsShader;
PFNGLBINDBUFFERPROC glad_glBindBuffer;
PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv;
PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer;
PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
PFNGLDETACHSHADERPROC glad_glDetachShader;
PFNGLSTENCILOPPROC glad_glStencilOp;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus;
PFNGLBLENDFUNCPROC glad_glBlendFunc;
PFNGLGETFLOATVPROC glad_glGetFloatv;
PFNGLDEPTHRANGEFPROC glad_glDepthRangef;
PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers;
PFNGLDELETESHADERPROC glad_glDeleteShader;
PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;
PFNGLISENABLEDPROC glad_glIsEnabled;
PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;
PFNGLCLEARDEPTHFPROC glad_glClearDepthf;
PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset;
PFNGLUNIFORM1IPROC glad_glUniform1i;
PFNGLLINEWIDTHPROC glad_glLineWidth;
PFNGLCLEARPROC glad_glClear;
PFNGLGETSHADERIVPROC glad_glGetShaderiv;
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv;
PFNGLVIEWPORTPROC glad_glViewport;
PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D;
PFNGLUNIFORM4FPROC glad_glUniform4f;
PFNGLGETUNIFORMFVPROC glad_glGetUniformfv;
PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
PFNGLDRAWELEMENTSPROC glad_glDrawElements;
PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation;
PFNGLSTENCILFUNCPROC glad_glStencilFunc;
PFNGLUNIFORM2IPROC glad_glUniform2i;
PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib;
PFNGLISPROGRAMPROC glad_glIsProgram;
PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv;
PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f;
PFNGLDEPTHMASKPROC glad_glDepthMask;
PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv;
PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers;
PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D;
PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers;
PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate;
PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv;
PFNGLUNIFORM3IPROC glad_glUniform3i;
PFNGLGETINTEGERVPROC glad_glGetIntegerv;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D;
PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform;
PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers;
PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation;
PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram;
PFNGLBLENDCOLORPROC glad_glBlendColor;
PFNGLDRAWARRAYSPROC glad_glDrawArrays;
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData;
PFNGLCREATESHADERPROC glad_glCreateShader;
PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv;
PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
PFNGLUNIFORM1IVPROC glad_glUniform1iv;
PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D;
PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv;
PFNGLGETBOOLEANVPROC glad_glGetBooleanv;
PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D;
PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D;
PFNGLGETERRORPROC glad_glGetError;
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
PFNGLFINISHPROC glad_glFinish;
PFNGLUNIFORM1FVPROC glad_glUniform1fv;
PFNGLUSEPROGRAMPROC glad_glUseProgram;
PFNGLCOLORMASKPROC glad_glColorMask;
PFNGLGENTEXTURESPROC glad_glGenTextures;
PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
PFNGLATTACHSHADERPROC glad_glAttachShader;
PFNGLTEXPARAMETERFPROC glad_glTexParameterf;
PFNGLPIXELSTOREIPROC glad_glPixelStorei;
PFNGLUNIFORM2IVPROC glad_glUniform2iv;
PFNGLUNIFORM3FVPROC glad_glUniform3fv;
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
PFNGLSTENCILMASKPROC glad_glStencilMask;
PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;
PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer;
PFNGLFRONTFACEPROC glad_glFrontFace;
PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f;
PFNGLGENBUFFERSPROC glad_glGenBuffers;
PFNGLCLEARCOLORPROC glad_glClearColor;
PFNGLSHADERBINARYPROC glad_glShaderBinary;
PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f;
PFNGLCLEARSTENCILPROC glad_glClearStencil;
PFNGLFLUSHPROC glad_glFlush;
PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv;
PFNGLCULLFACEPROC glad_glCullFace;
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
PFNGLGETSTRINGPROC glad_glGetString;
PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv;
PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer;
PFNGLBINDTEXTUREPROC glad_glBindTexture;
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
PFNGLUNIFORM4IPROC glad_glUniform4i;
PFNGLCOMPILESHADERPROC glad_glCompileShader;
PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate;
PFNGLISBUFFERPROC glad_glIsBuffer;
static void load_GL_ES_VERSION_2_0(GLADloadproc load) {
	if(!GLAD_GL_ES_VERSION_2_0) return;
	glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)load("glActiveTexture");
	glad_glAttachShader = (PFNGLATTACHSHADERPROC)load("glAttachShader");
	glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)load("glBindAttribLocation");
	glad_glBindBuffer = (PFNGLBINDBUFFERPROC)load("glBindBuffer");
	glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)load("glBindFramebuffer");
	glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)load("glBindRenderbuffer");
	glad_glBindTexture = (PFNGLBINDTEXTUREPROC)load("glBindTexture");
	glad_glBlendColor = (PFNGLBLENDCOLORPROC)load("glBlendColor");
	glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC)load("glBlendEquation");
	glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)load("glBlendEquationSeparate");
	glad_glBlendFunc = (PFNGLBLENDFUNCPROC)load("glBlendFunc");
	glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)load("glBlendFuncSeparate");
	glad_glBufferData = (PFNGLBUFFERDATAPROC)load("glBufferData");
	glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)load("glBufferSubData");
	glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)load("glCheckFramebufferStatus");
	glad_glClear = (PFNGLCLEARPROC)load("glClear");
	glad_glClearColor = (PFNGLCLEARCOLORPROC)load("glClearColor");
	glad_glClearDepthf = (PFNGLCLEARDEPTHFPROC)load("glClearDepthf");
	glad_glClearStencil = (PFNGLCLEARSTENCILPROC)load("glClearStencil");
	glad_glColorMask = (PFNGLCOLORMASKPROC)load("glColorMask");
	glad_glCompileShader = (PFNGLCOMPILESHADERPROC)load("glCompileShader");
	glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)load("glCompressedTexImage2D");
	glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)load("glCompressedTexSubImage2D");
	glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)load("glCopyTexImage2D");
	glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)load("glCopyTexSubImage2D");
	glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)load("glCreateProgram");
	glad_glCreateShader = (PFNGLCREATESHADERPROC)load("glCreateShader");
	glad_glCullFace = (PFNGLCULLFACEPROC)load("glCullFace");
	glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)load("glDeleteBuffers");
	glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)load("glDeleteFramebuffers");
	glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)load("glDeleteProgram");
	glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)load("glDeleteRenderbuffers");
	glad_glDeleteShader = (PFNGLDELETESHADERPROC)load("glDeleteShader");
	glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC)load("glDeleteTextures");
	glad_glDepthFunc = (PFNGLDEPTHFUNCPROC)load("glDepthFunc");
	glad_glDepthMask = (PFNGLDEPTHMASKPROC)load("glDepthMask");
	glad_glDepthRangef = (PFNGLDEPTHRANGEFPROC)load("glDepthRangef");
	glad_glDetachShader = (PFNGLDETACHSHADERPROC)load("glDetachShader");
	glad_glDisable = (PFNGLDISABLEPROC)load("glDisable");
	glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)load("glDisableVertexAttribArray");
	glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)load("glDrawArrays");
	glad_glDrawElements = (PFNGLDRAWELEMENTSPROC)load("glDrawElements");
	glad_glEnable = (PFNGLENABLEPROC)load("glEnable");
	glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)load("glEnableVertexAttribArray");
	glad_glFinish = (PFNGLFINISHPROC)load("glFinish");
	glad_glFlush = (PFNGLFLUSHPROC)load("glFlush");
	glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)load("glFramebufferRenderbuffer");
	glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)load("glFramebufferTexture2D");
	glad_glFrontFace = (PFNGLFRONTFACEPROC)load("glFrontFace");
	glad_glGenBuffers = (PFNGLGENBUFFERSPROC)load("glGenBuffers");
	glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)load("glGenerateMipmap");
	glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)load("glGenFramebuffers");
	glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)load("glGenRenderbuffers");
	glad_glGenTextures = (PFNGLGENTEXTURESPROC)load("glGenTextures");
	glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)load("glGetActiveAttrib");
	glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)load("glGetActiveUniform");
	glad_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)load("glGetAttachedShaders");
	glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)load("glGetAttribLocation");
	glad_glGetBooleanv = (PFNGLGETBOOLEANVPROC)load("glGetBooleanv");
	glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)load("glGetBufferParameteriv");
	glad_glGetError = (PFNGLGETERRORPROC)load("glGetError");
	glad_glGetFloatv = (PFNGLGETFLOATVPROC)load("glGetFloatv");
	glad_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetFramebufferAttachmentParameteriv");
	glad_glGetIntegerv = (PFNGLGETINTEGERVPROC)load("glGetIntegerv");
	glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)load("glGetProgramiv");
	glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)load("glGetProgramInfoLog");
	glad_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)load("glGetRenderbufferParameteriv");
	glad_glGetShaderiv = (PFNGLGETSHADERIVPROC)load("glGetShaderiv");
	glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)load("glGetShaderInfoLog");
	glad_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)load("glGetShaderPrecisionFormat");
	glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)load("glGetShaderSource");
	glad_glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
	glad_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)load("glGetTexParameterfv");
	glad_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)load("glGetTexParameteriv");
	glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)load("glGetUniformfv");
	glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)load("glGetUniformiv");
	glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)load("glGetUniformLocation");
	glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)load("glGetVertexAttribfv");
	glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)load("glGetVertexAttribiv");
	glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)load("glGetVertexAttribPointerv");
	glad_glHint = (PFNGLHINTPROC)load("glHint");
	glad_glIsBuffer = (PFNGLISBUFFERPROC)load("glIsBuffer");
	glad_glIsEnabled = (PFNGLISENABLEDPROC)load("glIsEnabled");
	glad_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)load("glIsFramebuffer");
	glad_glIsProgram = (PFNGLISPROGRAMPROC)load("glIsProgram");
	glad_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)load("glIsRenderbuffer");
	glad_glIsShader = (PFNGLISSHADERPROC)load("glIsShader");
	glad_glIsTexture = (PFNGLISTEXTUREPROC)load("glIsTexture");
	glad_glLineWidth = (PFNGLLINEWIDTHPROC)load("glLineWidth");
	glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)load("glLinkProgram");
	glad_glPixelStorei = (PFNGLPIXELSTOREIPROC)load("glPixelStorei");
	glad_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)load("glPolygonOffset");
	glad_glReadPixels = (PFNGLREADPIXELSPROC)load("glReadPixels");
	glad_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)load("glReleaseShaderCompiler");
	glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)load("glRenderbufferStorage");
	glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)load("glSampleCoverage");
	glad_glScissor = (PFNGLSCISSORPROC)load("glScissor");
	glad_glShaderBinary = (PFNGLSHADERBINARYPROC)load("glShaderBinary");
	glad_glShaderSource = (PFNGLSHADERSOURCEPROC)load("glShaderSource");
	glad_glStencilFunc = (PFNGLSTENCILFUNCPROC)load("glStencilFunc");
	glad_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)load("glStencilFuncSeparate");
	glad_glStencilMask = (PFNGLSTENCILMASKPROC)load("glStencilMask");
	glad_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)load("glStencilMaskSeparate");
	glad_glStencilOp = (PFNGLSTENCILOPPROC)load("glStencilOp");
	glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)load("glStencilOpSeparate");
	glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC)load("glTexImage2D");
	glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC)load("glTexParameterf");
	glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)load("glTexParameterfv");
	glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC)load("glTexParameteri");
	glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)load("glTexParameteriv");
	glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)load("glTexSubImage2D");
	glad_glUniform1f = (PFNGLUNIFORM1FPROC)load("glUniform1f");
	glad_glUniform1fv = (PFNGLUNIFORM1FVPROC)load("glUniform1fv");
	glad_glUniform1i = (PFNGLUNIFORM1IPROC)load("glUniform1i");
	glad_glUniform1iv = (PFNGLUNIFORM1IVPROC)load("glUniform1iv");
	glad_glUniform2f = (PFNGLUNIFORM2FPROC)load("glUniform2f");
	glad_glUniform2fv = (PFNGLUNIFORM2FVPROC)load("glUniform2fv");
	glad_glUniform2i = (PFNGLUNIFORM2IPROC)load("glUniform2i");
	glad_glUniform2iv = (PFNGLUNIFORM2IVPROC)load("glUniform2iv");
	glad_glUniform3f = (PFNGLUNIFORM3FPROC)load("glUniform3f");
	glad_glUniform3fv = (PFNGLUNIFORM3FVPROC)load("glUniform3fv");
	glad_glUniform3i = (PFNGLUNIFORM3IPROC)load("glUniform3i");
	glad_glUniform3iv = (PFNGLUNIFORM3IVPROC)load("glUniform3iv");
	glad_glUniform4f = (PFNGLUNIFORM4FPROC)load("glUniform4f");
	glad_glUniform4fv = (PFNGLUNIFORM4FVPROC)load("glUniform4fv");
	glad_glUniform4i = (PFNGLUNIFORM4IPROC)load("glUniform4i");
	glad_glUniform4iv = (PFNGLUNIFORM4IVPROC)load("glUniform4iv");
	glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)load("glUniformMatrix2fv");
	glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)load("glUniformMatrix3fv");
	glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)load("glUniformMatrix4fv");
	glad_glUseProgram = (PFNGLUSEPROGRAMPROC)load("glUseProgram");
	glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)load("glValidateProgram");
	glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)load("glVertexAttrib1f");
	glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)load("glVertexAttrib1fv");
	glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)load("glVertexAttrib2f");
	glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)load("glVertexAttrib2fv");
	glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)load("glVertexAttrib3f");
	glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)load("glVertexAttrib3fv");
	glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)load("glVertexAttrib4f");
	glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)load("glVertexAttrib4fv");
	glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)load("glVertexAttribPointer");
	glad_glViewport = (PFNGLVIEWPORTPROC)load("glViewport");
}
static int find_extensionsGLES2(void) {
	if (!get_exts()) return 0;
	free_exts();
	return 1;
}

static void find_coreGLES2(void) {

    /* Thank you @elmindreda
     * https://github.com/elmindreda/greg/blob/master/templates/greg.c.in#L176
     * https://github.com/glfw/glfw/blob/master/src/context.c#L36
     */
    int i, major, minor;

    const char* version;
    const char* prefixes[] = {
        "OpenGL ES-CM ",
        "OpenGL ES-CL ",
        "OpenGL ES ",
        NULL
    };

    version = (const char*) glGetString(GL_VERSION);
    if (!version) return;

    for (i = 0;  prefixes[i];  i++) {
        const size_t length = strlen(prefixes[i]);
        if (strncmp(version, prefixes[i], length) == 0) {
            version += length;
            break;
        }
    }

/* PR #18 */
#ifdef _MSC_VER
    sscanf_s(version, "%d.%d", &major, &minor);
#else
    sscanf(version, "%d.%d", &major, &minor);
#endif

    GLVersion.major = major; GLVersion.minor = minor;
    max_loaded_major = major; max_loaded_minor = minor;
	GLAD_GL_ES_VERSION_2_0 = (major == 2 && minor >= 0) || major > 2;
	if (GLVersion.major > 2 || (GLVersion.major >= 2 && GLVersion.minor >= 0)) {
		max_loaded_major = 2;
		max_loaded_minor = 0;
	}
}

int gladLoadGLES2Loader(GLADloadproc load) {
	GLVersion.major = 0; GLVersion.minor = 0;
	glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
	if(glGetString == NULL) return 0;
	if(glGetString(GL_VERSION) == NULL) return 0;
	find_coreGLES2();
	load_GL_ES_VERSION_2_0(load);

	if (!find_extensionsGLES2()) return 0;
	return GLVersion.major != 0 || GLVersion.minor != 0;
}

