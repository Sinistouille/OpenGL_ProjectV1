cmake_minimum_required(VERSION 3.3)
project(OpenGL_ProjectV1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_FILES main.c)

find_package(OpenGL REQUIRED)
#find_package(glfw3 3.4 REQUIRED)
#find_package(Vulkan REQUIRED)

include_directories("C:/Users/Maxence/Documents/Dev/C.PP/Dependencies/GLAD/include")
include_directories("C:/VulkanSDK/1.3.290.0/Include")
include_directories("C:/Users/Maxence/Documents/Dev/C.PP/Dependencies/GLFW/glfw-3.4/include/")
link_directories("C:/Users/Maxence/Documents/Dev/C.PP/Dependencies/GLFW/glfw-3.4/lib")



add_executable(main WIN32 ${SOURCE_FILES})

target_link_libraries(main glfw3)
#target_link_libraries(main OpenGL::GL)