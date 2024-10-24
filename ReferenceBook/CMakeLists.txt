# CMakeList.txt : CMake project for ReferenceBook, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

if (NOT WIN32)
  message(FATAL_ERROR "This project can only be compiled on Windows.")
endif()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ReferenceBook")

# Add source to this project's executable.
add_executable (ReferenceBook
        main.cpp
        System/Headers/Contact.h
        System/Source/Contact.cpp
        System/Headers/ContactBook.h
        System/Source/ContactBook.cpp
        System/Headers/Account.h
        System/Source/Account.cpp
        System/Headers/FileManager.h
        System/Source/FileManager.cpp
        System/Headers/Serializable.h
        System/Source/Serializable.cpp
        System/Headers/Date.h
        System/Source/Date.cpp
        System/Headers/TimeManager.h
        System/Source/TimeManager.cpp
        System/Headers/Tag.h
        System/Source/Tag.cpp
        UI/Headers/Button.h
        UI/Source/Button.cpp
        UI/Headers/Menu.h
        UI/Source/Menu.cpp
        UI/Headers/Object.h
        UI/Source/Object.cpp
        UI/Headers/Visual.h
        UI/Source/Visual.cpp
        UI/Headers/ConsoleManager.h
        UI/Source/ConsoleManager.cpp
        UI/Headers/TimeButton.h
        UI/Source/TimeButton.cpp
        UI/Headers/ContactInfoMenu.h
        UI/Source/ContactInfoMenu.cpp
        UI/Headers/ContactMenu.h
        UI/Source/ContactMenu.cpp
        UI/Headers/UserManualMenu.h
        UI/Source/UserManualMenu.cpp
        Enums/Color.h
        UI/Headers/AddContactMenu.h
        UI/Source/AddContactMenu.cpp
        UI/Headers/EditContactMenu.h
        UI/Headers/DeleteContactMenu.h
        UI/Source/DeleteContactMenu.cpp
        UI/Source/EditContactMenu.cpp
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ReferenceBook PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
