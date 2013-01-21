
/*
 * This file lists all timers used by the AI.
 * 
 */

(function(_global) {
////////////////////////////////////////////////////////////////////////////////////////////

// slightly shift all timers so that not to get too many of them on the same game frame,
// especially when multiple AI instances are running
function rnd() {
	return random(201) - 100;
}

_global.setTimers = function() {
	setTimer("spendMoney", 1000 + 2 * rnd());
	setTimer("checkAttack", 3000 + 4 * rnd());
	setTimer("checkVtols", 3000 + 4 * rnd());
	setTimer("updateAllAdaptInfo", 20000 + 10 * rnd());
}

////////////////////////////////////////////////////////////////////////////////////////////
})(this);