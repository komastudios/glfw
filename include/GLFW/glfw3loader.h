#ifndef _glfw3_loader_h_
#define _glfw3_loader_h_

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (* GLFWmoduleopenfun)(const char* path, void* user);

typedef void (* GLFWmoduleclosefun)(void* module, void* user);

typedef GLFWproc (* GLFWmoduleresolvefun)(void* module, const char* name, void* user);

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

GLFWAPI GLFWproc glfwPlatformLoaderResolve(void* module, const char* name);

#ifdef __cplusplus
}
#endif

#endif
