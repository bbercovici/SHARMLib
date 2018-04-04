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
