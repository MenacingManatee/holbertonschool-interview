#!/usr/bin/node

const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2],
  function (err, res, body) {
    if (err) { console.log(err); }
    const jsn = JSON.parse(body);
    const chars = jsn.characters;
    for (let i = 0; i < chars.length; i++) {
      request(chars[i], function (err, res, body) {
        if (err) { console.log(err); }
        const jsn2 = JSON.parse(body);
        console.log(jsn2.name);
      });
    }
  }
);
