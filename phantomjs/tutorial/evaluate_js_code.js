page = require('webpage').create()
page.onConsoleMessage = function(message) {
    console.log('title is ' + message);
};
page.open('https://www.taobao.com', function(status) {
    var title = page.evaluate(function() {
        console.log(document.title);
    });
    phantom.exit();
});
