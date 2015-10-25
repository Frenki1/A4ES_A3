#include "script_component.hpp"
class CfgPatches
{
    class ADDON
    {
        units[] = {};
        weapons[] = {"a3cs_dummyVest"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"a3cs_main", "a3cs_common"};
        version = A3CS_VERSION;
        versionStr = QUOTE(A3CS_VERSION);
        versionAr[] = A3CS_VERSION_ARRAY;
        author[] = {"SzwedzikPL", "ACE3 Team"};
        authorUrl = "http://arma3coop.pl";
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE(call COMPILE_FILE(XEH_clientInit));
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_Killed_EventHandlers {
    class CAManBase {
        class ADDON {
            killed = QUOTE(call FUNC(removeDummyVest));
        };
    };
};

class CfgFactionClasses
{
    class NO_CATEGORY;
    class a3cs_modules: NO_CATEGORY
    {
        displayName = "A3CS";
    };
    class a3cs_modules_supplies: NO_CATEGORY
    {
        displayName = "Zaopatrzenie";
    };
    class a3cs_modules_support: NO_CATEGORY
    {
        displayName = "Wsparcie";
    };
    class a3cs_modules_interactions: NO_CATEGORY
    {
        displayName = "Interakcje";
    };
    class a3cs_modules_tasks: NO_CATEGORY
    {
        displayName = "Zadania";
    };
    class a3cs_modules_effects: NO_CATEGORY
    {
        displayName = "Efekty";
    };
    class a3cs_modules_ai: NO_CATEGORY
    {
        displayName = "AI";
    };
    class a3cs_modules_settings: NO_CATEGORY
    {
        displayName = "Ustawienia";
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgSounds.hpp"

#include "dialogs.hpp"

/*
class CfgFunctions
{
    class PAM_Modules
    {
        class PAM_Modules
        {
            file = PATHTOF(functions);
            class moduleCCEffect {};
            class moduleSoundEffect {};
            class moduleBreathFogEffect {};
            class moduleFogEffect {};
            class moduleSandEffect {};
            class moduleSnowEffect {};

            class moduleCCEffectLocal {};
            class moduleSoundEffectLocal {};
            class moduleBreathFogEffectLocal {};
            class moduleFogEffectLocal {};
            class moduleSandEffectLocal {};
            class moduleSnowEffectLocal {};
        };
    };
};
class CfgFactionClasses
{
    class NO_CATEGORY;
    class a3cs_modules: NO_CATEGORY
    {
        displayName = "A3CS: Efekty";
    };
};

class CfgVehicles
{
    class Module_F;
    class A3C_Module: Module_F
    {
        scope = 0;
        scopeCurator = 0;
        isGlobal = 0;

        class ModuleDescription {};
    };
    class PAM_Modules_CC_Effect: A3C_Module
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "Efekty kolorystyczne";
        category = "a3cs_modules";
        function = "PAM_Modules_fnc_moduleCCEffect";
        isTriggerActivated = 1;
        isDisposable = 0;

        class Arguments
        {
            class EffectType
            {
                displayName = "Typ efektu";
                description = "Typ efektu widocznego na ekranie po uruchomieniu modułu";
                typeName = "STRING";
                class values
                {
                    class Effect01 {
                        name = "DayZ Standalone";
                        value = "dayz";
                        default = 1;
                    };
                    class Effect02 {
                        name = "Operation Flashpoint";
                        value = "ofp";
                        default = 0;
                    };
                    class Effect03 {
                        name = "Arma 2";
                        value = "a2";
                        default = 0;
                    };
                    class Effect04 {
                        name = "Arma 2 OA";
                        value = "a2oa";
                        default = 0;
                    };
                    class Effect05 {
                        name = "Zima";
                        value = "zima";
                        default = 0;
                    };
                    class Effect06 {
                        name = "Wiosna";
                        value = "wiosna";
                        default = 0;
                    };
                    class Effect07 {
                        name = "Jesien";
                        value = "jesien";
                        default = 0;
                    };
                    class Effect08 {
                        name = "Sloneczny dzien";
                        value = "sloneczny_dzien";
                        default = 0;
                    };
                    class Effect09 {
                        name = "Deszczowy dzien";
                        value = "deszczowy_dzien";
                        default = 0;
                    };
                    class Effect10 {
                        name = "Afryka";
                        value = "afryka";
                        default = 0;
                    };
                    class Effect11 {
                        name = "Pustynia";
                        value = "pustynia";
                        default = 0;
                    };
                    class Effect12 {
                        name = "Postapo";
                        value = "postapo";
                        default = 0;
                    };
                };
            };
        };
        class ModuleDescription: ModuleDescription
        {
            description = "Zmiana kolorystyki widocznej w grze.";
            sync[] = {};
            position = 1;
        };
    };
    class PAM_Modules_Sound_Effect: A3C_Module
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "Efekty dzwiekowe";
        category = "a3cs_modules";
        function = "PAM_Modules_fnc_moduleSoundEffect";
        isTriggerActivated = 1;
        isDisposable = 0;

        class Arguments
        {
            class EffectType
            {
                displayName = "Dzwiek";
                description = "Rodzaj odtwarzanego dzwieku";
                typeName = "STRING";
                class values
                {
                                        class Effect01 {
                                                name = "Dzwiek #1";
                                                value = "pam_module_soundeffect_01";
                                                default = 1;
                                        };
                                        class Effect02 {
                                                name = "Dzwiek #2";
                                                value = "pam_module_soundeffect_02";
                                                default = 0;
                                        };
                                        class Effect3 {
                                                name = "Arabski market #1";
                                                value = "pam_module_soundeffect_03";
                                                default = 0;
                                        };
                                        class Effect4 {
                                                name = "Arabski market #2";
                                                value = "pam_module_soundeffect_04";
                                                default = 0;
                                        };
                                        class Effect5 {
                                                name = "Arabski market #3";
                                                value = "pam_module_soundeffect_05";
                                                default = 0;
                                        };
                                        class Effect6 {
                                                name = "Arabski market #4";
                                                value = "pam_module_soundeffect_06";
                                                default = 0;
                                        };
                                        class Effect7 {
                                                name = "Arabskie modlitwy #1";
                                                value = "pam_module_soundeffect_07";
                                                default = 0;
                                        };
                                        class Effect8 {
                                                name = "Arabskie modlitwy #2";
                                                value = "pam_module_soundeffect_08";
                                                default = 0;
                                        };
                                        class Effect9 {
                                                name = "Arabskie modlitwy #3";
                                                value = "pam_module_soundeffect_09";
                                                default = 0;
                                        };
                                        class Effect10 {
                                                name = "Arabskie modlitwy #4";
                                                value = "pam_module_soundeffect_10";
                                                default = 0;
                                        };
                                        class Effect11 {
                                                name = "Arabskie modlitwy #5";
                                                value = "pam_module_soundeffect_11";
                                                default = 0;
                                        };
                                        class Effect12 {
                                                name = "Allahu akbar";
                                                value = "pam_module_soundeffect_12";
                                                default = 0;
                                        };
                                        class Effect13 {
                                                name = "Lecacy Jet";
                                                value = "pam_module_soundeffect_13";
                                                default = 0;
                                        };
                                        class Effect14 {
                                                name = "Radio chatter";
                                                value = "pam_module_soundeffect_14";
                                                default = 0;
                                        };
                                        class Effect17 {
                                                name = "Efekt las noc #1";
                                                value = "pam_module_soundeffect_17";
                                                default = 0;
                                        };
                                        class Effect18 {
                                                name = "Efekt las noc #2";
                                                value = "pam_module_soundeffect_18";
                                                default = 0;
                                        };
                                        class Effect15 {
                                                name = "Efekt las dzien #1";
                                                value = "pam_module_soundeffect_15";
                                                default = 0;
                                        };
                                        class Effect19 {
                                                name = "Efekt las dzien #2";
                                                value = "pam_module_soundeffect_19";
                                                default = 0;
                                        };
                                        class Effect20 {
                                                name = "Efekt las dzien #3";
                                                value = "pam_module_soundeffect_20";
                                                default = 0;
                                        };
                                        class Effect16 {
                                                name = "Efekt wietrzny las";
                                                value = "pam_module_soundeffect_16";
                                                default = 0;
                                        };
                };
            };
            class EffectLoop
            {
                displayName = "Powtarzaj";
                description = "Zapetlanie odtwarzanego dzwieku";
                typeName = "BOOL";
                class values
                {
                    class EffectLoopFalse {
                        name = "Nie";
                        value = 0;
                        default = 1;
                    };
                    class EffectLoopTrue {
                        name = "Tak";
                        value = 1;
                        default = 0;
                    };
                };
            };
        };
        class ModuleDescription: ModuleDescription
        {
            description = "Odtwarzanie dzwieków.";
            sync[] = {};
            position = 1;
        };
    };
    class PAM_Modules_Fog_Effect: A3C_Module
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "Efekt mgly";
        category = "a3cs_modules";
        function = "PAM_Modules_fnc_moduleFogEffect";
        isTriggerActivated = 1;
        isDisposable = 0;

        class Arguments {};
        class ModuleDescription: ModuleDescription
        {
            description = "Efekt mgly.";
            sync[] = {};
            position = 1;
        };
    };
    class PAM_Modules_Sand_Effect: A3C_Module
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "Efekt piasku";
        category = "a3cs_modules";
        function = "PAM_Modules_fnc_moduleSandEffect";
        isTriggerActivated = 1;
        isDisposable = 0;

        class Arguments {};
        class ModuleDescription: ModuleDescription
        {
            description = "Efekt piasku.";
            sync[] = {};
            position = 1;
        };
    };
    class PAM_Modules_Snow_Effect: A3C_Module
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "Efekt opadow sniegu";
        category = "a3cs_modules";
        function = "PAM_Modules_fnc_moduleSnowEffect";
        isTriggerActivated = 1;
        isDisposable = 0;

        class Arguments
        {
            class EffectType
            {
                displayName = "Sila opadow";
                description = "Sila opadow sniegu";
                typeName = "NUMBER";
                class values
                {
                    class Effect01 {
                        name = "Lekkie opady";
                        value = 1;
                        default = 1;
                    };
                    class Effect02 {
                        name = "Srednie opady";
                        value = 2;
                        default = 0;
                    };
                    class Effect03 {
                        name = "Ciezkie opady";
                        value = 3;
                        default = 0;
                    };
                };
            };
        };
        class ModuleDescription: ModuleDescription
        {
            description = "Efekt opadow sniegu.";
            sync[] = {};
            position = 1;
        };
    };
    class PAM_Modules_BreathFog_Effect: A3C_Module
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "Efekt pary z ust";
        category = "a3cs_modules";
        function = "PAM_Modules_fnc_moduleBreathFogEffect";
        isTriggerActivated = 1;
        isDisposable = 0;

        class Arguments {};
        class ModuleDescription: ModuleDescription
        {
            description = "Efekt pary z ust.";
            sync[] = {};
            position = 1;
        };
    };
};
