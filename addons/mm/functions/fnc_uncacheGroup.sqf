/*
 * Author: SzwedzikPL
 * Uncache group
 */
#include "script_component.hpp"

if(!isServer) exitWith {};
params ["_group"];

private _groupUnits = units _group;
private _groupLeader = leader _group;
private _leaderIsCached = _groupLeader getVariable [QGVAR(cached), false];
private _uncachedUnitCount = 0;

{
    private _unit = _x;
    private _unitCached = _unit getVariable [QGVAR(cached), false];
    if(_unitCached) then {
        //uncache unit
        _unit enableSimulationGlobal true;
        _unit hideObjectGlobal false;
        _unit setDamage (damage _unit); //trigger unit
        _unit setVariable [QGVAR(cached), false];
        _uncachedUnitCount = _uncachedUnitCount + 1;
        if(_leaderIsCached) then {
            //leader was cached so load cache data
            private _cacheData = _unit getVariable [QGVAR(cacheData), []];
            _cacheData params [["_positionATL", [], [[]]], ["_dir", 0, [0]]];
            _unit setPosATL _positionATL;
            _unit setDir _dir;
        } else {
            //leader was not cached so move to leader
            private _position = (vehicle _groupLeader) getPos [0.5 + (random 3), random 360];
            private _dir = getDir (vehicle _groupLeader);
            _unit setPos _position;
            _unit setDir _dir;
        };
    };
    nil
} count _groupUnits;

_uncachedUnitCount
