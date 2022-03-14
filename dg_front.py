from dg import *
from manage import *
import pywebio.output as pwo
from pywebio.input import *
import numpy as np
import pandas as pd

def display(matrix):
    return np.matrix(matrix)
    
def check_ans(matrix):
    return dungeon_game(matrix)
def user_f():
    pwo.clear()
    arr = input_group("Insert matrix infomation",[
    input('Row count', name='m',type=NUMBER),
    input('Column count', name='n',type=NUMBER),])
    matrix=[]
    for i in range(int(arr['m'])):          # A for loop for row entries
      a=[]
      for j in range(int(arr['n'])):      # A for loop for column entries
         a.append(int(input('Enter element Row wise:')))
      matrix.append(a)
    pwo.put_markdown(""" # Dungeon Matrix genrated by Dungeon Master: """)
    pwo.put_table((display(matrix).tolist()),None)
    pwo.put_markdown(""" # Minimum Health to save princess """)
    pwo.put_text(check_ans(matrix))
    pwo.put_buttons(['Home Page'], onclick = [home_page])
    



def default_f():
    pwo.clear()
    arr = input_group("Insert matrix infomation",[
    input('Row count', name='m'),
    input('Column count', name='n'),])
    matrix=[]
    for i in range(int(arr['m'])):          # A for loop for row entries
      a=[]
      for j in range(int(arr['n'])):      # A for loop for column entries
         a.append(random.randint(-1000, 1000))
      matrix.append(a)
    pwo.put_markdown(""" # Dungeon Matrix genrated by Dungeon Master: """)
    pwo.put_table((display(matrix).tolist()),None)
    pwo.put_markdown(""" # Minimum Health to save princess """)
    pwo.put_text(check_ans(matrix))
    pwo.put_buttons(['Home Page'], onclick = [home_page])
   
