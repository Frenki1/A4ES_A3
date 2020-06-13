mapOrientation = 1;
drawObjects = 0;
drawLocations = 0;
showMarkers = 0;
showCountourInterval = 0;
showTacticalPing = 0;
maxSatelliteAlpha = 0;
alphaFadeStartScale = 0;
alphaFadeEndScale = 0;
colorBackground[] = {0,0,0,0};
colorSea[] = {0,0,0,0};
colorForest[] = {0,0,0,0};
colorForestBorder[] ={0,0,0,0};
colorRocks[] = {0,0,0,0};
colorRocksBorder[] = {0,0,0,0};
colorLevels[] = {0,0,0,0};
colorMainCountlines[] = {0,0,0,0};
colorCountlines[] = {0,0,0,0};
colorMainCountlinesWater[] = {0,0,0,0};
colorCountlinesWater[] = {0,0,0,0};
colorPowerLines[] = {0,0,0,0};
colorRailWay[] = {0,0,0,0};
colorNames[] = {0,0,0,0};
colorInactive[] = {0,0,0,0};
colorText[] = {0,0,0,0};
colorOutside[] = {0,0,0,0};
colorTracks[] = {0,0,0,0};
colorTracksFill[] = {0,0,0,0};
colorRoads[] = {0,0,0,0};
colorRoadsFill[] = {0,0,0,0};
colorMainRoads[] = {0,0,0,0};
colorMainRoadsFill[] = {0,0,0,0};
colorGrid[] = {0,0,0,0};
colorGridMap[] = {0,0,0,0};
sizeExLabel = 0;
sizeExGrid = 0;
sizeExUnits = 0;
sizeExNames = 0;
sizeExInfo = 0;
sizeExLevel = 0;

HIDE_MAP_MARKER(ActiveMarker);
HIDE_MAP_MARKER(Bunker);
HIDE_MAP_MARKER(Bush);
HIDE_MAP_MARKER(busstop);
HIDE_MAP_MARKER(Chapel);
HIDE_MAP_MARKER(church);
HIDE_MAP_MARKER(Command);
HIDE_MAP_MARKER(Cross);
HIDE_MAP_MARKER(CustomMark);
HIDE_MAP_MARKER(Fortress);
HIDE_MAP_MARKER(Fountain);
HIDE_MAP_MARKER(fuelstation);
HIDE_MAP_MARKER(hospital);

class Legend {
    color[] = {0,0,0,0};
    colorBackground[] = {0,0,0,0};
    font = "RobotoCondensed";
    sizeEx = 0;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
};

HIDE_MAP_MARKER(lighthouse);

class LineMarker {
    lineDistanceMin = 0;
    lineLengthMin = 0;
    lineWidthThick = 0;
    lineWidthThin = 0;
    textureComboBoxColor = "#(argb,8,8,3)color(0,0,0,0)";
};

HIDE_MAP_MARKER(power);
HIDE_MAP_MARKER(powersolar);
HIDE_MAP_MARKER(powerwave);
HIDE_MAP_MARKER(powerwind);
HIDE_MAP_MARKER(quay);
HIDE_MAP_MARKER(Rock);
HIDE_MAP_MARKER(Ruin);
HIDE_MAP_MARKER(shipwreck);
HIDE_MAP_MARKER(SmallTree);
HIDE_MAP_MARKER(Stack);

class Task {
    coefMax = 0;
    coefMin = 0;
    color[] = {0,0,0,0};
    colorCanceled[] = {0,0,0,0};
    colorCreated[] = {0,0,0,0};
    colorDone[] = {0,0,0,0};
    colorFailed[] = {0,0,0,0};
    icon = "#(argb,8,8,3)color(0,0,0,0)";
    iconCanceled = "#(argb,8,8,3)color(0,0,0,0)";
    iconCreated = "#(argb,8,8,3)color(0,0,0,0)";
    iconDone = "#(argb,8,8,3)color(0,0,0,0)";
    iconFailed = "#(argb,8,8,3)color(0,0,0,0)";
    importance = 0;
    size = 0;
    taskAssigned = "#(argb,8,8,3)color(0,0,0,0)";
    taskCanceled = "#(argb,8,8,3)color(0,0,0,0)";
    taskCreated = "#(argb,8,8,3)color(0,0,0,0)";
    taskFailed = "#(argb,8,8,3)color(0,0,0,0)";
    taskNone = "#(argb,8,8,3)color(0,0,0,0)";
    taskSucceeded = "#(argb,8,8,3)color(0,0,0,0)";
};

HIDE_MAP_MARKER(Tourism);
HIDE_MAP_MARKER(transmitter);
HIDE_MAP_MARKER(Tree);
HIDE_MAP_MARKER(ViewTower);
HIDE_MAP_MARKER(watertower);
HIDE_MAP_MARKER(Waypoint);
HIDE_MAP_MARKER(WaypointCompleted);
