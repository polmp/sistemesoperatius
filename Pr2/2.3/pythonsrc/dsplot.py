#! /usr/bin/env python
# -*- coding: utf-8 -*-
"""
======================
MÓDUL DSPLOT
======================
"""
import datetime
import matplotlib.pyplot as grafica
from dataset import *
from datafetcher import *
from sensortranf import *

class DataSetPlot(object):
	def __init__(self):
		"""
		Mètode constructor
		"""
		self.__dataset=Dataset()
		
	def plot(self,d,s):
		"""
		Afegeix a la gràfica un conjunt de dades determinat per DataSet d i el sensor s.
		Si s’afegeix més d’un DataSet es representa cadascun d’un color diferent. 
		L’etiqueta de la llegenda corresponent a aquest DataSet és el nom del mateix.

		:param object d: Dataset a fer el plot.
		:param int s: Sensor del que volem fer el plot.
		"""
		grafica.plot(d.timevector(),d.valuevector(),label="Sensor "+str(s))
		grafica.ylabel("Temperatura",fontsize=18)
		grafica.xlabel("Temps",fontsize=18)
		grafica.legend()
				
	def show(self):
		"""
		Mostra la gràfica per la pantalla. El mètode no retorna fins que l’usuari tanca la finestra
		de la gràfica.

		"""
		grafica.show()