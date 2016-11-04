#! /usr/bin/env python
# -*- coding: utf-8 -*-
#-*-coding:utf-8-*-
"""
==========================
MÓDUL SENSORTRANSF
==========================
"""
	
from dataset import *
import sys

class Ea(Exception):
	esunaprova

class SensorError(Exception):
    pass

def normalize(d,s=0):
    """
    La funció normalize(d,s=0) aplica la transformació escaient per al sensor s sobre el DataSet d. 
    Una vegada aplicada els valors de l’objecte són temperatures en graus Celsius.

    :param object d: Dataset a normalitzar.
    :param int s: Sensor a normalitzar.

    """


    dades={0:[3.1418,5.6500,0.24],1:[0.0000,1.0000,1.37],2:[2.1850,5.3972,0.95],3:[2.1313,5.2959,0.42],4:[10.5953,16.8243,0.29],5:[10.5842,16.5574,0.79]}
    try:
        if s not in dades.keys():
            raise SensorError()
    except SensorError:
        print "No existeix el sensor!"
        sys.exit(0)
    else:
    	sensor=dades[s]
    	op1=100*((3.3040/1024.0)/sensor[1])
    	op2=((100*sensor[0])/sensor[1])-50+sensor[2]
    	d.transform(a=op1,b=op2)

class Clase2(Object):
    prova



	
	
