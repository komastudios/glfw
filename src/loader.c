#if defined(_GLFW_MODULE_LOADER)

#define _GLFW_MODULE_LOADER_SOURCE
#include "internal.h"
#include "../include/GLFW/glfw3loader.h"

#include <string.h>

static GLFWmoduleloader _glfwModuleLoader;

void glfwInitModuleLoader(const GLFWmoduleloader* loader)
{
    if (loader)
    {
        if (loader->open && loader->close && loader->resolve)
            _glfwModuleLoader = *loader;
        else
            _glfwInputError(GLFW_INVALID_VALUE, "Missing function in module loader");
    }
    else
        memset(&_glfwModuleLoader, 0, sizeof(GLFWmoduleloader));
}

void* _glfwModuleLoaderOpen(const char* path)
{
    if (_glfwModuleLoader.open)
        return _glfwModuleLoader.open(path, _glfwModuleLoader.user);
    return _glfwPlatformLoadModule(path);
}

void _glfwModuleLoaderClose(void* module)
{
    if (_glfwModuleLoader.close)
        _glfwModuleLoader.close(module, _glfwModuleLoader.user);
    else
        _glfwPlatformFreeModule(module);
}

GLFWproc _glfwModuleLoaderResolve(void* module, const char* name)
{
    if (_glfwModuleLoader.resolve)
        return _glfwModuleLoader.resolve(module, name, _glfwModuleLoader.user);
    return _glfwPlatformGetModuleSymbol(module, name);
}

#endif // _GLFW_MODULE_LOADER
