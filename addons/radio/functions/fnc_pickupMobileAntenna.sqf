#include "script_component.hpp"
/*
 * Author: SzwedzikPL
 * Pickup mobile antenna
 */

params ["_target", "_player"];
TRACE_2("pickupMobileAntenna",_target,_player);

if !(alive _target) exitWith {};

if (!([_player, "tfw_rf3080Item"] call CBA_fnc_canAddItem)) exitWith {
  [LSTRING(NoPlaceInInventory)] call ACEFUNC(common,displayTextStructured);
};

_player playActionNow "PutDown";

[{
  params ["_target", "_player"];

  // Check is antenna is still there
  if (isNull _target) exitWith {};

  // Check is there still room in inventory
  if (!([_player, "tfw_rf3080Item"] call CBA_fnc_canAddItem)) exitWith {
    [LSTRING(NoPlaceInInventory)] call ACEFUNC(common,displayTextStructured);
  };

  // Pickup
  deleteVehicle _target;
  _player addItem "tfw_rf3080Item";

  // A3CSServer event
  ["a3csserver_events_userAntennaRem", [_player]] call CBA_fnc_serverEvent;
}, [_target, _player], 1] call CBA_fnc_waitAndExecute;
