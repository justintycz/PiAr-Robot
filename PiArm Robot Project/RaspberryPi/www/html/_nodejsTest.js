
var serialport = require("serialport");

console.log("Hi");

var port = new serialport('/dev/ttyACM0', {
	baudRate:9600,
	//parser:serialport.parsers.readline('\n')
});

const Readline = serialport.parsers.readline;
const parser = new Readline();
port.pipe(parser);

port.on('open', onPortOpen);
parser.on('data', onData);
port.on('close', onClose);
port.on('error', onError);
port.write('Hi mom!');


function onPortOpen(data) {
	document.write("<p>Port Open</p>");
}
function onData(data) {
	document.write("<p>Data recieved: " + data + "</p>");
}
function onClose() {
	document.write("<p>Port Closed</p>");
}
function onError() {
	document.write("<p>Error with serial coms</p>");
}
