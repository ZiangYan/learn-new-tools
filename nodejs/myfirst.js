var http = require('http');
var url = require('url');
var fs = require('fs');
var events = require('events');

var eventEmitter = new events.EventEmitter();
var myEventHandler = function () {
  console.log('I hear a scream!');
}

eventEmitter.on('scream', myEventHandler);

eventEmitter.emit('scream');
