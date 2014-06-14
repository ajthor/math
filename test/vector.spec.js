var chai = require('chai'),
	expect = chai.expect;

require('mocha');

var exported = require('../build/Release/math').Vector;

describe('vectorJs function', function () {
	
	it('should load without throwing');
	it('should be an object Vector');
	it('should have some functions');
	it('should have some properties');
	
	describe('Vector prototype', function () {
		
		it('should have a function \'add\'');
		it('should add two vectors together');
		it('should have a function \'sub\'');
		it('should subtract one vector from the other');
		
		it('should have a function \'mult\''); // Dot (Scalar)
		it('should multiply two vectors together');
		it('should accept both a scalar and a vector');
		
		it('should have a function \'prod\''); // Cross (Vector)
		it('should find the vector product of two vectors');
		it('should accept both a vector and a matrix');
		
	});
	
});