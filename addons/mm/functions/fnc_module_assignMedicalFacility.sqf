#include "script_component.hpp"

params ["_logic"];

if (isNull _logic) exitWith {};
if(!isServer) exitWith {};

{_x setVariable ["ace_medical_isMedicalFacility", true, true];} foreach synchronizedObjects _logic;
