macro(GET_OS_INFO)
    string(REGEX MATCH "Linux" OS_LINUX ${CMAKE_SYSTEM_NAME})
    string(REGEX MATCH "BSD" OS_BSD ${CMAKE_SYSTEM_NAME})
    if(WIN32)
        set(OS_WIN TRUE)
    endif(WIN32)

    if(NOT DEFINED CMINPACK_LIB_INSTALL_DIR)
    set(CMINPACK_LIB_INSTALL_DIR "lib")
    if(OS_LINUX)
        if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
            set(CMINPACK_LIB_INSTALL_DIR "lib64")
        else(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
            set(CMINPACK_LIB_INSTALL_DIR "lib")
        endif(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
        message (STATUS "Operating system is Linux")
    elseif(OS_BSD)
        message (STATUS "Operating system is BSD")
    elseif(OS_WIN)
        message (STATUS "Operating system is Windows")
    else(OS_LINUX)
        message (STATUS "Operating system is generic Unix")
    endif(OS_LINUX)
    endif(NOT DEFINED CMINPACK_LIB_INSTALL_DIR)
    set(CMINPACK_INCLUDE_INSTALL_DIR
        "include/${PROJECT_NAME_LOWER}-${CMINPACK_MAJOR_VERSION}")
endmacro(GET_OS_INFO)


macro(DISSECT_VERSION)
    # Find version components
    string(REGEX REPLACE "^([0-9]+).*" "\\1"
        CMINPACK_MAJOR_VERSION "${CMINPACK_VERSION}")
    string(REGEX REPLACE "^[0-9]+\\.([0-9]+).*" "\\1"
        CMINPACK_MINOR_VERSION "${CMINPACK_VERSION}")
    string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+)" "\\1"
        CMINPACK_REVISION_VERSION ${CMINPACK_VERSION})
    string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1"
        CMINPACK_CANDIDATE_VERSION ${CMINPACK_VERSION})
endmacro(DISSECT_VERSION)

