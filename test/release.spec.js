var chai = require('chai'),
	expect = chai.expect;

describe('release module', function() {

	var exported;

	it('should load without errors', function() {
		expect(function() {
			return require('../build/Release/math.node');
		}).to.not.throw(Error);
	});

	it('should have an object \'Vector\'', function() {
		var m = require('../build/Release/math.node');
		expect(m.Vector).to.exist;
	});

	it('should have an object \'Matrix\'', function() {
		var m = require('../build/Release/math.node');
		expect(m.Matrix).to.exist;
	});

});