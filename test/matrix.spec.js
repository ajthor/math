var chai = require('chai'),
	expect = chai.expect;

require('mocha');

var exported = require('../build/Release/math').Matrix;

describe('matrixJs function', function () {

	it('should have enumerable properties', function () {
		expect(function () {

			var instance = new exported(3, 3);
			console.log(instance + '\n');

			for (var i in instance) {
				console.log(i, instance[i]);
			}

		}).to.not.throw(Error);
	});
	it('should have enumerable properties', function () {
		expect(function () {

			var instance = new exported([3, 3]);
			console.log(instance + '\n');

			for (var i in instance) {
				console.log(i, instance[i]);
			}
			
		}).to.throw(Error);
	});
	
	it('should load without throwing');
	it('should be an object Matrix');
	it('should have some functions');
	it('should have some properties');
	
	describe('Matrix prototype', function () {
		
		it('should have a function \'add\'');
		it('should add two matrices together');
		it('should have a function \'sub\'');
		it('should subtract one matrix from the other');
		
		it('should have a function \'mult\''); // Dot (Scalar)
		it('should multiply two matrices together');
		it('should accept both a scalar and a matrix');
		
		it('should have a function \'prod\''); // Cross
		it('should find the product of two matrices');
		it('should accept both a vector and a matrix');
		
	});
	
});