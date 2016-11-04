#! /usr/bin/env python
# -*- coding: utf-8 -*-
"""
=========================
MÒDUL SUPERVISOR
=========================


Classe
--------
"""
from estat import*
from node import *
from triport import*

class Supervisor(object):

	def __init__(self):
		"""
		Mètode constructor
		"""
		self.__nodes=[]
		self.__triport=[]
		self.__changed=False

	def add_node(self,n):
		"""
		Afegeix un node a la llista a supervisar

		"""
		try:
			if n in self.__nodes:
				raise Exception()
		except:
			print "El node ja esta llistat!"
		else:
			self.__nodes.append(n)
			n.set_supervisor(self)

	def add_triport(self,t):
		"""
		Afegeix un triport a la llista a supervisar
		"""
		try:
			if t in self.__triport:
				raise Exception()
		except:
			print "El triport ja esta llistat!"
		else:
			self.__triport.append(t)

	def notify_change(self):
		"""
		Notifica un canvi d'estat d'un node.
		"""
		if not self.__changed:
			self.__changed=True

	def run(self,log=False):
		"""
		Executa la simulació del supervisor
		"""
		for triport in self.__triport:
			triport.tick()					
			if log==True:
				print "Tick -> "+ str(triport)
