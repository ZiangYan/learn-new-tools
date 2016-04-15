var page = require('webpage').create();
page.open('https://www.taobao.com', function(status) {
    console.log('status: ' + status);
    if (status == 'success') {
        page.render('example.png');
    }
    phantom.exit();
});
