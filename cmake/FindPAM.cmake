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


# - Try to find the PAM libraries
# Once done this will define
#
#  PAM_FOUND - system has pam
#  PAM_INCLUDE_DIR - the pam include directory
#  PAM_LIBRARIES - libpam library

if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
	# Already in cache, be silent
	set(PAM_FIND_QUIETLY TRUE)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)

find_path(PAM_INCLUDE_DIR NAMES security/pam_appl.h pam/pam_appl.h)
find_library(PAM_LIBRARY pam )
find_library(PAM_MISC_LIBRARY pam_misc )
find_library(DL_LIBRARY dl)

if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
	set(PAM_FOUND TRUE)
	if (DL_LIBRARY)
		set(PAM_LIBRARIES ${PAM_MISC_LIBRARY} ${PAM_LIBRARY} ${DL_LIBRARY})
	else (DL_LIBRARY)
		set(PAM_LIBRARIES ${PAM_LIBRARY} ${PAM_MISC_LIBRARY})
	endif (DL_LIBRARY)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)

if (PAM_FOUND)
	if (NOT PAM_FIND_QUIETLY)
		message(STATUS "Found PAM: ${PAM_LIBRARIES}")
	endif (NOT PAM_FIND_QUIETLY)
else (PAM_FOUND)
	if (PAM_FIND_REQUIRED)
		message(FATAL_ERROR "PAM was not found")
	endif(PAM_FIND_REQUIRED)
endif (PAM_FOUND)

mark_as_advanced(PAM_INCLUDE_DIR PAM_LIBRARY DL_LIBRARY PAM_MESSAGE_CONST)
