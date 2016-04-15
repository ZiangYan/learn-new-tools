var page = require('webpage').create();
var system = require('system');

if (system.args.length === 1) {
    console.log('Usage: load_speed.js <URL>');
    phantom.exit();
}

var t = Date.now()
var address = system.args[1]
page.open(address, function(status) {
    if (status !== 'success') {
        console.log('URL ' + address + ' failed to load');
    } else {
        t = Date.now() - t;
        console.log('loading time: ' + t + 'msec');
    }
    phantom.exit();
});
