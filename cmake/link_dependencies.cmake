MACRO(SETMODULEQTTARGETSLIST)
    SET(ARGUMENTS "${ARGN}")
    
    # get module name
    LIST(GET ARGUMENTS 0 MODULENAME)
    
    # check if module is present in modules or libraries
    LIST(FIND PrjExecutables ${MODULENAME} found_in_exec)
    LIST(FIND PrjLibraries ${MODULENAME} found_in_libs)
    
    IF("${found_in_exec}" STREQUAL "-1" AND "${found_in_libs}" STREQUAL "-1")
        MESSAGE(FATAL_ERROR "Could not find Module: " ${MODULENAME})
    ENDIF("${found_in_exec}" STREQUAL "-1" AND "${found_in_libs}" STREQUAL "-1")
    
    # iterate over list
    SET(index 1)
    LIST(LENGTH ARGUMENTS ARGUMENTS_LENGTH)
    WHILE(index LESS ${ARGC})
        LIST(GET ARGUMENTS ${index} ARGUMENT)
        
        # append Target to Module
        LIST(APPEND ${MODULENAME}_QTTARGETS ${ARGUMENT})
        
        # add qt targetes to global list
        LIST(APPEND QTTARGETS ${ARGUMENT})
        
        MATH(EXPR index "${index}+1")
    ENDWHILE(index LESS ${ARGC})
ENDMACRO(SETMODULEQTTARGETSLIST)

MACRO(DEFINEMODULEQTDEPENDENCY)
    # define qt dependencies for each module here
    SETMODULEQTTARGETSLIST(noises Core Widgets Gui)
ENDMACRO(DEFINEMODULEQTDEPENDENCY)

MACRO(LOADQTPACKAGES)
    SET(QTPACKAGELIST ${QTTARGETS})
    LIST(REMOVE_DUPLICATES QTPACKAGELIST)
    
    FOREACH(QTPACKAGE ${QTPACKAGELIST})
        FIND_PACKAGE(Qt5${QTPACKAGE} REQUIRED)
    ENDFOREACH(QTPACKAGE ${QTPACKAGELIST})
ENDMACRO(LOADQTPACKAGES)

MACRO(SETLINKDEPENDENCIES)    
    # for the project
    IF(${PROJECT_DYNAMIC})
        TARGET_LINK_LIBRARIES(noises general base)
        TARGET_LINK_LIBRARIES(simplenoise general base)
    ENDIF(${PROJECT_DYNAMIC})
    
    IF(${PROJECT_DYNAMIC})
        FOREACH(PrjExecutable ${PrjExecutables})
            FOREACH(QTTARGET ${${PrjExecutable}_QTTARGETS})
                TARGET_LINK_LIBRARIES(${PrjExecutable} Qt5::${QTTARGET})
            ENDFOREACH(QTTARGET ${${PrjExecutable}_QTTARGETS})
        ENDFOREACH(PrjExecutable ${PrjExecutables})
        
        FOREACH(PrjLibrary ${PrjLibraries})
            FOREACH(QTTARGET ${${PrjLibrary}_QTTARGETS})
                TARGET_LINK_LIBRARIES(${PrjLibrary} Qt5::${QTTARGET})
            ENDFOREACH(QTTARGET ${${PrjLibrary}_QTTARGETS})
        ENDFOREACH(PrjLibrary ${PrjLibraries})
    ELSE(${PROJECT_DYNAMIC})
        SET(QTLINKTARGETS ${QTTARGETS})
        LIST(REMOVE_DUPLICATES QTLINKTARGETS)
        
        FOREACH(PrjExecutable ${PrjExecutables})
            FOREACH(QTLINKTARGET ${QTLINKTARGETS})
                TARGET_LINK_LIBRARIES(${PrjExecutable} Qt5::${QTLINKTARGET})
            ENDFOREACH(QTLINKTARGET ${QTLINKTARGETS})
        ENDFOREACH(PrjExecutable ${PrjExecutables})
    ENDIF(${PROJECT_DYNAMIC})
ENDMACRO(SETLINKDEPENDENCIES)