cmake_minimum_required(VERSION 3.13)

set(KOS_BASE /opt/toolchains/dc/kos)
set(KOS_CC_BASE /opt/toolchains/dc/sh-elf)
set(KOS_SUBARCH pristine)
set(KOS_PORTS ${KOS_BASE}/../kos-ports)
include_directories(${KOS_PORTS}/include/raylib)
include(${KOS_BASE}/utils/cmake/dreamcast.toolchain.cmake)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(DreamDisc C)

set(CMAKE_C_STANDARD 23)

SET (SRCS main.c
    src/controller.c
    src/save.c
    src/background.c
    src/scenes/mainmenu.c
    src/scenes/game.c
    src/scene.c
    src/ui.c


)

add_executable(DreamDisc ${SRCS})
target_link_libraries(DreamDisc raylib GL m z ADX)

kos_add_romdisk(DreamDisc romdisk)
