from django.template import Template, Context
from django.http import HttpResponse
from ttgLib.TextToGcode import ttg  
from django.shortcuts import render
import serial

def probandoTemplate(request):
    if "entrada" in request.GET:
        entrada = request.GET["entrada"]
        gcode = ttg(entrada,1,0,"return",1).toGcode("M02 S500","M05 S0","G0","G1")
        ser = serial.Serial('/dev/ttyUSB0')
        print(ser.name)
        ser.write(b'hello')
        ser.close() 
        return render(request, 'index.html', {"codigo": gcode})     
    else:
        respuesta = "no datos"
    return render(request, 'index.html', {"respuesta": respuesta})