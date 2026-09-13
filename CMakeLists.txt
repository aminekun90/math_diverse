# MathDiverse — build moderne d'un programme console de 2010-2014.
#
# Windows : le code d'origine, API console native + PlaySound (winmm).
# POSIX   : platform/ réimplémente conio.h, le sous-ensemble Win32 utilisé et
#           les 91 appels à system(), en séquences ANSI et termios. Aucun
#           fichier de logique n'est modifié.
cmake_minimum_required(VERSION 3.20)
project(MathDiverse VERSION 1.6.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Les 25 unités du projet Dev-C++ d'origine (MathDiverse.dev).
set(MD_SOURCES
  main.cpp
  diverse.cpp
  tetris.cpp
  allumettes.c
  Morpion/morpion.c
  Morpion/gestion.c
  Morpion/tictac.c
  snake/snakesource.cpp
  snake/console.cpp
  snake/game.cpp
  snake/menu.cpp
  snake/snake.cpp
  snake/wall.cpp
  snake/apple.cpp
)

if(NOT WIN32)
  list(APPEND MD_SOURCES platform/compat.c)
endif()

add_executable(MathDiverse ${MD_SOURCES})
target_include_directories(MathDiverse PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
  target_link_libraries(MathDiverse PRIVATE winmm)
else()
  # Le son passe par le lecteur du système (afplay, paplay, aplay) : rien à lier.
  target_compile_definitions(MathDiverse PRIVATE _GNU_SOURCE)
endif()

if(MSVC)
  target_compile_definitions(MathDiverse PRIVATE _CRT_SECURE_NO_WARNINGS)
  target_compile_options(MathDiverse PRIVATE /utf-8)
endif()

# Le jeu lit tetris.wav et a.xm à côté de l'exécutable.
foreach(asset tetris.wav a.xm)
  add_custom_command(TARGET MathDiverse POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/${asset} $<TARGET_FILE_DIR:MathDiverse>/${asset})
endforeach()
