#!/usr/bin/env node

// Math.node REPL
// ==============
// This is a simplistic REPL which exposes the math.node object to 
// the user for debugging and testing purposes.
var repl = require('repl');
var math = require('../build/Release/math');

console.log('Starting Math.node REPL...');
console.log('To exit, press <Cmd+D>');

// Start the REPL.
var r = repl.start({
	prompt: '> '
});

// Expose the math and instance objects to the REPL.
r.context.math = math;

// Print a message to the console on exit.
r.on('exit', function () {
	console.log('Exit math.node REPL.');
});