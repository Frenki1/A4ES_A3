#include "script_component.hpp"

ADDON = false;

GVAR(useFlexiMenu) = true;

#include "XEH_PREP.hpp"

GVAR(fleximenuTarget) = objNull;
GVAR(fleximenuType) = -1;
GVAR(fleximenuActions) = [];
GVAR(fleximenuMenuPath) = [];
GVAR(fleximenuFirstRun) = false;
GVAR(fleximenuOptionsData) = [];
GVAR(fleximenuInteractionOptionsData) = [];

GVAR(fleximenuDef) = ["player", [], -100, [QUOTE(PATHTOF(flexiMenu.sqf)), "main"]];

ADDON = true;
