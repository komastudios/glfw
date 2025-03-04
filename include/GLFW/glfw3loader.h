#ifndef _glfw3_loader_h_
#define _glfw3_loader_h_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (* GLFWmoduleproc)(void);

typedef void* (* GLFWmoduleopenfun)(const char* path, void* user);

typedef void (* GLFWmoduleclosefun)(void* module, void* user);

typedef GLFWmoduleproc (* GLFWmoduleresolvefun)(void* module, const char* name, void* user);

typedef struct GLFWmoduleloader
{
    GLFWmoduleopenfun open;
    GLFWmoduleclosefun close;
    GLFWmoduleresolvefun resolve;
    void* user;
} GLFWmoduleloader;

GLFWAPI void glfwInitModuleLoader(const GLFWmoduleloader* loader);

GLFWAPI void* glfwPlatformLoaderOpen(const char* path);

GLFWAPI void glfwPlatformLoaderClose(void* module);

GLFWAPI GLFWmoduleproc glfwPlatformLoaderResolve(void* module, const char* name);

#ifdef __cplusplus
}
#endif

#endif
