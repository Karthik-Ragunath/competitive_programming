import sys
import os
import heapq

class Max_Heap(obj):
	def __init__(self, val):
		self.val = val
	def __lt__(self, other):
		return self.val > self.other
	def __eq__(self, other):
		return self.val == other.val
	def __str__(self):
		return str(self.val)

import heapq

max_heap = []
heapq.heapify(max_heap, Max_Heap(3))

'''
-- Data to send: {'service': u'nightwing', u'clients': [{u'ingestion_queue_name': u'1325_ideas2it_eskrima', u'widgets': [u'tag'], u'region_code': u'us-east-1', u'name': u'ideas2it', u'id': 1325}], u'sources': [], 'mode': u'client_create', u'action': u'add', u'api_key': u'a460c0b75756b86cc6f0256b8bde24ab12ff60c8'}

{'action': 'add',
 'api_key': 'a460c0b75756b86cc6f0256b8bde24ab12ff60c8',
 'clients': [{'id': 1325,
   'ingestion_queue_name': '1325_ideas2it_eskrima',
   'name': 'ideas2it',
   'region_code': 'us-east-1',
   'widgets': ['tag']}],
 'mode': 'client_create',
 'service': 'nightwing',
 'sources': []}
 '''