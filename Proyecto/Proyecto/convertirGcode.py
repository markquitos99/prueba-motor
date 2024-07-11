from ttgLib.TextToGcode import ttg

gcode = ttg("Text to Gcode", 1, 0, "return", 1).toGcode("M02 S500", "M05 S0", "G0", "G1")
print(gcode)