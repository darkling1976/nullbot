
/*
 * This file includes routines and algorithms completely unrelated to Warzone 2100.
 * 
 */

(function(_global) {
////////////////////////////////////////////////////////////////////////////////////////////

_global.random = function(max) {
	if (max <= 0)
		return undefined;
	return Math.floor(Math.random() * max);
}

_global.randomID = function() {
	return random(1000000) + "_" + random(1000000) + "_"+random(1000000) + "_"+random(1000000) + "_"+random(1000000) + "_"+random(1000000);
}

// some useful array functions
Array.prototype.random = function() {
	if (this.length > 0)
		return this[random(this.length)];
}

Array.prototype.last = function() {
	if (this.length > 0)
		return this[this.length - 1];
}

Array.prototype.filterProperty = function(property, value) {
	return this.filter(function(element) {
		return element[property] === value;
	});
}

// cluster analysis happens here
_global.naiveFindClusters = function(list, size) {
	var ret = { clusters: [], xav: [], yav: [], maxIdx: 0, maxCount: 0 };
	for (var i = list.length - 1; i >= 0; --i) {
		var x = list[i].x, y = list[i].y;
		var found = false;
		for (var j = 0; j < ret.clusters.length; ++j) {
			if (distBetweenTwoPoints(ret.xav[j], ret.yav[j], x, y) < size) {
				var n = ret.clusters[j].length;
				ret.clusters[j][n] = list[i];
				ret.xav[j] = (n * ret.xav[j] + x) / (n + 1);
				ret.yav[j] = (n * ret.yav[j] + y) / (n + 1);
				if (ret.clusters[j].length > ret.maxCount) {
					ret.maxIdx = j;
					ret.maxCount = ret.clusters[j].length;
				}
				found = true;
				break;
			}
		}
		if (!found) {
			var n = ret.clusters.length;
			ret.clusters[n] = [list[i]];
			ret.xav[n] = x;
			ret.yav[n] = y;
			if (1 > ret.maxCount) {
				ret.maxIdx = n;
				ret.maxCount = 1
			}
		}
	}
	return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////
})(this);