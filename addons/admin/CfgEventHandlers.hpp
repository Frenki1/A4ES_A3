class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};
class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};
class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMPInterrupt {
        ADDON = QUOTE([ARR_2('RscDisplayMPInterrupt', _this)] call COMPILE_FILE(XEH_displayLoad));
    };
};
