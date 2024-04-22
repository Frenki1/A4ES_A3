#include "script_component.hpp"
/*
 * Author: ACE team, SzwedzikPL
 * Handler for draw3D mission EH
 */

if (
  GVAR(displayInterrupt) ||
  {isNull ACE_player} ||
  {!alive ACE_player} ||
  {!(isNull (objectParent ace_player))} ||
  {EGVAR(ui,screenshotModeEnabled)}
) exitWith {
  0 call FUNC(clear2DNameTag);
};

private _targetsData = [[], DFUNC(getAreaTargets), ace_player, QGVAR(areaTargetsCache), 1] call ACEFUNC(common,cachedCall);
{_x call FUNC(draw3DNameTag)} forEach _targetsData;

if (freeLook) then {
0 call FUNC(clear2DNameTag);
} else {
  if (!GVAR(show2DNameTag) && {GVAR(show3DNameTag) != 2} && {GVAR(show3DNameTag) != 3}) exitWith {};

  private _targetData = [[], DFUNC(getCursorTarget), ace_player, QGVAR(cursorTargetCache), 0.25] call ACEFUNC(common,cachedCall);
  // Don't show cursor nametag while aiming
  if (isNil "_targetData" || {cameraView == "gunner"}) exitWith {
    0 call FUNC(clear2DNameTag);
  };

  private _target = _targetData # 0;

  if (GVAR(show2DNameTag) && {_target != GVAR(last2DCursorTarget)}) then {
    _targetData call FUNC(draw2DNameTag);
  };

  if (GVAR(show3DNameTag) == 2 || {GVAR(show3DNameTag) == 3}) then {
    _targetData call FUNC(draw3DNameTag);
  };
};
