
/*
 * This file contain functions for manipulating stats defined by rulesets.
 * 
 */

(function(_global) {
////////////////////////////////////////////////////////////////////////////////////////////

_global.isHoverPropulsion = function(str) {
	for (var i = 0; i < propulsionStats.hover.length; ++i)
		if (str === propulsionStats.hover[i].stat)
			return true;
	return false;
}

_global.isVtolPropulsion = function(str) {
	for (var i = 0; i < propulsionStats.vtol.length; ++i)
		if (str === propulsionStats.vtol[i].stat)
			return true;
	return false;
}

_global.iHaveHover = function() {
	const COMP_PROPULSION=3; 
	for (var i = 0; i < propulsionStats.hover.length; ++i)
		if (componentAvailable(COMP_PROPULSION, propulsionStats.hover[i].stat))
			return true;
	return false;
}

_global.iHaveVtol = function() {
	const COMP_PROPULSION=3; 
	for (var i = 0; i < propulsionStats.vtol.length; ++i)
		if (componentAvailable(COMP_PROPULSION, propulsionStats.vtol[i].stat))
			return true;
	return false;
}

_global.enumStructList = function(list, player) {
	if (typeof(player) === "undefined")
		player = me;
	var ret = [];
	for (var i = 0; i < list.length; ++i)
		ret = ret.concat(enumStruct(player, list[i]));
	return ret;
}

_global.countStructList = function(list, player) {
	if (typeof(player) === "undefined")
		player = me;
	var ret = 0;
	for (var i = 0; i < list.length; ++i) 
		ret += countStruct(list[i], player);
	return ret;
}

_global.structListLimit = function(list) {
	var ret = 0;
	for (var i = 0; i < list.length; ++i)
		ret += getStructureLimit(list[i]);
	return ret;
}

//
// here be functions for querying out research paths 
//

function statsToResList(path) {
	var ret = [];
	for (var i = 0; i < path.length; ++i) 
		ret.push(path[i].res);
	return ret;
}

_global.bodyStatsToResList = function(path) {
	return statsToResList(path);
}

_global.propulsionStatsToResList = function(path) {
	return statsToResList(path);
}

_global.weaponStatsToResList = function(path, aspect) {
	var ret = [];
	if (typeof(aspect) === "undefined" || aspect === RESASPECTS.WEAPONS) {
		for (var i = 0; i < path.weapons.length; ++i)
			ret.push(path.weapons[i].res);
		for (var i = 0; i < path.vtols.length; ++i)
			ret.push(path.vtols[i].res);
		for (var i = 0; i < path.templates.length; ++i)
			ret.push(path.templates[i].res);
	}
	if (typeof(aspect) === "undefined" || aspect === RESASPECTS.DEFENSES) {
		for (var i = 0; i < path.defenses.length; ++i)
			ret.push(path.defenses[i].res);
	}
	if (typeof(aspect) === "undefined" || aspect === RESASPECTS.EXTRAS)
		ret = ret.concat(path.extras);
	return ret;
}

//
// here be functions for querying out component lists
//

_global.bodyStatsToComponents = function(stats, usage, weight) {
	var ret = [];
	for (var i = 0; i < stats.length; ++i)
		if (typeof(weight) === "undefined" || stats[i].weight === weight)
			if (stats[i].usage & usage)
				ret.push(stats[i].stat);
	ret.reverse();
	return ret;
}

_global.propulsionStatsToComponents = function(stats) {
	var ret = [];
	for (var i = 0; i < stats.length; ++i)
		ret.push(stats[i].stat);
	ret.reverse();
	return ret;
}

_global.weaponStatsToComponents = function(stats, weight) {
	var ret = [];
	for (var i = 0; i < stats.weapons.length; ++i) {
		if (typeof(weight) === "undefined" || stats.weapons[i].weight === weight)
			ret.push(stats.weapons[i].stat);
	}
	ret.reverse();
	return ret;
}

_global.weaponStatsToVtolComponents = function(stats, weight) {
	var ret = [];
	for (var i = 0; i < stats.vtols.length; ++i) {
		if (typeof(weight) === "undefined" || stats.vtols[i].weight === weight)
			ret.push(stats.vtols[i].stat);
	}
	ret.reverse();
	return ret;
}

//
// here be functions for querying out defensive structures
//

_global.weaponStatsToDefenses = function(stats, defrole) {
	var ret = [];
	for (var i = 0; i < stats.defenses.length; ++i)
		if (typeof(defrole) === "undefined" || stats.defenses[i].defrole === defrole)
			ret.push(stats.defenses[i].stat);
	// reverse not needed here
	return ret;
}


////////////////////////////////////////////////////////////////////////////////////////////
})(this);