var chai = require('chai'),
	expect = chai.expect;

require('mocha');

var exported = require('../build/Release/math').Matrix;

describe('matrixJs function', function () {

	it('should have enumerable properties', function () {
		var instance = new exported([3, 3]);
		console.log(instance + '\n');

		for (var i in instance) {
			console.log(i, instance[i]);
		}
	});

	it('should not throw if passed an array', function () {
		expect(function () {
			var instance = new exported([3, 3]);
		}).to.not.throw(Error);
	});

	it('should not throw if passed a 2-D array', function () {
		expect(function () {
			var instance = new exported([[3, 4], [2, 1]]);
		}).to.not.throw(Error);
	});
	
	it('should load without throwing');
	it('should be an object Matrix');
	it('should have some functions');
	it('should have some properties');
	
	describe('Matrix prototype', function () {

		var matrixProto = exported.prototype;

		describe('get', function () {

			it('should have a function \'get\'', function () {
				expect(matrixProto.get).to.exist;
			});

			it('should return a row if passed only one index', function () {
				var instance = new exported([3, 3]);
				var result = instance.get(1);

				expect(result).to.be.an('Array');
			});

			it('should return one value if passed two indices', function () {
				var instance = new exported([3, 3]);
				var result = instance.get(1, 1);

				expect(result).to.be.a('Number');
				expect(result).to.equal(0);
			});

			it('should set a value in an array', function() {
				var instance = new exported([[1, 1], [1, 1]]);
				instance.set([1, 1], 3);

				var result = instance.get([1, 1]);

				expect(result).to.equal(3);
			});
		});
		
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