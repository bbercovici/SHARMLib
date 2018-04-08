# MIT License

# Copyright (c) 2018 Benjamin Bercovici and Jay McMahon

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

if (EXISTS /home/bebe0705/.am_fortuna)
	set(IS_FORTUNA ON)
	message("-- This is Fortuna")

else()
	set(IS_FORTUNA OFF)
endif()


if(${IS_FORTUNA})
	set(SHARMLIB_INCLUDE_HEADER /home/bebe0705/libs/local/include/SHARMLib/)
	set(SHARMLIB_LIBRARY /home/bebe0705/libs/local/lib/libSHARMLib.so)

else()
	set(SHARMLIB_INCLUDE_HEADER /usr/local/include/SHARMLib/)

	if (APPLE)
		set(SHARMLIB_LIBRARY /usr/local/lib/libSHARMLib.dylib)
	elseif(UNIX AND NOT APPLE)
		set(SHARMLIB_LIBRARY /usr/local/lib/libSHARMLib.so)
	else()
		message(FATAL_ERROR "Unsupported platform")
	endif()
endif()


message("-- Found SHARMLib: " ${SHARMLIB_LIBRARY})
