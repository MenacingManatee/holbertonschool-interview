#!/usr/bin/node

const request = require('request');

function asyncGetCharacter(url) {
	return new Promise(function (resolve, reject) {
		request(url, function (err, res, body) {
			if (!err && res.statusCode == 200) {
				resolve(body);
			} else {
				reject(err);
			}
		});
	});
}
async function doRequest() {
	request('https://swapi-api.hbtn.io/api/films/' + process.argv[2],
		function (err, res, body) {
			if (err) { console.log(err); }
			const jsn = JSON.parse(body);
			const chars = jsn.characters;
			for (let i = 0; i < chars.length; i++) {
				let res = await asyncGetCharacter(chars[i]);
				console.log(res.name);
			}
		}
	);
}

doRequest();
