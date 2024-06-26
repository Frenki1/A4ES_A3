#include "script_component.hpp"

// Exit if no interface or it's main menu intro
if (!hasInterface || EGVAR(common,isMainMenu)) exitWith {};

if (GVAR(disabledInMission)) then {
  systemChat LLSTRING(Chat_RadarDisabledByMission);
};

["CBA_settingsInitialized", {
  LOG("CBA_settingsInitialized event");
  GVAR(settingsInitialized) = true;
  call FUNC(handleSettingsChanged);
}] call CBA_fnc_addEventHandler;

["unit", {
  LOG_1("unit event: %1",str _this);
  // Hide current squad for now
  GVAR(showCurrentSquad) = false;
  // Trigger squads changed event on unit change & update UI
  [{
    [QEGVAR(squads,squadChanged), []] call CBA_fnc_localEvent;
  }, []] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addPlayerEventHandler;

["vehicle", {
  LOG_1("vehicle event: %1",str _this);
  false call FUNC(updateUI);
}] call CBA_fnc_addPlayerEventHandler;

[QGVAR(jamRadar), {
  LOG_1("jamRadar event: %1",str _this);
  // Update UI
  true call FUNC(updateUI);
}] call CBA_fnc_addEventHandler;

[QEGVAR(squads,squadChanged), {
  LOG_1("squadChanged event: %1",str _this);

  GVAR(currentSquad) = ace_player call EFUNC(squads,getUnitSquad);

  if (isNull GVAR(currentSquad)) then {
    GVAR(currentSquadUnits) = [];
    GVAR(showCurrentSquad) = false;
  } else {
    private _squadUnits = GVAR(currentSquad) call EFUNC(squads,getSquadUnits);

    // Sort squad units by rank descending
    GVAR(currentSquadUnits) = [_squadUnits, 0] call EFUNC(nametags,sortUnitsByRank);
    GVAR(showCurrentSquad) = (count GVAR(currentSquadUnits)) >= 2;
  };

  // Update UI
  true call FUNC(updateUI);
}] call CBA_fnc_addEventHandler;

[QEGVAR(radio,onSpeak), {
  LOG_2("%1 event: %2",QEGVAR(radio,onSpeak),str _this);
  (_this # 0) call FUNC(handleUnitStatusUpdate);
}] call CBA_fnc_addEventHandler;

[QEGVAR(nametags,unitColorChanged), {
  LOG_1("unitColorChanged event: %1",str _this);
  _this call FUNC(handleUnitStatusUpdate);
}] call CBA_fnc_addEventHandler;

["ace_unconscious", {
  params ["_unit"];

  LOG_1("ace_unconscious event: %1",str _this);
  _this call FUNC(handleUnitStatusUpdate);

  // Update ui if player unconsciousness status changes
  if (_unit isEqualTo ace_player) then {
    false call FUNC(updateUI);
  };
}] call CBA_fnc_addEventHandler;

// ACE Finger
["ace_finger_fingered", {
  LOG_1("ace_finger_fingered event: %1",str _this);
  _this call FUNC(handleFinger);
}] call CBA_fnc_addEventHandler;

// UI screenshot mode
[QEGVAR(ui,screenshotModeToggled), {
  LOG_2("%1 event: %2",QEGVAR(ui,screenshotModeToggled),str _this);
  false call FUNC(updateUI);
}] call CBA_fnc_addEventHandler;
