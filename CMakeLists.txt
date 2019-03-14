cmake_minimum_required (VERSION 3.0)

# Project step I: Check dependencies and find packages
# ------------------------------------------------------------------------------------------------------
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

#find_package(YOUR_PACKAGE REQUIRED)

# Project step II: Set up project name
# ------------------------------------------------------------------------------------------------------
set(PROJ_MAIN_NAME ncurses_windows_manager)

# Required libraries, flags, and include files for compiling and linking against PROJ_MAIN_NAME (all targets)
set(${PROJ_MAIN_NAME}_LIBS "ncurses")
set(${PROJ_MAIN_NAME}_DEFS "")
set(${PROJ_MAIN_NAME}_INCS "")
set(${PROJ_MAIN_NAME}_PATH "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "Base project path" FORCE)
set(RESOURCES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources" CACHE PATH "Setting resources path" FORCE)

# Set up a custom install path
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "Changing default install path" FORCE)
endif()

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

list(APPEND ${PROJ_MAIN_NAME}_EXTRA_INCS )  # Add your extra include path here
list(APPEND ${PROJ_MAIN_NAME}_EXTRA_LIBS )  # Add your extra libs here

# Project step III: Add modules
# ------------------------------------------------------------------------------------------------------
add_subdirectory(modules)

# Project step IV: Add examples
# ------------------------------------------------------------------------------------------------------
add_subdirectory(samples)

# Custom target to restore Terminal if crash
# ------------------------------------------------------------------------------------------------------
add_custom_target(restore_terminal COMMAND stty sane)
