#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, function (error, response, body) {
  if (error) {
    console.error(error);
  }
  const data = JSON.parse(body).characters;
  data.forEach(lurl => {
    request(lurl, (error, response, body) => {
      if (error) {
        console.error(error);
      }
      console.log(JSON.parse(body).name);
    });
  });
});
