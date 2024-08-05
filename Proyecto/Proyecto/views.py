from django.template import Template, Context
from django.http import HttpResponse
from ttgLib.TextToGcode import ttg  
from django.shortcuts import render
import serial

def probandoTemplate(request):
    if "entrada" in request.GET:
        entrada = request.GET["entrada"]
        gcode = 'G1 X50 Y80'#ttg(entrada,1,0,"return",1).toGcode("M02 S500","M05 S0","G0","G1")
        #SERIAL
        index = 0
        try:
            ser = serial.Serial('COM3', 115200)
            #while index < 3:
            ser.write(gcode.encode())
            respuesta_bytes = ser.read_until(b'\r\n')
            respuesta_string = respuesta_bytes.decode('utf-8')
            print("Codigo - " + str(index) + " : " + respuesta_string)
            ser.close()
        except Exception as e:
            print(f"Error: {e}")
        return render(request, 'index.html', {"codigo": gcode, "respuesta2": "exito"})
    else:
        respuesta = "no datos"
    return render(request, 'index.html', {"respuesta": respuesta})