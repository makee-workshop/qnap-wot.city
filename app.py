import time
import sys  
import websocket
import datetime

sys.path.insert(0, '/usr/lib/python2.7/bridge/') 
from bridgeclient import BridgeClient as bridgeclient

value = bridgeclient()

websocket.enableTrace(True)
ws = websocket.create_connection("ws://wot.city/object/57615d8a54242e1f2a000ee5/send")

while True:
	d0 = value.get("moisture")
	h0 = value.get("humidity")
	t0 = value.get("temperature")
	print "Moisture: " + d0
	print "Humidity: " + h0
	print "Temperature: " + t0
	
	t = time.time();
	date = datetime.datetime.fromtimestamp(t).strftime('%Y%m%d%H%M%S')
	
	vals = "{\"date\":\""+date+"\",\"temperature\":"+t0+",\"h\":"+h0+",\"soil\":"+d0+"}"
	
	time.sleep(1);
	ws.send(vals);
	print vals;