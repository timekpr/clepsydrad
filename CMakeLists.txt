# Copyright (c) 2016 Olli-Pekka Wallin <opwallin@gmail.com>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

project(clepsydrad)
cmake_minimum_required(VERSION 2.8)

#-----------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
#-----------

# Set version
set(CLEPSYDRAD_VERSION_MAJOR 0)
set(CLEPSYDRAD_VERSION_MINOR 1)
set(CLEPSYDRAD_VERSION_PATCH 0)
set(CLEPSYDRAD_VERSION_STRING "${CLEPSYDRAD_VERSION_MAJOR}.${CLEPSYDRAD_VERSION_MINOR}.${CLEPSYDRAD_VERSION_PATCH}")

SET(SRC_LIST
    main.c
    linked_list.c
    config.h
    readconf.c
    pamcheck.c
    pamcheck.h
    c_socket.h
)

if(NOT NO_PAM)
    MESSAGE(STATUS "PAM LIB REQUIRED ")
    find_package(PAM REQUIRED)
    if(PAM_FOUND)
        add_definitions(-DUSE_PAM)
    endif()
endif()

if (NOT NO_JSON)
   #find_package(JSON REQUIRED)
   MESSAGE(STATUS "JSON LIB REQUIRED ")
   if(JSON_FOUND)
       add_definitions(-DUSE_JSON)
   endif()
endif()          

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(LIBS ${LIBS} ${PAM_LIBRARIES} ${JSON_LIBRARY})
set(LIBS ${LIBS})

target_link_libraries(${PROJECT_NAME} ${JSON_LIBRARY} ${PAM_LIBRARIES})
target_link_libraries(${PROJECT_NAME})

