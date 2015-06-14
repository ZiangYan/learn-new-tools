var fs = require('fs');
var path = require('path');
module.exports = function(argpath, argext, argcallback) {
    fs.readdir(argpath, function (err, list) {
        if (err)
	    return argcallback(err);
        list = list.filter(function (file) {
            return path.extname(file) === '.' + argext;
        });
	argcallback(null, list);
    });
}; 
