const { secret } = require('./secret.js');
var express = require('express');
var path = require('path');
var mysql = require('mysql');
var connection = mysql.createConnection(
    { host: "127.0.0.1", user: "root", password: "12345677654321", database: "challenge"});
var app = express();
app.use(express.json())
app.get('/', function (request, response) {response.sendFile(path.join(__dirname, 'index.html'));});
app.get('/login', function (request, response) {response.sendFile(path.join(__dirname, 'login.html'));});
app.post('/auth', function (request, response) {
    var loginData = request.body;
    loginData = Object.assign({ secret }, loginData); //oh, that's cool
    connection.query(
        "SELECT ? AS SECRET FROM users WHERE user = ? AND password = ?",
        [loginData.secret, loginData.user, loginData.password],
        (error, result) => {
            if (error) {return response.status(500).send("資料庫錯誤");}
            else if (result) {return response.status(200).send(result[0]["SECRET"]);}
            else {return response.status(401).send("你錯了呦～");}
        }
    );
});
var server = app.listen(process.env.PORT || 10022, function () {
    console.log(server.address().port);
});