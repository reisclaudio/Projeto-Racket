import sys
import os

print("Apagando testes")
os.system("rm script.py")
os.system("rm -rf casosDeTeste/*.geo")
os.system("rm casosDeTeste/q1-testes/*.qry")
os.system("rm casosDeTeste/q2-testes/*.qry")
os.system("rm casosDeTeste/q3-testes/*.qry")
