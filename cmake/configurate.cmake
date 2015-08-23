MACRO(CONFIGURATE)
    # set project name
    SET(PrjName Noises)

    # define libraries
    SET(PrjLibraries 
        base
        simplenoise)

    # define executables
    SET(PrjExecutables 
        noises)
ENDMACRO(CONFIGURATE)

MACRO(DEFINEMODULEQTDEPENDENCY)
    SETMODULEQTTARGETSLIST(noises Core Widgets Gui)
ENDMACRO(DEFINEMODULEQTDEPENDENCY)

MACRO(DEFINEMODULELINKDEPENDENCY)
    SETMODULELINKTARGETSLIST(noises base)
    SETMODULELINKTARGETSLIST(simplenoise base)
ENDMACRO(DEFINEMODULELINKDEPENDENCY)