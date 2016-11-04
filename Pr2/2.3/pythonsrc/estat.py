#! /usr/bin/env python
# -*- coding: utf-8 -*-
"""
=====================
MÒDUL ESTAT
=====================

Classe
--------
"""
class Estat(object):
	"""
	>>> e1=Estat(1)
	>>> e2=Estat(0)
	>>> e3=Estat()
	>>> e3.undef()
	True
	>>> e1&e2
	0
	>>> e1|e2
	1
	>>> ~e1
	0
	>>> e1==e2
	0
	>>> print e1
	Alt(1)

	"""
	def __init__(self,e=-1):
		"""
		Métode init
		"""
		self.__e=e

	def undef(self):
		"""
		Comprova si l'estat es indefinit

		:return: True si l'estat es Indefinit.
		"""

		if self.__e==-1:
			return True
		else:
			return False
	
	def __nonzero__(self):
		"""
		True si self esta ben definit
		"""

		if self.undef():
			return False
		else:
			return True

	def __and__(self,other):
		"""
		Porta lògica and
		"""

		if self.undef() and other.undef() or self.undef() and other.__e==1 or self.__e==1 and other.undef():
			return -1

		elif self.undef() and other.__e==0 or self.__e==0 and other.undef():
			return 0

		elif self.__e==1 and other.__e==1:
			return 1

		else:
			return 0


	def __or__(self,other):
		"""
		Porta lògica or
		"""
	
		if self.undef() and other.undef() or self.undef() and other.__e==0 or self.__e==0 and other.undef():
			return -1

		elif self.undef() and other.__e==1 or self.__e==1 and other.undef():
			return 1

		elif self.__e==1 or other.__e==1:
			return 1

		else:
			return 0

	def __invert__(self):
		"""
		Porta lògica not
		"""

		if self.undef():
			return -1
		else:
			if self.__e==0:
				return 1
			else:
				return 0

	def __eq__(self,other):
		"""
		Métode equal
		"""
		if self.__e == other.__e:
			return True
		else:
			return False

	def __repr__(self):
		"""
		Métode repr
		"""
		if self.__e==0:
			return "Baix(0)"
		elif self.__e==1:
			return "Alt(1)"
		else:
			return "Indefinit(-1)"