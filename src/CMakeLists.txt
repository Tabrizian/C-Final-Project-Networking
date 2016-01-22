# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

set(SOURCES main.c multiplayer.h)

if(WIN32)
	set(SOURCES ${SOURCES} multiplayer-win32.c)
	target_link_libraries(good.out wsock32)
else()
	set(SOURCES ${SOURCES} multiplayer-unix.c)
endif()
add_executable(good.out ${SOURCES})

# Add personal c flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -DDEBUG")
