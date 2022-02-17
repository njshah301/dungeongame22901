import random
import pywebio.output as pwo
from pywebio.input import *
from dg_main import *
import pywebio.output as pwo
from pywebio.input import input
import numpy as np


def home_page():
   
  # import front
    import dg_front
    import pywebio.output as pwo
    from pywebio.input import input  
    pwo.clear()
    pwo.put_html('''<!DOCTYPE html>
<html>
<head>
<style>
body {
  background-image: url('https://images.unsplash.com/photo-1618005182384-a83a8bd57fbe?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1528&q=80');
}
</style>
</head>
<body>
</body>
</html>
''' )
    pwo.set_scope('List')
    pwo.put_markdown(""" # Dungeon Game""")
    pwo.put_markdown(""" # Become Dungeon Master """)
    pwo.put_buttons(['Become Dungeon Master'], onclick = [dg_front.user_f])
    pwo.put_markdown(""" # Default Dungeon Master """)
    pwo.put_buttons(['Default Dungeon Master'], onclick = [dg_front.default_f])
   
   
    while(True):
        pass
    
if __name__ == '__main__':
    import argparse
    from pywebio.platform.tornado_http import start_server as start_http_server
    from pywebio import start_server as start_ws_server

    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--port", type=int, default=8080)
    parser.add_argument("--http", action="store_true", default=False, help='Whether to enable http protocol for communicates')
    args = parser.parse_args()
    home_page()
