#include "script_component.hpp"
/*
 * Author: SzwedzikPL
 * Joins unit to given squad
 */

params ["_unit", "_target"];

// Exit if not server or null squad
if (!isServer) exitWith {};

private _currentSquad = _unit call FUNC(getUnitSquad);
private _changedSquads = [];

// Update current unit squad
if !(isNull _currentSquad) then {
  // Add squad to changed squads if squad was not deleted after unit leaving
  if !([_unit, false] call FUNC(leaveSquad)) then {
    _changedSquads pushBack _currentSquad;
  };
};

private _newSquad = _unit call FUNC(getUnitSquad);
private _newSquadUnits = _newSquad getVariable ["units", []];

// Create new squad if target has no squad
if (isNull _newSquad) then {
  _newSquad = call FUNC(createSquad);
  _newSquad setVariable ["leader", _target, true];
  _newSquadUnits = [_target];
};

// Set unit squad
_unit setVariable [QGVAR(squad), _newSquad, true];

// Update squad units
_newSquadUnits pushback _unit;
_newSquad setVariable ["units", _newSquadUnits, true];
_changedSquads pushBack _newSquad;

LOG_3("Unit %1 joined squad of %2 (changed squads: %3)",str _unit,str _target,str _changedSquads);

// Send event for clients
_changedSquads call FUNC(triggerSquadChanged);