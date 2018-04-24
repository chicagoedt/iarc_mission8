/* Open playground, opens up new client for test drone instance */
var arDrone = require('ar-drone');
var express = require('express');
var client  = arDrone.createClient();
var app = express();
var path = require('path');
client.createRepl();
