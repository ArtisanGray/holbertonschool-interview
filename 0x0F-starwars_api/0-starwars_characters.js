#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, async function (error, response, body) {
  if (error) { console.error(error); }
  const data = await JSON.parse(body).characters;
  for (const charac of data) {
    const name = await new Promise((resolve, reject) => {
      request(charac, (error, response, body) => {
        if (error) { console.error(error); }
        resolve(JSON.parse(body).name);
      });
    });
    console.log(name);
  }
});
