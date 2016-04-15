page = require('webpage').create()
page.open('https://www.taobao.com', function(status) {
    if (status !== 'success') {
        console.log('error while opening webpage');
    } else {
        var cookies = page.cookies;
        for (var i in cookies) {
            console.log(cookies[i].name + ' : ' + cookies[i].value);
        }
    }
    phantom.exit();
});
